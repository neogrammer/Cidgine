#include "CidSprite.hpp"

CidSprite::CidSprite()
{
}

CidSprite::CidSprite(Assets::Textures texId_, sf::Vector2f pos_, sf::Vector2f size_, sf::IntRect texRect_, sf::Vector2f texOff_, int drawOrder_)
	: textureId{ texId_ }
	, position{ pos_ }
	, size{ size_ }
	, textureRect{ texRect_ }
	, texOff{ texOff_ }
	, drawOrder{ drawOrder_ }
{
	ready = true;
}

CidSprite::~CidSprite()
{
}

void CidSprite::draw(sf::RenderWindow& wnd_)
{
	if (ready) {
		sf::Sprite sprite{ Assets::textures.get((int)textureId) };
		sprite.setPosition(position - texOff);
		sprite.setTextureRect(textureRect);
		wnd_.draw(sprite);
	}
}
