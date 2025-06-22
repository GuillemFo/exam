#include "Warlock.hpp"

Warlock::Warlock(){};
Warlock::Warlock(const Warlock &other){}; //might not be necessary since private
//Warlock &Warlock::operator=(const Warlock &other){}; //migth not be necessary since private


Warlock::Warlock(const std::string &nm, const std::string &tit) : name(nm), title(tit)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->getName() << ": My job here is done!" << std::endl;
}


const std::string &Warlock::getName() const
{
	return (this->name);
}

const std::string &Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(const std::string &tit)
{
	this->title = tit;
}

void Warlock::introduce() const
{
	std::cout << this->getName() << ": I am " << this->getName() << ", " << this->getTitle() << "!" << std::endl;
}


