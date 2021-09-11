#pragma once
#include "IEntity.h"

using namespace sf;
//-------------------------------------------------------
enum class PaddleType
{
	SMALL,
	MIDDLE,
	BIG
};
//-------------------------------------------------------
class Paddle : public IEntity
{
public:
	Sprite sprite;

	Paddle();
	Paddle(PaddleType p_type);
	void draw(RenderWindow& window);
	void update(float time);
	float getRight();
	float getLeft();
	float getTop();
	Vector2f getPosition();
	Vector2u getSize();

	_declspec(property(get=getRight)) float Right;
	_declspec(property(get=getLeft)) float Left;
	_declspec(property(get=getTop)) float Top;

private:
	Texture texture_;
	float speed_;

	std::string getImage(PaddleType p_type);
};
//-------------------------------------------------------
