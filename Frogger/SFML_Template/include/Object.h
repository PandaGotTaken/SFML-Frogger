#pragma once
#include <SFML/Graphics.hpp>


class Object
{
private:
	sf::RectangleShape objectbody;
	bool direction;
	int length;
	float speed;
	int ypos;
	int xpos;
	sf::Texture carTexture;
	sf::Texture truckTexture;
	sf::Texture turtleTexture;
	sf::Texture logTexture;
	sf::Texture padTexture;

public:
	Object(bool givendirection, float givenlength, float givenspeed, int givenypos, int givenxpos, char type);
	~Object();
	void move();
	sf::RectangleShape getObjectBody();
	sf::FloatRect getobjectBb();
	bool returndirection();
	float returnspeed();
};

