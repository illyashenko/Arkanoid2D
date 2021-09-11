#pragma once
#include <SFML/Graphics.hpp>
#include "constants.h"

__interface IEntity
{
	void draw(sf::RenderWindow& window);
	void update(float time);
};
