#include <iostream>
#include <SFML/Graphics.hpp>
#include "constants.h"
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

   /* Image im_e;
    im_e.loadFromFile("graphics/destruction_block.png");
    im_e.createMaskFromColor(Color::White);
    Texture tx_e;
    tx_e.loadFromImage(im_e);
    Sprite destruction;
    destruction.setTexture(tx_e);
    destruction.setPosition(100.f, 200.f);*/

    float currentFrame = 0.f;

    Paddle* paddle = new Paddle();
    Ball* ball = new Ball();
    Block* block = new Block();

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

        if (Keyboard::isKeyPressed(Keyboard::Space) && block)
        {
            block->exchangeBlock(BlockType::BROKEN);
            block->update(time);
            if (block->stopFrame()) {
                delete block;
                block = nullptr;
            }
        }

        paddle->draw(window);
        
        if (block) {
            block->draw(window);
        }

        ball->draw(window);
        window.display();
    }
    return 0;
}
