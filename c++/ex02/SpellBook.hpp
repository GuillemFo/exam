#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
	private:
		SpellBook(const SpellBook &other);
		SpellBook &operator=(const SpellBook &other);
		std::map <std::string, ASpell *>arr_spell;
	public:
		SpellBook();
		~SpellBook();
				
		void learnSpell(ASpell *aspell_ptr);
		void forgetSpell(const std::string &spell_name);
		ASpell *createSpell(const std::string &spell_name);

};
