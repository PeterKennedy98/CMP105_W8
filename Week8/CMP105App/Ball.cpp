#pragma once
#include "Ball.h"
#include "Level.h"



Ball::Ball()
{
	texture.loadFromFile("gfx/Beach_Ball.png");

	setTexture(&texture);
	setSize(sf::Vector2f(100.f, 100.f));
	setCollisionBox(50, 50, 100, 100);
}

Ball::~Ball()
{

}

void Ball::Update(float dt)
{
	move(velocity * dt);

	if (getPosition().x <= 0)
	{
		velocity = -velocity;

	}
	else if (getPosition().x >= window->getSize().x)
	{
		velocity = -velocity;
	}

}

void Ball::collisionResponse(GameObject * collider)
{
	velocity.x = -velocity.x;
}