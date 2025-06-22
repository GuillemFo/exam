#include "BrickWall.hpp"

BrickWall::BrickWall():ATarget("Inconspicuous Red-brick Wall"){}
BrickWall::~BrickWall()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}

ATarget *BrickWall::clone() const
{
	return (new BrickWall());
}

