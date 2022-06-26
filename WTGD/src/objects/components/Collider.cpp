#include "Collider.h"

WTGD::Collider::Collider(sf::RectangleShape* body, bool enabled) : Component("Collider")
{
	collision_enabled = enabled;

	this->body = body;
	body->setSize(body->getSize());
	body->setOrigin(body->getSize() / 2.0f);
	body->setPosition(body->getPosition());
	body->setScale(body->getScale());
	enable_tick();
}

bool WTGD::Collider::check_collision(std::vector<Collider*> others, float push)
{
	for (Collider* other : others)
	{
		if (this != other)
		{
			if (body->getGlobalBounds().intersects(other->body->getGlobalBounds()))
			{
				printf("Colliding");
				return true;
			}
			else 
			{
				return false;
			}
		}
		return false;
	}
}
