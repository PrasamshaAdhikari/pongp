
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "sticks.h"
#include "ball.h"
#include "collision.h"
#include "score.h"
#include "GameOver.h"

using namespace sf;

class Game {
private:
    RenderWindow window;
    Paddle paddles[2];
    Ball ball;
    SoundBuffer buf_paddle, buf_wall, buf_score;
    Sound paddleSound, wallSound, scoreSound;
    Texture scText;
    Sprite scoreSprite;
    int W, H;

public:
    Game(int width, int height)
        : window(VideoMode(width, height), "Pong!"), W(width), H(height) {
        window.setKeyRepeatEnabled(true);
        window.setVerticalSyncEnabled(false);

        // Load Sounds
        buf_paddle.loadFromFile("C:\\Users\\Mücahit\\Desktop\\pong\\paddle.wav");
        buf_wall.loadFromFile("C:\\Users\\Mücahit\\Desktop\\pong\\wall.wav");
        buf_score.loadFromFile("C:\\Users\\Mücahit\\Desktop\\pong\\score.wav");
        paddleSound.setBuffer(buf_paddle);
        wallSound.setBuffer(buf_wall);
        scoreSound.setBuffer(buf_score);

        // Initialize Paddles
        paddles[0].pos = Vector2f(20, 305);
        paddles[1].pos = Vector2f(W - 40, 305);
        paddles[0].initPaddles("C:\\Users\\Mücahit\\Desktop\\pong\\stick_1.png");
        paddles[1].initPaddles("C:\\Users\\Mücahit\\Desktop\\pong\\stick_2.png");
        paddles[0].speed = 1.f;
        paddles[1].speed = 1.f;
        paddles[0].dir = 2;
        paddles[1].dir = 2;
        paddles[0].score = 0;
        paddles[1].score = 0;

        // Initialize Ball
        ball.pos = Vector2f(626, 346);
        ball.initBall("C:\\Users\\Mücahit\\Desktop\\pong\\ball.png");
        ball.speed = Vector2f(0, 0);

        // Initialize Score Text
        scText.loadFromFile("C:\\Users\\Mücahit\\Desktop\\pong\\score.png");
        scoreSprite.setTexture(scText);
        scoreSprite.setPosition(546, 35);
        createNumberSprites(window);
    }

    void run() {
        while (window.isOpen()) {
            processEvents();
            update();
            render();
        }
    }

private:
    void processEvents() {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }
    }

    void update() {
        // Game Input Logic
        handleInput();

        // Start The Game By Pressing "SPACE"
        if (Keyboard::isKeyPressed(Keyboard::Space)) {
            whoStartsTheGame(paddles[0], paddles[1], ball);
        }

        // Check Collision
        Collision(ball, paddles[1], paddles[0], paddleSound, scoreSound, paddles[0].score, paddles[1].score);

        paddles[0].movePaddles(ball);
        paddles[1].movePaddles(ball);
        ball.moveBall();
        gameOver(ball, paddles[0], paddles[1]);
        updateScore(paddles[0].score, paddles[1].score, window);
    }

    void handleInput() {
        if (Keyboard::isKeyPressed(Keyboard::W)) paddles[0].dir = 0;
        else if (Keyboard::isKeyPressed(Keyboard::S)) paddles[0].dir = 1;
        else paddles[0].dir = 2;

        if (Keyboard::isKeyPressed(Keyboard::Up)) paddles[1].dir = 0;
        else if (Keyboard::isKeyPressed(Keyboard::Down)) paddles[1].dir = 1;
        else paddles[1].dir = 2;
    }

    void render() {
        window.clear(Color::Black);

        // Draw Elements
        paddles[0].drawPaddles(window);
        paddles[1].drawPaddles(window);
        ball.drawBall(window);
        window.draw(scoreSprite);

        window.display();
    }
};

int main() {
    Game pong(1280, 720);
    pong.run();
    return 0;
}
