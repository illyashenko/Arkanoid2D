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
void Block::update(float time)
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