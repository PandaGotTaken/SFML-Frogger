#include "Frog.h"
#include <iostream>
using namespace std;

//constructor for the frog class
Frog::Frog()
{
	//find the texture within the assets folder and assigns it to the object
	frogTexture.loadFromFile("Assets/Frog sprite.png");
	frogbody.setTexture(&frogTexture);
	//sets the origin, size, position and speed of the object
	frogbody.setOrigin(20 / 2.0f, 20 / 2.0f);
	frogbody.setSize(sf::Vector2f(20, 20));
	frogbody.setPosition(300, 400-(20/2));
	frogspeed = 20;
	//used to offset the wall in order to prevent the player from moving off the map
	walloffset = 25;
	
}


Frog::~Frog()
{
}

//function used to move the player up without allowing them to move off the map (also rotates them to face the direction)
void Frog::moveUp() {
	if (frogbody.getPosition().y >= 0 + walloffset) {
		frogbody.move(0, -frogspeed);
		frogbody.setRotation(0);
	}
}
//function used to move the player left without allowing them to move off the map (also rotates them to face the direction)
void Frog::moveLeft() {
	if (frogbody.getPosition().x >= 0 + walloffset) {
		frogbody.move(-frogspeed, 0);
		frogbody.setRotation(270);
	}
}
//function used to move the player down without allowing them to move off the map (also rotates them to face the direction)
void Frog::moveDown() {
	if (frogbody.getPosition().y <= 400 - walloffset){
		frogbody.move(0, frogspeed);
		frogbody.setRotation(180);
	}
}
//function used to move the player right without allowing them to move off the map (also rotates them to face the direction)
void Frog::moveRight() {
	if (frogbody.getPosition().x <= 600 - walloffset) {
		frogbody.move(frogspeed, 0);
		frogbody.setRotation(90);
	}
}
//function used to move the player up and left without allowing them to move off the map
void Frog::moveUpLeft() {
	if (frogbody.getPosition().y >= 0 + walloffset) {
		if (frogbody.getPosition().x >= 0 + walloffset) {
			frogbody.move(-frogspeed, -frogspeed);
		}
		else {
			frogbody.move(0, -frogspeed);
		}
	}
	else {
		if (frogbody.getPosition().x >= 0 + walloffset) {
			frogbody.move(-frogspeed, 0);
		}
	}
}
//function used to move the player up and right without allowing them to move off the map
void Frog::moveUpRight() {
	if (frogbody.getPosition().y >= 0 + walloffset) {
		if (frogbody.getPosition().x <= 600 - walloffset) {
			frogbody.move(frogspeed, -frogspeed);
		}
		else {
			frogbody.move(0, -frogspeed);
		}
	}
	else {
		if (frogbody.getPosition().x <= 600 - walloffset) {
			frogbody.move(frogspeed, 0);
		}
	}
}
//function used to move the player down and left without allowing them to move off the map
void Frog::moveDownLeft() {
	if (frogbody.getPosition().y <= 400 - walloffset) {
		if (frogbody.getPosition().x >= 0 + walloffset) {
			frogbody.move(-frogspeed, frogspeed);
		}
		else {
			frogbody.move(0, frogspeed);
		}
	}
	else {
		if (frogbody.getPosition().x >= 0 + walloffset) {
			frogbody.move(-frogspeed, 0);
		}
	}
}
//function used to move the player down and right without allowing them to move off the map
void Frog::moveDownRight() {
	if (frogbody.getPosition().y <= 400 - walloffset) {
		if (frogbody.getPosition().x <= 600 - walloffset) {
			frogbody.move(frogspeed, frogspeed);
		}
		else {
			frogbody.move(0, frogspeed);
		}
	}
	else {
		if (frogbody.getPosition().x <= 600 - walloffset) {
			frogbody.move(frogspeed, 0);
		}
	}
}

//function used to reset the position of the frog back to the start
void Frog::reset() {
	frogbody.setPosition(300, 400-(20/2));
}

//used to return the frogs bounds in order to detect collision
sf::FloatRect Frog::getfrogBb() {
	return frogbody.getGlobalBounds();
}

//used to return the frogs body in order to display on screen
sf::RectangleShape Frog::getFrogBody() {
	return frogbody;
}

//used to move the frog in a direction whilst they are on a turtle or frog 
void Frog::push(bool direction, float objectspeed) {
	if (direction == true) {
		frogbody.move(objectspeed, 0);
	}
	else {
		frogbody.move(-objectspeed, 0);
	}
}

//functions to return the y and x position of the frog in order to detect whether they have moved off the map whilst being pushed
float Frog::returnypos() {
	return(frogbody.getPosition().y);
}
float Frog::returnxpos() {
	return(frogbody.getPosition().x);
}

