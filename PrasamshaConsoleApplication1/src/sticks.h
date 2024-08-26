#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "ball.h"

using namespace sf;
using namespace std;

class Paddle {
public:
	Texture texture;
	Sprite sprite;
	Vector2f pos;
	float dir, speed;
	int score;
	void initPaddles(string texture_path)
	{
		texture.loadFromFile(texture_path);
		sprite.setTexture(texture);
		sprite.setPosition(pos);
	}

	void movePaddles(Ball& ball)
	{
		//Eðer topun hýzý 1.5 f den büyükse paddle hýzý *= 2f;
		if (abs(ball.speed.x) < 1.5f) speed = 1.f;
		else					speed = 2.f;

		if (dir == 0) pos.y -= speed;
		if (dir == 1) pos.y += speed;
		if (dir == 2) pos.y = pos.y;

		// Collision With Boundaries
		if (pos.y < 4) pos.y = 4;
		if (pos.y > 604) pos.y = 604;
		sprite.setPosition(pos);
	}

	void drawPaddles(RenderWindow& window)
	{
		window.draw(sprite);
	}
};
 