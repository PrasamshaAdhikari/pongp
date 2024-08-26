#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace sf;
using namespace std;

Texture numTexture[10];
Sprite numSprite[10];
string path = "";
void createNumberSprites(RenderWindow& window)
{
	for (int i = 0; i < 10;i++)
	{
		path = "C:\\Users\\Mücahit\\Desktop\\pong\\numbers\\" + to_string(i) + ".png";
		if (!numTexture[i].loadFromFile(path))
		{
			//throw error
		}
		numSprite[i].setTexture(numTexture[i]);
		numSprite[i].setScale(0.1f, 0.1f);
	}
}

void updateScore(int puan0, int puan1,RenderWindow& window)
{
	//puan0
	for (int i = 0;i < 10;i++)
	{
		if (puan0 == i)
		{
			numSprite[i].setColor(Color(255, 255, 255, 255));
			numSprite[i].setPosition((560), (120));
			window.draw(numSprite[i]);
		}

		if (puan1 == i)
		{
			numSprite[i].setColor(Color(255, 255, 255, 255));
			numSprite[i].setPosition((675), (120));
			window.draw(numSprite[i]);
		}
		else
			numSprite[i].setColor(Color(255, 255, 255, 0));
	}
}

void whoStartsTheGame(Paddle& stick0, Paddle& stick1,Ball& ball)
{
	if (stick0.score > stick1.score)
	{
		ball.speed = Vector2f(-1.0f, 0);
	}
	else if (stick0.score < stick1.score)
	{
		ball.speed = Vector2f(1.0f, 0);
	}
	else
	{
		ball.speed.x = 1;
	}
}