#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include <iostream>

class Ball : public GameObject
{
public:
	Ball();
	~Ball();

	void Update(float dt);
	virtual void collisionResponse(GameObject* collider);

	void setwindow(sf::RenderWindow* hwnd)
	{ 
		window = hwnd;
	}

	sf::RenderWindow* window;

	sf::Texture texture;
};

