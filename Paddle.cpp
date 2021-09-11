#include "Paddle.h"

Paddle::Paddle() : speed_(0.2f)
{
	Image image;
	image.loadFromFile("puddle2.png");
	image.createMaskFromColor(Color::White);
	texture_.loadFromImage(image);

	sprite.setTexture(texture_);
	sprite.setPosition(360.0, 575.0);
}
//-------------------------------------------------------
Paddle::Paddle(PaddleType p_type)
{
	Image image;
	image.loadFromFile(getImage(p_type));

	texture_.loadFromImage(image);

	sprite.setTexture(texture_);
	sprite.setPosition(180.0, 580.0);

}
//-------------------------------------------------------
void Paddle::draw(RenderWindow& window)
{
	window.draw(sprite);
}
//-------------------------------------------------------
void Paddle::update(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::Right) && Right < Constants::WHIDTH)
	{
		sprite.move(speed_ * time, 0);
	}
	if (Keyboard::isKeyPressed(Keyboard::Left) && Left > 0)
	{
		sprite.move(-speed_ * time, 0);
	}
}
//-------------------------------------------------------
float Paddle::getRight()
{
	return sprite.getPosition().x + 90;
}
float Paddle::getLeft()
{
	return sprite.getPosition().x;
}
float Paddle::getTop()
{
	return sprite.getPosition().y;
}
Vector2f Paddle::getPosition()
{
	return sprite.getPosition();
}
Vector2u Paddle::getSize()
{
	return texture_.getSize();
}
//-------------------------------------------------------
std::string Paddle::getImage(PaddleType p_type) {

	std::string file_path;

	switch (p_type)
	{
	case PaddleType::SMALL:
		file_path = "puddle2.png";
		break;
	case PaddleType::MIDDLE:
		break;
	case PaddleType::BIG:
		break;
	}

	return file_path;

}
