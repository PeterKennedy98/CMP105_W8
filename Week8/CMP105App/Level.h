#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Ball.h"
#include "Framework/Collision.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	Ball Ball_1;
	Ball Ball_2;

	sf::RectangleShape Ball_1_Hitbox;
	sf::RectangleShape Ball_2_Hitbox;

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;
};