#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "sticks.h"
#include "ball.h"
#include "collision.h"
#include "score.h"

// If paddle[0] or paddle[1] reaches to a score of "10", 
// Change: ball.speed, paddle.pos, paddle.speed 

void gameOver(Ball& ball, Paddle& stick0, Paddle& stick1)
{
	if (stick0.score >= 10 || stick1.score >= 10)
	{
		stick0.score = 0;
		stick1.score = 0;
		stick0.speed = 1.f;
		stick1.speed = 1.f;

		ball.speed = Vector2f(0, 0);
		ball.pos = Vector2f((626), (346));
		this_thread::sleep_for(chrono::milliseconds(800));
	}
}