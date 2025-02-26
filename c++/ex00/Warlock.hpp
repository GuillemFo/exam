#pragma once

#include <iostream>
#include <string>

class Warlock
{
	private:
		std::string name;
		std::string title;
		Warlock();
		Warlock(const Warlock &other);
		Warlock &operator=(const Warlock &other);

	public:
		const std::string &getName() const;
		const std::string &getTitle() const;

		void setTitle(const std::string &t); //const?
		Warlock(const std::string &nm, const std::string &tit);
		~Warlock();
		void introduce() const;


};
