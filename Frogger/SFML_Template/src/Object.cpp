#include "Object.h"
#include <iostream>
using namespace std;


//constructor for the class
//a true 'givendirection' indicates the object is moving right whereas a false 'givendirection' indicates the object is moving left
//the char 'type' is used to determine what texture to provide to the object
Object::Object(bool givendirection, float givenlength, float givenspeed, int givenypos, int givenxpos, char type)
{
	//retrieves all of the textures from the assets folder
	carTexture.loadFromFile("Assets/Car sprite.png");
	truckTexture.loadFromFile("Assets/Truck sprite.png");
	logTexture.loadFromFile("Assets/Log sprite.png");
	turtleTexture.loadFromFile("Assets/Turtle sprite.png");
	padTexture.loadFromFile("Assets/Lilypad sprite.png");
	//converts the parameters into local variables used later in the class
	direction = givendirection;
	speed = givenspeed;
	ypos = givenypos;
	xpos = givenxpos;
	//sets the size and origin for the object
	objectbody.setSize(sf::Vector2f(givenlength, 20.f));
	objectbody.setOrigin(objectbody.getSize().x / 2.0f, objectbody.getSize().y / 2.0f);
	//checks what character is given by the parameter 'type' in order to assign it the correct texture
	if (type == 'C') {
		//if 'C' (car) is given then it checks the length of the car in order to determine whether to give it the truck or car texture
		if (givenlength == 40) {
			objectbody.setTexture(&carTexture);
		}
		else {
			objectbody.setTexture(&truckTexture);
		}
		//checks the direction of the vehicle and if it is moving right it rotates the object by 180 degrees
		if (givendirection == true) {
			objectbody.setRotation(180);
		}
	}
	else if (type == 'T') {
		objectbody.setTexture(&turtleTexture);
	}
	else if (type == 'L') {
		objectbody.setTexture(&logTexture);
	}
	else if (type == 'P') {
		objectbody.setTexture(&padTexture);
	}
	//sets the position of the object using the given parameters
	objectbody.setPosition(xpos, ypos);


}


Object::~Object()
{
}

//a function that allows the object to move using the given speed and direction
void Object::move(){
	//checks the direction
	if (direction == true) {
		//moves the object to the right using the given speed
		objectbody.move(speed, 0);
		//checks to see if the object has moved off the right side of the screen and if it has it changes the position to the left of the screen (essentially looping it)
		if (objectbody.getPosition().x > 700) {
			objectbody.setPosition(-100, ypos);
		}
	}
	else if (direction == false) {
		//move the object left using the given speed
		objectbody.move(-speed, 0);
		//checks to see if the object has moved off the left hand side of the screen and if it has it changes the position to the right
		if (objectbody.getPosition().x < -100) {
			objectbody.setPosition(700, ypos);
		}
	}
}

//used to return the object body of the object (for drawing purposes)
sf::RectangleShape Object::getObjectBody() {
	return objectbody;
}

//used to return the bounds of the object in order to determin collision
sf::FloatRect Object::getobjectBb() {
	return objectbody.getGlobalBounds();
}

//returns the given direction of the object
bool Object::returndirection() {
	return(direction);
}

//returns the given speed of the object
float Object::returnspeed() {
	return(speed);
}

