#pragma once
#include "IEntity.h"

using namespace sf;

enum class BlockType
{
	SINGLE,
	DOUBLE,
	TRIPLE,
	BROKEN
};

class Block : public IEntity
{
public:
	Block();
	Block(BlockType blockType, Vector2f position);
	void draw(RenderWindow& window);
	void update(const float& time);
	float getLeft();
	float getRight();
	float getTop();
	float getBottom();
	void setPosition(Vector2f position);
	BlockType getBlockType();
	void setBlockType(BlockType blockType);
	void exchangeBlock(BlockType blockType);
	bool stopFrame();

	_declspec(property(get = getLeft)) float Left;
	_declspec(property(get = getRight)) float Right;
	_declspec(property(get = getTop)) float Top;
	_declspec(property(get = getBottom)) float Bottom;
private:
	Sprite sprite_;
	Texture texture_;
	BlockType blocType_;
	float currentFrame;
	bool stop;

	std::string getImage();
};

