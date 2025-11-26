#include <resources/Assets.hpp>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "AnimFrameData.hpp"
#ifndef ANIMDATA_HPP__
#define ANIMDATA_HPP__

struct AnimData
{
	std::vector<sf::IntRect> frames;
	std::vector<AnimFrameData> frameInfo;
};

#endif