#pragma once
#include "IEntity.h"
#include "Paddle.h"
#include "Block.h"

#define M_PI 3.14159265358979323846

using namespace sf;

class Ball : public IEntity
{
public:
	Vector2f velocity;

	Ball();
	void draw(RenderWindow& window);
	void update(const float& time);
	void setAngle(float angle);
	float getAngle();
	bool checkColission(Paddle* paddle);
	bool checkColission(Block* block);

	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	_declspec(property(get = getLeft)) float Left;
	_declspec(property(get = getRight)) float Right;
	_declspec(property(get = getTop)) float Top;
	_declspec(property(get = getBottom)) float Bottom;

private:
	CircleShape shape_;
};

