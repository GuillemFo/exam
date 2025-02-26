#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);
		std::map <std::string, ASpell *>arr;
	public:
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &t); //const?
		Warlock(const std::string &nm, const std::string &tit);
		~Warlock();
		void introduce() const;
		
		void learnSpell(ASpell *spell_ptr);
		void forgetSpell(std::string spell_name);
		void launchSpell(std::string spell_name, const ATarget &tar_ref);

};
