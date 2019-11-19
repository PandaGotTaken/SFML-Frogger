#include <SFML/Graphics.hpp>
#include <Frog.h>
#include <Object.h>
#include <iostream>

using namespace std;

//Definition of variables used later in code
bool upPressed = false;
bool downPressed = false;
bool rightPressed = false;
bool leftPressed = false;
bool turtlecheck = false;
bool logcheck = false;
int score = 0;
Frog player;
int lives = 3;
int recordDistance = 400 - 10;
int padsreached = 0;

//start of main function
int main() {

	//create a window with the constructor 
	sf::RenderWindow window(sf::VideoMode(600, 400), "SFMLTemplate"); 

	//creates the font object for the font used (referenced in doc)
	sf::Font froggerfont;
	froggerfont.loadFromFile("Assets/frogger_.ttf");

	//Creates the text object that displays the player's current score
	sf::Text scoretext;
	scoretext.setFont(froggerfont);
	scoretext.setCharacterSize(18);
	scoretext.setPosition(0, 0);
	scoretext.setFillColor(sf::Color::Black);
	scoretext.setStyle(sf::Text::Bold);
	
	//Creates the text object that will display the player's current lives
	sf::Text livestext;
	livestext.setFont(froggerfont);
	livestext.setCharacterSize(18);
	livestext.setPosition(500, 0);
	livestext.setFillColor(sf::Color::Black);
	livestext.setStyle(sf::Text::Bold);

	//Creates the game over title that will display once the player has lost all of their lives
	sf::Text gameovertext;
	gameovertext.setFont(froggerfont);
	gameovertext.setCharacterSize(48);
	gameovertext.setPosition(180, 120);
	gameovertext.setFillColor(sf::Color::White);
	gameovertext.setStyle(sf::Text::Bold);
	gameovertext.setString("Game Over!");

	//creates the text object used to display the player's final score when the game ends
	sf::Text finalscoretext;
	finalscoretext.setFont(froggerfont);
	finalscoretext.setCharacterSize(36);
	finalscoretext.setPosition(200, 200);
	finalscoretext.setFillColor(sf::Color::White);
	finalscoretext.setStyle(sf::Text::Bold);

	//string variables needed to display variables
	string livesstring;
	string scorestring;

	//creation of rectangle object that serves as lake
	sf::RectangleShape lake;
	lake.setSize(sf::Vector2f(600.f, 180.f));
	lake.setOrigin(lake.getSize().x / 2.0f, lake.getSize().y / 2.0f);
	lake.setFillColor(sf::Color(25,25,112));
	lake.setPosition(300, 90);

	//creation of rectangle object to serve as the pavement for the player
	sf::RectangleShape pavement;
	pavement.setSize(sf::Vector2f(600.f, 220.f));
	pavement.setOrigin(pavement.getSize().x / 2.0f, pavement.getSize().y / 2.0f);
	pavement.setFillColor(sf::Color(132,132,130));
	pavement.setPosition(300, 290);

	//creation of the road rectangle which is where the cars drive
	sf::RectangleShape road;
	road.setSize(sf::Vector2f(600.f, 180.f));
	road.setOrigin(road.getSize().x / 2.0f, road.getSize().y / 2.0f);
	road.setFillColor(sf::Color(50, 50, 50));
	road.setPosition(300, 290);

	//creation of grass bank that is shown at the very top of the screen (purely visual)
	sf::RectangleShape bank;
	bank.setSize(sf::Vector2f(600.f, 20.f));
	bank.setOrigin(bank.getSize().x / 2.0f, bank.getSize().y / 2.0f);
	bank.setFillColor(sf::Color(86, 176, 0));
	bank.setPosition(300, 10);


	// decleration of all cars as objects and insertion of them into the vector 'vehicles'
	vector<Object> vehicles;
	Object car1a(true, 60, 0.1, 270, 0, 'C');
	Object car1b(true, 60, 0.1, 270, 400, 'C');
	Object car2a(false, 40, 0.15, 290, 600, 'C');
	Object car2b(false, 40, 0.15, 290, 400, 'C');
	Object car2c(false, 40, 0.15, 290, 200, 'C');
	Object car3a(true, 40, 0.18, 310, 0, 'C');
	Object car3b(true, 40, 0.18, 310, 400, 'C');
	Object car4a(false, 40, 0.12, 330, 600, 'C');
	Object car4b(false, 40, 0.12, 330, 400, 'C');
	Object car4c(false, 40, 0.12, 330, 200, 'C');
	Object car4d(false, 40, 0.12, 330, 0, 'C');
	Object car5a(false, 40, 0.15, 350, 600, 'C');
	Object car5b(false, 40, 0.15, 350, 200, 'C');
	Object car6a(true, 40, 0.2, 250, 600, 'C');
	Object car6b(true, 40, 0.2, 250, 400, 'C');
	Object car6c(true, 40, 0.2, 250, 200, 'C');
	Object car7a(false, 60, 0.14, 230, 0, 'C');
	Object car7b(false, 60, 0.14, 230, 200, 'C');
	Object car7c(false, 60, 0.14, 230, 400, 'C');
	vehicles.push_back(car1a);
	vehicles.push_back(car1b);
	vehicles.push_back(car2a);
	vehicles.push_back(car2b);
	vehicles.push_back(car2c);
	vehicles.push_back(car3a);
	vehicles.push_back(car3b);
	vehicles.push_back(car4a);
	vehicles.push_back(car4b);
	vehicles.push_back(car4c);
	vehicles.push_back(car4d);
	vehicles.push_back(car5a);
	vehicles.push_back(car5b);
	vehicles.push_back(car6a);
	vehicles.push_back(car6b);
	vehicles.push_back(car6c);
	vehicles.push_back(car7a);
	vehicles.push_back(car7b);
	vehicles.push_back(car7c);

	// decleration of all turtles and insertion of them into 'turtles'
	vector<Object> turtles;
	Object turtle1a(false, 100, 0.04, 170, 0, 'T');
	Object turtle1b(false, 100, 0.04, 170, 200, 'T');
	Object turtle1c(false, 100, 0.04, 170, 400, 'T');
	Object turtle1d(false, 100, 0.04, 170, 600, 'T');
	Object turtle2a(false, 100, 0.055, 110, 0, 'T');
	Object turtle2b(false, 100, 0.055, 110, 200, 'T');
	Object turtle2c(false, 100, 0.055, 110, 400, 'T');
	Object turtle2d(false, 100, 0.055, 110, 600, 'T');
	Object turtle3a(false, 100, 0.065, 70, 0, 'T');
	Object turtle3b(false, 100, 0.065, 70, 250, 'T');
	Object turtle3c(false, 100, 0.065, 70, 500, 'T');
	turtles.push_back(turtle1a);
	turtles.push_back(turtle1b);
	turtles.push_back(turtle1c);
	turtles.push_back(turtle1d);
	turtles.push_back(turtle2a);
	turtles.push_back(turtle2b);
	turtles.push_back(turtle2c);
	turtles.push_back(turtle2d);
	turtles.push_back(turtle3a);
	turtles.push_back(turtle3b);
	turtles.push_back(turtle3c);

	// decleration of all logs and insertion of them into 'logs'
	vector<Object> logs;
	Object log1a(true, 100, 0.030, 150, 600, 'L');
	Object log1b(true, 100, 0.030, 150, 350, 'L');
	Object log1c(true, 100, 0.030, 150, 100, 'L');
	Object log2a(true, 150, 0.055, 130, 600, 'L');
	Object log2b(true, 150, 0.055, 130, 200, 'L');
	Object log3a(true, 80, 0.030, 90, 600, 'L');
	Object log3b(true, 80, 0.030, 90, 400, 'L');
	Object log3c(true, 80, 0.030, 90, 200, 'L');
	Object log3d(true, 80, 0.030, 90, 0, 'L');
	Object log4a(true, 100, 0.030, 50, 600, 'L');
	Object log4b(true, 100, 0.030, 50, 350, 'L');
	Object log4c(true, 100, 0.030, 50, 100, 'L');
	logs.push_back(log1a);
	logs.push_back(log1b);
	logs.push_back(log1c);
	logs.push_back(log2a);
	logs.push_back(log2b);
	logs.push_back(log3a);
	logs.push_back(log3b);
	logs.push_back(log3c);
	logs.push_back(log3d);
	logs.push_back(log4a);
	logs.push_back(log4b);
	logs.push_back(log4c);

	//declaration of lilypads where the player finishes and insertion of them into 'pads'
	vector<Object> pads;
	bool padcheck[5] = {false, false, false, false, false};
	Object lilypad1(true, 20, 0, 30, 100, 'P');
	Object lilypad2(true, 20, 0, 30, 200, 'P');
	Object lilypad3(true, 20, 0, 30, 300, 'P');
	Object lilypad4(true, 20, 0, 30, 400, 'P');
	Object lilypad5(true, 20, 0, 30, 500, 'P');
	pads.push_back(lilypad1);
	pads.push_back(lilypad2);
	pads.push_back(lilypad3);
	pads.push_back(lilypad4);
	pads.push_back(lilypad5);

	// run until the use closes the window 
	while (window.isOpen()) {

		// check all the user events 
		sf::Event event; 

		while (window.pollEvent(event))
		{
			// user has pressed the close button 

			if (event.type == sf::Event::Closed) {
				window.close();

			}
			//checks to see if the player has any lives left (if they do not it does not allow them to move)
			if (lives > 0) {
				//detects when the player presses one of the arrow keys
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Up) upPressed = true;
					if (event.key.code == sf::Keyboard::Left) leftPressed = true;
					if (event.key.code == sf::Keyboard::Down) downPressed = true;
					if (event.key.code == sf::Keyboard::Right) rightPressed = true;
				}
				//detects when the player releases one of the arrow keys
				if (event.type == sf::Event::KeyReleased) {
					if (event.key.code == sf::Keyboard::Up) upPressed = false;
					if (event.key.code == sf::Keyboard::Left) leftPressed = false;
					if (event.key.code == sf::Keyboard::Down) downPressed = false;
					if (event.key.code == sf::Keyboard::Right) rightPressed = false;
				}

				if (event.type == sf::Event::KeyPressed) {

					//moves the player accordingly once the corresponding arrow keys are pressed
					if (upPressed == true and downPressed == false) {
						if (leftPressed == true and rightPressed == false) {
							player.moveUpLeft();
						}
						else if (leftPressed == false and rightPressed == true) {
							player.moveUpRight();
						}
						else {
							player.moveUp();
						}
						//if the player moves up and breaks their record for distance travelled so far they attain 20 points
						if (player.returnypos() < recordDistance) {
							recordDistance = recordDistance - 20;
							score = score + 20;
							cout << score << endl;
						}
					}
					else if (upPressed == false and downPressed == true) {
						if (leftPressed == true and rightPressed == false) {
							player.moveDownLeft();
						}
						else if (leftPressed == false and rightPressed == true) {
							player.moveDownRight();
						}
						else {
							player.moveDown();
						}
					}
					else {
						if (leftPressed == true and rightPressed == false) {
							player.moveLeft();
						}
						else if (leftPressed == false and rightPressed == true) {
							player.moveRight();
						}
					}
				}
			}
       // user events ended 


		}
		
		//clears the window of previous display
		window.clear(sf::Color::White);

		//draws in the previously defined rectangle shapes (background of the screen)
		window.draw(pavement);
		window.draw(lake); 
		window.draw(road);
		window.draw(bank);


		//checks every vehicle
		for (int i = 0; i < vehicles.size(); i++) {
			//moves every vehicle and then draws its new position on the screen
			vehicles.at(i).move();
			window.draw(vehicles.at(i).getObjectBody());
			//checks collision with the player
			if (player.getfrogBb().intersects(vehicles.at(i).getobjectBb())) {
				// if collision is detected the player's position is reset and they lose a life (record distance is also reset)
				player.reset();
				recordDistance = 390;
				lives = lives - 1;
			}
		}

		//resets variable used to detect whether the player is on a turtle
		turtlecheck = false;
		//checks through every turtle in 'turtles'
		for (int i = 0; i < turtles.size(); i++) {
			//moves every turtle and then draws their new position on screen.
			turtles.at(i).move();
			window.draw(turtles.at(i).getObjectBody());
			//checks whether the player is on a turtle
			if (player.getfrogBb().intersects(turtles.at(i).getobjectBb())) {
				//if the players is on a turtle then the turtlecheck variable is changed and the player is moved with the turtle
				turtlecheck = true;
				player.push(turtles.at(i).returndirection(), turtles.at(i).returnspeed());
				//checks to see whether the player is moved off the side of the map
				if (player.returnxpos() <= 0 or player.returnxpos() >= 600) {
					//if the player is moved off the side of the map then they lose a life and get reset (identical to when they are hit by a car)
					player.reset();
					recordDistance = 390;
					lives = lives - 1;
					if (lives == 0) {
						cout << "Game Over" << endl;
					}
					else {
						cout << "lives: " << lives << endl;
					}
				}
			}
			
		}

		//resets variable used to detect whether the player is on a log
		logcheck = false;
		//checks through every log in 'logs'
		for (int i = 0; i < logs.size(); i++) {
			//moves every log and then draws their new position on screen.
			logs.at(i).move();
			window.draw(logs.at(i).getObjectBody());
			//checks whether the player is currently on a log
			if (player.getfrogBb().intersects(logs.at(i).getobjectBb())) {
				//if the player is on a log it changes logcheck and then moves the player in accordance to the log
				logcheck = true;
				player.push(logs.at(i).returndirection(), logs.at(i).returnspeed());
				//checks to see if the player is moved off the side of the map
				if (player.returnxpos() <= 0 or player.returnxpos() >= 600) {
					//if the player is moved off the side of the map then they lose a life and get reset (identical to when they are hit by a car)
					player.reset();
					recordDistance = 390;
					lives = lives - 1;
					if (lives == 0) {
						cout << "Game Over" << endl;
					}
					else {
						cout << "lives: " << lives << endl;
					}
				}
			}

		}

		//checks through every lilypad in 'pads'
		for (int i = 0; i < pads.size(); i++) {
			//checks to see if the lilypad has already been stepped on
			if (padcheck[i] == false) {
				//if the lilypad has not been reached yet it is drawn on the screen
				window.draw(pads.at(i).getObjectBody());
			}
			//checks to see if the player intercepts with a available lilypad
			if (player.getfrogBb().intersects(pads.at(i).getobjectBb()) and padcheck[i] == false) {
				//if the player gets to a available lilypad then the player is reset and their score is increased by 100
				player.reset();
				recordDistance = 390;
				score = score + 100;
				//the variable within the list used to determine whether the lilypad has been stepped on is changed and the 'padsreached' variable is incremented
				padcheck[i] = true;
				padsreached = padsreached + 1;
				//checks to see if the player has reached all of the available lilypads
				if (padsreached >= 5) {
					//if the player has reached all of the lilypads then it makes them all available again and sets 'padsreached' to 0 (in order to allow the player to continue the game)
					for (int j = 0; j < pads.size(); j++) {
						padcheck[j] = false;
					}
					padsreached = 0;
				}
			}
		}

		//checks to see if the player is neither on a log or turtle
		if (turtlecheck == false && logcheck == false) {
			//then checks to see if the player is currently in the localbounds of the lake
			if (player.getfrogBb().intersects(lake.getLocalBounds())) {
				//if the player on the lake without being on a turtle or log (or lilypad) then they lose a life and get reset (identical to when they are hit by a car)
				player.reset();
				recordDistance = 390;
				lives = lives - 1;
				if (lives == 0) {
					cout << "Game Over" << endl;
				}
				else {
					cout << "lives: " << lives << endl;
				}
			}
		}

		//checks to see if the player has any available lives left
		if (lives > 0) {
			//draws the current position of the player
			window.draw(player.getFrogBody());
			//adds the current lives onto 'livestext' and then draws it to the top right corner of the screen
			livesstring = to_string(lives);
			livestext.setString("Lives: " + livesstring);
			window.draw(livestext);

			//adds the current score onto the 'scoretext' and then draws the text onto the top left corner of the screen
			scorestring = to_string(score);
			scoretext.setString("Score: " + scorestring);
			window.draw(scoretext);
		}
		else {
			//if the player has no lives left it draws the 'gameover' text and also their final score onto the center of the screen
			scorestring = to_string(score);
			finalscoretext.setString("Score: " + scorestring);
			window.draw(finalscoretext);
			window.draw(gameovertext);
			
		}

		//displays the contents of the window onto the screen
		window.display();




	}
	return 0; 
}