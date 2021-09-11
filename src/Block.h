#pragma once
#include "IEntity.h"

using namespace sf;

enum class BlockType
{
	SINGLE,
	DOUBLE,
	TRIPLE
};

class Block : public IEntity
{
public:
	Block();
	Block(BlockType blockType, Vector2f position);
	void draw(RenderWindow& window);
	void update(float time);
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();

	_declspec(property(get = getLeft)) float Left;
	_declspec(property(get = getRight)) float Right;
	_declspec(property(get = getTop)) float Top;
	_declspec(property(get = getBottom)) float Bottom;
private:
	Sprite sprite_;
	Texture texture_;
};

