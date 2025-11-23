#include <SFML/Graphics.hpp>
#include <resources/Assets.hpp>
#ifndef CIDSPRITE_HPP__
#define CIDSPRITE_HPP__

class CidSprite {
		
	Assets::Textures textureId;
	sf::Vector2f position;
	sf::Vector2f size;
	int drawOrder{ 0 };
	sf::IntRect textureRect;
	sf::Vector2f texOff; 

	bool ready{ false };
public:
	

	CidSprite();
	CidSprite(Assets::Textures texId_, sf::Vector2f pos_, sf::Vector2f size_, sf::IntRect texRect_, sf::Vector2f texOff_, int drawOrder_ = 0);
	~CidSprite();
	
	void draw(sf::RenderWindow& wnd_);
	sf::Vector2f getPosition() { return position; }
	sf::Vector2f getSize() { return size; }
};

#endif // CIDSPRITE_HPP__