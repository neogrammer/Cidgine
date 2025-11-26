#include "CidSprite.hpp"
#include "AnimData.hpp"
#ifndef ANIMATEDSPRITE_HPP__
#define ANIMATEDSPRITE_HPP__

class AnimatedSprite : public CidSprite
{
public:
	AnimatedSprite();
	AnimatedSprite(Assets::Textures texId_, sf::Vector2f pos_, sf::Vector2f size_, sf::IntRect texRect_, sf::Vector2f texOff_, int drawOrder_ = 0);
	~AnimatedSprite();

	AnimData animData;

	int animNum;

	int frameNum;

	float frameTime;

	float animFPS = 24.f;

	sf::IntRect currRect;

	void initialize(AnimData& myData_, int startingAnimNum_);
	void updateAnim(float deltaTime_);
	void ChangeAnim(int num_);

};
#endif