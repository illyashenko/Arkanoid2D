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

    Clock clock;

    Image im;
    im.loadFromFile("blok_blue.png");
    im.createMaskFromColor(Color::White);
    Texture tx;
    tx.loadFromImage(im);
    Sprite s;
    s.setTexture(tx);
    s.setPosition(50.f, 100.f);

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

        window.clear(Color(70, 130, 180));
        paddle->draw(window);
        ball->draw(window);
        window.draw(s);
        window.display();
    }
    return 0;
}
