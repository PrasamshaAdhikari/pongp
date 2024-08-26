#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>
#include "sticks.h"
#include "ball.h"

using namespace sf;
using namespace std;
void Collision(Ball& ball, Paddle& stick1,Paddle& stick0,Sound& paddle,Sound& score, int& puan0, int& puan1) // ball out of range puan++
{
	//stick[1]
	
	// Ball hit to the middle range
	if ((ball.pos.x  <= stick1.pos.x && ball.pos.x + 21 >= stick1.pos.x) && (ball.pos.y + 11) <= (stick1.pos.y + 66) && (ball.pos.y + 11) >= (stick1.pos.y + 44))
	{
		ball.speed.y = 0;
		ball.speed.x *= -1;
		ball.dir = 4; //left
		paddle.play();
	}
	// Ball hit to the upper range
	else if ((ball.pos.x <= stick1.pos.x && ball.pos.x + 21 >= stick1.pos.x) && (ball.pos.y + 11) < (stick1.pos.y + 44) && (ball.pos.y + 11) > stick1.pos.y)
	{
		//eðer ball: down-right ise ve stick up ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 2 && stick1.dir == 0)
		{
			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		//eðer ball: up-right ise ve stick down ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 0 && stick1.dir == 1)
		{
			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		ball.speed.x *= -1;
		ball.speed.y = -0.65f;
		ball.dir = 5;
		paddle.play();
	}
	// Ball hit to the down range
	else if ((ball.pos.x  <= stick1.pos.x && ball.pos.x + 21 >= stick1.pos.x) && (ball.pos.y + 11) <= (stick1.pos.y + 110) && (ball.pos.y + 11) > (stick1.pos.y + 66))
	{
		//eðer ball: down-right ise ve stick up ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 2 && stick1.dir == 0)
		{
			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		//eðer ball: up-right ise ve stick down ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 0 && stick1.dir == 1)
		{
			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		ball.speed.x *= -1;
		ball.speed.y = 0.65f;
		ball.dir = 3;
		paddle.play();
	}

	//stick[0]
	
	// Ball hit to the middle range
	if ((ball.pos.x  <= stick0.pos.x && ball.pos.x +7 >= stick0.pos.x) && (ball.pos.y + 11) <= (stick0.pos.y + 66) && (ball.pos.y + 11) >= (stick0.pos.y + 44))
	{
		ball.speed.y = 0;
		ball.speed.x *= -1;
		ball.dir = 1;
		paddle.play();
	}
	// Ball hit to the upper range
	else if ((ball.pos.x <= stick0.pos.x && ball.pos.x + 7 >= stick0.pos.x) && (ball.pos.y + 11) < (stick0.pos.y + 44) && (ball.pos.y + 11) > stick0.pos.y)
	{
		//eðer ball: down-left ise ve stick up ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 3 && stick0.dir == 0)
		{
			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		//eðer ball: up-left ise ve stick down ise speed'i 2 ile çarp  SPEED UP....
		if (ball.dir == 5 && stick0.dir == 1)
		{

			ball.speed.x *= 1.4f;
			ball.speed.y *= 1.4f;
		}
		ball.speed.x *= -1;
		ball.speed.y = -0.65f;
		ball.dir = 0;
		paddle.play();
		
	}
	// Ball hit to the down range
	else if ((ball.pos.x <= stick0.pos.x && ball.pos.x + 7 >= stick0.pos.x) && (ball.pos.y + 11) <= (stick0.pos.y + 110) && (ball.pos.y + 11) > (stick0.pos.y + 66))
	{
		ball.speed.x *= -1;
		ball.speed.y = 0.65f;
		ball.dir = 2;
		paddle.play();
		
	}
	
	// Calculating Score
	if (ball.pos.x < 0)
	{
		puan1++;
		score.play();
		this_thread::sleep_for(chrono::milliseconds(500));
		ball.pos = Vector2f((626), (346));
		ball.speed = Vector2f(0, 0);
	}
	if (ball.pos.x > 1259)
	{
		puan0++;
		score.play();
		this_thread::sleep_for(chrono::milliseconds(500));
		ball.pos = Vector2f((626), (346));
		ball.speed = Vector2f(0, 0);
	}

	// After ball and paddle collision, speed updates
}
