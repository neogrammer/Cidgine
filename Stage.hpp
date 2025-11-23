#include <list>
#include "CidSprite.hpp"
#include "Globals.hpp"
#include <vector>
#include <SFML/Graphics/View.hpp>
#ifndef STAGE_HPP__
#define STAGE_HPP__

class Stage 
{
	int numScreens{};
	int numHScreens{};
	int numVScreens{};

	float screenWidth{};
	float screenHeight{};

	int totalWidth{};
	int totalHeight{};

	std::list<CidSprite> bgSpriteList{};

	sf::View stageView{};

public:
	Stage(sf::RenderWindow& wnd_, int numHScreens_, int numVScreens_, std::list<Assets::Textures> bgImages_ );
	~Stage();

	std::vector<CidSprite*> getOnScreenBG(sf::Vector2f topLeft_, sf::Vector2f bottomRight_);
	void renderBG(sf::RenderWindow& wnd_, std::vector<CidSprite*>& bgs);
	void updateView(sf::RenderWindow& wnd_, sf::Vector2f centerPos_);

};

#endif