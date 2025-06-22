#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;
class ASpell
{
	protected:
		std::string name;
		std::string effects;
	public:
		ASpell();
		const std::string &getName() const;
		const std::string &getEffects() const;

		ASpell(const ASpell &other);
		ASpell &operator=(const ASpell &other);
		ASpell(const std::string &nm, const std::string &ef);
		virtual ~ASpell();
		virtual ASpell *clone() const =0;
		
		void launch(const ATarget &tar) const;		


};
