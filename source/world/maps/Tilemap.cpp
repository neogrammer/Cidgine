#include "Tilemap.hpp"

#include <fstream>
void Tilemap::loadMap(const std::string& filename_, Assets::Textures textureId_)
{


	tiles.clear();
	textureId = textureId_;

	auto tw = glbl::TileW;
	auto th = glbl::TileH;

	std::ifstream file{ filename_ };

	if (file.is_open())
	{
		file >> mapWidth;
		file >> mapHeight;
		
		tiles.resize(mapWidth * mapHeight);
		for (int y = 0; y < mapHeight; ++y) {
			for (int x = 0; x < mapWidth; ++x) {
				int tileIndex{ -1 };
				file >> tileIndex;
				tiles[x + y * mapWidth] = tileIndex;
			}
		}
		file.close();
	}


}

void Tilemap::drawMap(sf::RenderWindow& wnd_, sf::Vector2f centerView_)
{
	float topLeftX = centerView_.x - (glbl::ScrW / 2.f);
	float topLeftY = centerView_.y - (glbl::ScrH / 2.f);
	float bottomRightX = centerView_.x + (glbl::ScrW / 2.f);
	float bottomRightY = centerView_.y + (glbl::ScrH / 2.f);

	int startX = static_cast<int>(topLeftX) / glbl::TileW;
	int startY = static_cast<int>(topLeftY) / glbl::TileH;
	int endX = static_cast<int>(bottomRightX) / glbl::TileW + 1;
	int endY = static_cast<int>(bottomRightY) / glbl::TileH + 1;
	startX = std::max(0, startX);
	startY = std::max(0, startY);
	endX = std::min(mapWidth, endX);
	endY = std::min(mapHeight, endY);
	sf::Texture& tileset = Assets::textures.get(static_cast<int>(textureId));
	for (int y = startY; y < endY; ++y) {
		for (int x = startX; x < endX; ++x) {
			int tileIndex = tiles[x + y * mapWidth] - 9000;
			if (tileIndex >= 0) {
				int tu = tileIndex % (tileset.getSize().x / glbl::TileW);
				int tv = tileIndex / (tileset.getSize().x / glbl::TileW);
				sf::Sprite sprite{ tileset };
				sprite.setTextureRect(sf::IntRect{ {tu * glbl::TileW, tv * glbl::TileH},{ glbl::TileW, glbl::TileH } });
				sprite.setPosition({ static_cast<float>(x * glbl::TileW), static_cast<float>(y * glbl::TileH) });
				wnd_.draw(sprite);
			}
		}
	}
}
