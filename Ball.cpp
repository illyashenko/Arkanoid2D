#include "Ball.h"

Ball::Ball()
{
	shape_.setRadius(8.f);
	shape_.setFillColor(Color::Yellow);
	shape_.setPosition(225.0710f, 400.f);
	setAngle(20.f);
}
//--------------------------------------------------------------
void Ball::draw(RenderWindow& window)
{
	window.draw(shape_);
}
//--------------------------------------------------------------
void Ball::update(float time)
{
	shape_.move(velocity *time * 0.015f);

	if (shape_.getPosition().x < 0.1f)
		velocity.x = - velocity.x;
	if(shape_.getPosition().x > (Constants::WHIDTH - 16))
		velocity.x = -velocity.x;
	if (shape_.getPosition().y < 0.1f)
		velocity.y = -velocity.y;
	if (shape_.getPosition().y > (Constants::HEIGH - 16))
		velocity.y = - velocity.y;
}
//--------------------------------------------------------------
void Ball::setAngle(float angle)
{
	velocity.x = 11.f * (float)std::cos(angle * M_PI / 180);
	velocity.y = -11.f * (float)std::sin(angle * M_PI / 180);
}
float Ball::getAngle()
{
	float angle = std::atan2(-velocity.y, velocity.x) * 180 / M_PI;

	if (angle < 0.f)
		angle += 360.f;

	return angle;
}
//--------------------------------------------------------------
bool Ball::checkColission(Paddle* paddle)
{
	if (Left < paddle->Right && Right > paddle->Left && Top < paddle->Top && Bottom >= paddle->Top)
	{

		float deviation = 50.f;
		bool leftSide = shape_.getPosition().x < paddle->getPosition().x;
		float distanceFromCenter = std::abs(shape_.getPosition().x - paddle->getPosition().x);
		float percantage = distanceFromCenter / ((float)paddle->getSize().x / 2.f);
		float angle = 90.f - percantage * deviation * (leftSide ? -1.f : 1.f);
		setAngle(angle);
		return true;
	}
	return false;
}
bool Ball::checkColission()
{
	return false;
}
//--------------------------------------------------------------
float Ball::getLeft()
{
	return shape_.getPosition().x - shape_.getRadius();
}
float Ball::getRight()
{
	return shape_.getPosition().x + shape_.getRadius();
}
float Ball::getTop()
{
	return shape_.getPosition().y - shape_.getRadius();
}
float Ball::getBottom()
{
	return shape_.getPosition().y + shape_.getRadius();
}
//--------------------------------------------------------------