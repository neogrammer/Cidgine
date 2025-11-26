#include <resources/Assets.hpp>
#include <vector>
#include <Globals.hpp>
#ifndef ISOMAP_HPP__
#define ISOMAP_HPP__

class Isomap
{
	int mapWidth{};
	int mapHeight{};
	std::vector<int> tiles{};
	Assets::Textures textureId{ Assets::Textures::Invariant };


public:

	void loadMap(const std::string& filename_, Assets::Textures textureId_);

	void drawMap(sf::RenderWindow& wnd_, sf::Vector2f centerView_);
};

#endif // ISOMAP_HPP__