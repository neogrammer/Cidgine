#include "Isomap.hpp"

#include <fstream>
void Isomap::loadMap(const std::string& filename_, Assets::Textures textureId_)
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

void Isomap::drawMap(sf::RenderWindow& wnd_, sf::Vector2f centerView_)
{
	float topLeftX = centerView_.x - (glbl::ScrW / 2.f);
	float topLeftY = centerView_.y - (glbl::ScrH / 2.f);
	float bottomRightX = centerView_.x + (glbl::ScrW / 2.f);
	float bottomRightY = centerView_.y + (glbl::ScrH / 2.f);

	int startX = std::max(0, static_cast<int>(topLeftX) / glbl::TileW - (glbl::WorldOffsetX * glbl::CellWidth));
	int startY = std::max(0, static_cast<int>(topLeftY) / glbl::TileH - (glbl::WorldOffsetY * glbl::CellHeight));
	
	int endX = std::min(mapWidth - 1, static_cast<int>(bottomRightX) / glbl::TileW + 1 + (glbl::WorldOffsetX * glbl::CellWidth));
	int endY = std::min(mapHeight -1 , static_cast<int>(bottomRightY) / glbl::TileH + 1 + (glbl::WorldOffsetY * glbl::CellHeight));
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
				float isox = (float)x;
				float isoy = (float)y;
					
				sf::Sprite sprite{ tileset };
				sprite.setTextureRect(sf::IntRect{ {tu * glbl::TileW, tv * glbl::TileH},{ glbl::TileW, glbl::TileH } });
				sprite.setPosition({ (float)glbl::CellWidth * ((isox - isoy) / (float)glbl::CellWidth) * ((float)glbl::CellWidth / 2.f) + (glbl::WorldOffsetX * glbl::CellWidth), (float)glbl::CellHeight * ((isox + isoy) / (float)glbl::CellHeight) * ((float)glbl::CellHeight / 2.f) + (glbl::WorldOffsetY * glbl::CellHeight) });
				wnd_.draw(sprite);
			}
		}
	}
}
