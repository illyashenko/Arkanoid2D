#include "Block.h"

Block::Block()
{

}
Block::Block(BlockType blockType, Vector2f position)
{
}
//--------------------------------------------------------------
void Block::draw(RenderWindow& window)
{
	window.draw(sprite_);
}
//--------------------------------------------------------------
void Block::update(const float& time)
{

}
//--------------------------------------------------------------
float Block::getLeft()
{
	return sprite_.getPosition().x;
}
float Block::getRight()
{
	return sprite_.getPosition().x + 74.f;
}
float Block::getTop()
{
	return sprite_.getPosition().y;
}
float Block::getBottom()
{
	return sprite_.getPosition().y + 20;
}
//--------------------------------------------------------------
void Block::setPosition(Vector2f position)
{
	sprite_.setPosition(position);
}
std::string Block::getImage(BlockType blocType)
{
	switch (blocType)
	{
	case BlockType::SINGLE :
		return "graphics/blok_blue.png";
	case BlockType::DOUBLE : 
		return "";
	case BlockType::TRIPLE : 
		return "";
	case BlockType::BROKEN :
		return "graphics/destruction_block.png";
	default:
		return "";
		break;
	}
}
//--------------------------------------------------------------