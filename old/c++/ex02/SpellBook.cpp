#include "SpellBook.hpp"

SpellBook::SpellBook(){};

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_beg = arr_spell.begin();
	std::map<std::string, ASpell *>::iterator it_end = arr_spell.end();
	while (it_beg != it_end)
	{
		delete it_beg->second;
		++it_beg;
	}
	arr_spell.clear();
}




void SpellBook::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		arr_spell.insert(std::pair<std::string, ASpell*>(spell_ptr->getName(), spell_ptr->clone()));
}





void SpellBook::forgetSpell(const std::string &spell_name)
{
	std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
	if (it != arr_spell.end())
	{
		delete it->second;
	}
	arr_spell.erase(spell_name);
}







ASpell *SpellBook::createSpell(const std::string &spell_name)
{

	std::map<std::string, ASpell *>::iterator it = arr_spell.find(spell_name);
	if (it != arr_spell.end())
		return (arr_spell[spell_name]);
	return (NULL);
	
}























