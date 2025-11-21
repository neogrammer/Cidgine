#include <SFML/Graphics.hpp>

#ifndef DRAWABLE_HPP__
#define DRAWABLE_HPP__

class Drawable
{
public:
	virtual void render(sf::RenderWindow& window) = 0;
};

#endif
