#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
#include "Paddle.h"
#include "Ball.h"

using namespace sf;

int main()
{
    ContextSettings settings;
    settings.antialiasingLevel = 16;
    VideoMode screen(Constants::WHIDTH, Constants::HEIGH, Constants::BITS_PER_PIXEL);
    RenderWindow window(screen
                        ,"Arkanoid"
                        , Style::Close | Style::Titlebar
                        , settings);

    Texture tx;
    tx.loadFromFile("materiya.jpg");
    Sprite sp;
    sp.setTexture(tx);

    Clock clock;

    Paddle* paddle = new Paddle();
    Ball* ball = new Ball();

    while (window.isOpen())
    {
        float time = (float)clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = (time / 200);

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        paddle->update(time);
        ball->update(time);
        ball->checkColission(paddle);

        window.clear(Color::Cyan);
        window.draw(sp);
        paddle->draw(window);
        ball->draw(window);
        window.display();
    }
    return 0;
}
