#include "Block.h"

Block::Block() : currentFrame(0.f) , stop(false)
{
	blocType_ = BlockType::SINGLE;
	Image im;
	im.loadFromFile(getImage());
	im.createMaskFromColor(Color::White);

	texture_.loadFromImage(im);
	sprite_.setTexture(texture_);
	sprite_.setPosition(50.f, 100.f);

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
	if (blocType_ != BlockType::BROKEN)
		return;

	currentFrame += 0.001f * time;
	if (currentFrame > 3) {
		currentFrame -= 3;
		stop = true;
	}
	sprite_.setTextureRect(IntRect(85 * int(currentFrame), 0, 85, 33));
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
//--------------------------------------------------------------
BlockType Block::getBlockType()
{
	return blocType_;
}
void Block::setBlockType(BlockType blockType)
{
	this->blocType_ = blockType;
}
void Block::exchangeBlock(BlockType blockType)
{
	this->blocType_ = blockType;
	Image im;
	im.loadFromFile(getImage());
	im.createMaskFromColor(Color::White);
	texture_.loadFromImage(im);
}
bool Block::stopFrame()
{
	return stop;
}
//--------------------------------------------------------------
std::string Block::getImage()
{
	switch (blocType_)
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