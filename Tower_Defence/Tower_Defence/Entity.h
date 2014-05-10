

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML\Graphics.hpp>

class Entity
{
private:
	int posX;
	int posY;
public:
	Entity();
	Entity(int positionX, int positionY);
	~Entity();
	virtual void update(float deltaTime);
	virtual void draw(sf::RenderWindow* window);

};


#endif