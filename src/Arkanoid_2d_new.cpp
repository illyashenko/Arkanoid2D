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

    Image im_e;
    im_e.loadFromFile("destruction_block.png");
    im_e.createMaskFromColor(Color::White);
    Texture tx_e;
    tx_e.loadFromImage(im_e);
    Sprite destruction;
    destruction.setTexture(tx_e);
    destruction.setTextureRect(IntRect(0, 0, 255, 33));
    destruction.setPosition(100.f, 200.f);

    float currentFrame = 0.f;

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

        if (Keyboard::isKeyPressed(Keyboard::Space))
        {
            currentFrame += 0.001 * time;
            if (currentFrame > 3)
                currentFrame -= 3;
            destruction.setTextureRect(IntRect(85 * int(currentFrame), 0, 85, 33));
            //destruction.move(0.02 * time, 0);
            window.draw(destruction);
        }

        paddle->draw(window);
        ball->draw(window);
        window.draw(s);
        window.display();
    }
    return 0;
}
