#include "Polymorph.hpp"

Polymorph::Polymorph():ASpell("Polymorph", "turned into a critter"){}
Polymorph::~Polymorph()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}

ASpell *Polymorph::clone() const
{
	return (new Polymorph());
}

