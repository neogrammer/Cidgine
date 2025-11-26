#include "Stage.hpp"

Stage::Stage(sf::RenderWindow& wnd_, int numHScreens_, int numVScreens_, std::list<Assets::Textures> bgImages_)
	: numScreens{}
	, numHScreens{ numHScreens_ }
	, numVScreens{ numVScreens_ }
	, screenWidth{ (float)glbl::ScrW }
	, screenHeight{ (float)glbl::ScrH }
	, totalWidth{ static_cast<int>(glbl::ScrW * static_cast<float>(numHScreens_))}
	, totalHeight{ static_cast<int>(glbl::ScrH * static_cast<float>(numVScreens_)) }
	, bgSpriteList{}
	, stageView{wnd_.getDefaultView()}
{
	auto imgIt = bgImages_.begin();
	for (int v = 0; v < numVScreens; ++v) {
		for (int h = 0; h < numHScreens; ++h) {
			if (imgIt != bgImages_.end()) {
				sf::Vector2f pos{ h * screenWidth, v * screenHeight };
				sf::Vector2f size{ screenWidth, screenHeight };
				sf::IntRect texRect{ { 0, 0},{ static_cast<int>(size.x), static_cast<int>(size.y) } };
				sf::Vector2f texOff{ 0.f, 0.f };
				CidSprite bgSprite{ *imgIt, pos, size, texRect, texOff, -100 };
				bgSpriteList.push_back(bgSprite);
				++imgIt;
			}
		}
	}
	numScreens = numHScreens * numVScreens;
}

Stage::~Stage()
{
}

std::vector<CidSprite*> Stage::getOnScreenBG(sf::Vector2f topLeft_, sf::Vector2f bottomRight_)
{
	std::vector<CidSprite*> onScreenBGs{};
	for (CidSprite& bgSprite : bgSpriteList) {
		sf::Vector2f bgPos = bgSprite.getPosition();
		sf::Vector2f bgSize = bgSprite.getSize();
		if (!(bgPos.x + bgSize.x < topLeft_.x || bgPos.x > bottomRight_.x ||
			bgPos.y + bgSize.y < topLeft_.y || bgPos.y > bottomRight_.y)) {
			onScreenBGs.push_back(&bgSprite);
		}
	}

	return onScreenBGs;
}

void Stage::renderBG(sf::RenderWindow& wnd_, std::vector<CidSprite*>& bgs)
{
	for (CidSprite* bgSprite : bgs) {
		bgSprite->draw(wnd_);
	}
}

void Stage::updateView(sf::RenderWindow& wnd_, sf::Vector2f centerPos_)
{
	stageView.setCenter(centerPos_);
	wnd_.setView(stageView);
}
