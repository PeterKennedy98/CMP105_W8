#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	Ball_1.setwindow(window);
	Ball_2.setwindow(window);

	// initialise game objects
	Ball_1.setPosition(100, 200);
	Ball_1.setVelocity(sf::Vector2f(50.f, 0.f));

	Ball_2.setPosition(500, 200);
	Ball_2.setVelocity(sf::Vector2f(-50.f, 0));

	Ball_1_Hitbox.setSize(sf::Vector2f(Ball_1.getCollisionBox().width-1, Ball_1.getCollisionBox().height-1));
	Ball_1_Hitbox.setPosition(sf::Vector2f(Ball_1.getPosition()));
	Ball_1_Hitbox.setOutlineColor(sf::Color::Green);
	Ball_1_Hitbox.setOutlineThickness(1);
	Ball_1_Hitbox.setFillColor(sf::Color::Transparent);

	Ball_2_Hitbox.setSize(sf::Vector2f(Ball_2.getCollisionBox().width-1, Ball_2.getCollisionBox().height-1));
	Ball_2_Hitbox.setPosition(sf::Vector2f(Ball_2.getPosition()));
	Ball_2_Hitbox.setOutlineColor(sf::Color::Magenta);
	Ball_2_Hitbox.setOutlineThickness(1);
	Ball_2_Hitbox.setFillColor(sf::Color::Transparent);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	Ball_1.Update(dt);
	Ball_2.Update(dt);

	if (Collision::checkBoundingBox(&Ball_1, &Ball_2))
	{
		Ball_1.collisionResponse(NULL);
		Ball_2.collisionResponse(NULL);
	}


	Ball_1_Hitbox.setPosition(sf::Vector2f(Ball_1.getPosition()));

	Ball_2_Hitbox.setPosition(sf::Vector2f(Ball_2.getPosition()));

}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(Ball_1);
	window->draw(Ball_2);

	window->draw(Ball_1_Hitbox);
	window->draw(Ball_2_Hitbox);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}