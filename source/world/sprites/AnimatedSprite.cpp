#include "AnimatedSprite.hpp"

AnimatedSprite::AnimatedSprite()
	: CidSprite{}
	, animNum{}
	, frameNum{}
	, frameTime{}
	, animFPS{ 10.f }
{
}

AnimatedSprite::AnimatedSprite(Assets::Textures texId_, sf::Vector2f pos_, sf::Vector2f size_, sf::IntRect texRect_, sf::Vector2f texOff_, int drawOrder_)
	: CidSprite{texId_, pos_, size_, texRect_, texOff_, drawOrder_}
	, animNum{}
	, frameNum{}
	, frameTime{}
	, animFPS{ 10.f }
{
}

AnimatedSprite::~AnimatedSprite()
{
}

void AnimatedSprite::initialize(AnimData& myData_, int startingAnimNum_)
{
	animData = myData_;
	ChangeAnim(startingAnimNum_);
}

void AnimatedSprite::updateAnim(float deltaTime_)
{
	frameTime += deltaTime_;


	if (frameTime > (1 / animFPS))
	{
		frameNum += (int)(frameTime * animFPS);

		if (frameNum >= animData.frameInfo[animNum].numFrames)
		{
			frameNum = frameNum % animData.frameInfo[animNum].numFrames;
		}

		int imageNum = animData.frameInfo[animNum].startFrame + frameNum;
		currRect = animData.frames[imageNum];

		frameTime = fmod(frameTime, 1 / animFPS);
	}
}

void AnimatedSprite::ChangeAnim(int num_)
{
	animNum = num_;
	frameNum = 0;
	frameTime = 0.f;
	int imageNum = animData.frameInfo[animNum].startFrame;
	currRect = animData.frames[imageNum];
}
