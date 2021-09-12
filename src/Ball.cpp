#include "Ball.h"

Ball::Ball()
{
	shape_.setRadius(10.f);
	shape_.setFillColor(Color(255, 255, 0));
	shape_.setPosition(225.0710f, 400.f);
	setAngle(25.f);
}
//--------------------------------------------------------------
void Ball::draw(RenderWindow& window)
{
	window.draw(shape_);
}
//--------------------------------------------------------------
void Ball::update(const float& time)
{
	shape_.move(velocity * time * 0.01f);

	if (Left < 0.1f || Right > Constants::WHIDTH)
		velocity.x = - velocity.x;
	if (Top < 0.1f || Bottom > Constants::HEIGH)
		velocity.y = -velocity.y;
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
	if (Left < paddle->Right && Right > paddle->Left && Top < paddle->Top && Bottom > paddle->Top)
	{
		float deviation = 50.f;
		bool leftSide = Left < paddle->Left;
		float distanceFromCenter = std::abs(Left - paddle->Left);
		float percantage = distanceFromCenter / 45;
		float angle = 135.f - percantage * deviation * (leftSide ? -1.f : 1.f);
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
	return shape_.getPosition().x;
}
float Ball::getRight()
{
	return shape_.getPosition().x + shape_.getRadius()*2;
}
float Ball::getTop()
{
	return shape_.getPosition().y;
}
float Ball::getBottom()
{
	return shape_.getPosition().y + shape_.getRadius()*2;
}
//--------------------------------------------------------------