#pragma once

#include <iostream>
#include <string>
#include "ASpell.hpp"

class ASpell;
class ATarget
{
	protected:
		std::string type;
		ATarget();
	public:
		const std::string &getType() const;
		
		ATarget(const ATarget &other);
		void setType(const std::string &t); //const?
		ATarget &operator=(const ATarget &other);
		ATarget(const std::string &nm);
		virtual ~ATarget();
		virtual ATarget *clone() const =0;

		void getHitBySpell(const ASpell &spell) const;
	
};
