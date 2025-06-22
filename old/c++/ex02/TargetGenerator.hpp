#pragma once

#include <iostream>
#include <string>
#include "ATarget.hpp"

#include <map>

class TargetGenerator
{
	private:
		TargetGenerator(const TargetGenerator &other);
		TargetGenerator &operator=(const TargetGenerator &other);
		std::map <std::string, ATarget *>arr_tar;
	public:
		TargetGenerator();
		~TargetGenerator();
				
		void learnTargetType(ATarget *atar_ptr);
		void forgetTargetType(const std::string &tar_name);
		ATarget *createTarget(const std::string &tar_name);

};
