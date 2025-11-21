#include "Thing.hpp"
#include "Updateable.hpp"


#ifndef UTHING_HPP__
#define UTHING_HPP__

class UThing : public Thing, public Updateable
{
public:
	void update(float dt_) override;
};

#endif