#include "ATarget.hpp"

ATarget::ATarget(){};
ATarget::ATarget(const ATarget &other)
{
	*this = other;
}

ATarget &ATarget::operator=(const ATarget &other)
{
	this->type = other.type;
	return (*this);
}


ATarget::ATarget(const std::string &nm) : type(nm)
{
	//std::cout << this->name << ": This looks like another boring day." << std::endl;
}

ATarget::~ATarget()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}


const std::string &ATarget::getType() const
{
	return (this->type);
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << this->getType() << " has been " << spell.getEffects() << "!" <<std::endl;
}

