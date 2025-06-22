#include "Fwoosh.hpp"

Fwoosh::Fwoosh():ASpell("Fwoosh", "fwooshed"){}
Fwoosh::~Fwoosh()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}

