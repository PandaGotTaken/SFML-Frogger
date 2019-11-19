#pragma once
#include <SFML/Graphics.hpp>

class Frog
{
private:
	sf::RectangleShape frogbody;
	int frogspeed;
	int walloffset;
	sf::Texture frogTexture;

public:

	Frog();
	~Frog();
	void moveUp();
	void moveLeft();
	void moveDown();
	void moveRight();
	void moveUpLeft();
	void moveUpRight();
	void moveDownLeft();
	void moveDownRight();
	void reset();
	void push(bool direction, float objectspeed);
	sf::RectangleShape getFrogBody();
	sf::FloatRect getfrogBb();
	float returnypos();
	float returnxpos();
};

