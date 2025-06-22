#include "Dummy.hpp"

Dummy::Dummy():ATarget("Target Practice Dummy"){}
Dummy::~Dummy()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}

ATarget *Dummy::clone() const
{
	return (new Dummy());
}

