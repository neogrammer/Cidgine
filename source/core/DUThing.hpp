#include "Thing.hpp"
#include "Drawable.hpp"
#include "Updateable.hpp"
#ifndef DUTHING_HPP__
#define DUTHING_HPP__

class DUThing : public Thing, public Drawable, public Updateable
{
public:
	void render(sf::RenderWindow& window) override;
	void update(float dt_) override;
};

#endif