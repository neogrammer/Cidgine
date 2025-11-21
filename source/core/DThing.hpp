#include "Thing.hpp"
#include "Drawable.hpp"

#ifndef DTHING_HPP__
#define DTHING_HPP__

class DThing : public Thing, public Drawable
{
public:
	void render(sf::RenderWindow& window);
};

#endif