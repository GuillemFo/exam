#include "Fireball.hpp"

Fireball::Fireball():ASpell("Fireball", "burnt to a crisp"){}
Fireball::~Fireball()
{
	//std::cout << this->getName() << ": My job here is done!" << std::endl;
}

ASpell *Fireball::clone() const
{
	return (new Fireball());
}

