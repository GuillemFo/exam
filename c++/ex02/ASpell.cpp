#include "ASpell.hpp"

ASpell::ASpell(){}
ASpell::ASpell(const ASpell &other)
{
	*this = other;
}

ASpell &ASpell::operator=(const ASpell &other)
{
	this->name = other.name;
	this->effects = other.effects;
	return (*this);
}


ASpell::ASpell(const std::string &nm, const std::string &tit) : name(nm), effects(tit)
{
	//std::cout << this->name << ": This looks like another boring day." << std::endl;
}

ASpell::~ASpell()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}


const std::string &ASpell::getName() const
{
	return (this->name);
}

const std::string &ASpell::getEffects() const
{
	return (this->effects);
}

void ASpell::launch(const ATarget &tar) const
{
	tar.getHitBySpell(*this);
}

