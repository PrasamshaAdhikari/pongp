#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;
using namespace std;

class Ball {
public:
	Sprite sprite;
	Texture texture;
	Vector2f pos,speed;
	float dir;
	// dir = 0: UP-RIGHT
	// dir = 1: RIGHT
	// dir = 2: DOWN-RIGHT
	// dir = 3: DOWN-LEFT
	// dir = 4: LEFT
	// dir = 5: UP-LEFT
	void initBall(string texture_path)
	{
		texture.loadFromFile(texture_path);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}


	void drawBall(RenderWindow& window)
	{
		window.draw(sprite);
	}

	void firstMoveBall()
	{
		dir = 2;
	}

	void moveBall()
	{
		pos.x += speed.x;
		pos.y += speed.y;

		// Collision With Boundaries
		if (pos.y < 0)
		{
			if (speed.x > 0) dir = 2;
			if (speed.x < 0) dir = 3;
			speed.y *= -1;
		}
		if (pos.y > 700)
		{
			if (speed.x > 0) dir = 0;
			if (speed.x < 0) dir = 5;
			speed.y *= -1;
		}

		sprite.setPosition(pos);
	}

};