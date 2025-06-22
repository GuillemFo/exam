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
	std::map<std::string, ASpell *>::iterator it_beg = arr.begin();
	std::map<std::string, ASpell *>::iterator it_end = arr.end();
	while (it_beg != it_end)
	{
		delete it_beg->second;
		++it_beg;
	}
	arr.clear();
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




void Warlock::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		arr.insert(std::pair<std::string, ASpell*>(spell_ptr->getName(), spell_ptr->clone()));
}





void Warlock::forgetSpell(std::string spell_name)
{
	std::map<std::string, ASpell *>::iterator it = arr.find(spell_name);
	if (it != arr.end())
	{
		delete it->second;
	}
	arr.erase(spell_name);
}







void Warlock::launchSpell(std::string spell_name, const ATarget &tar_ref)
{
	ASpell *spell = arr[spell_name];
	if (spell)
	{
		spell->launch(tar_ref);
	}
}























