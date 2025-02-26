#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(){};

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_beg = arr_tar.begin();
	std::map<std::string, ATarget *>::iterator it_end = arr_tar.end();
	while (it_beg != it_end)
	{
		delete it_beg->second;
		++it_beg;
	}
	arr_tar.clear();
}




void TargetGenerator::learnTargetType(ATarget *atar_ptr)
{
	if (atar_ptr)
		arr_tar.insert(std::pair<std::string, ATarget*>(atar_ptr->getType(), atar_ptr->clone()));
}





void TargetGenerator::forgetTargetType(const std::string &tar_name)
{
	std::map<std::string, ATarget *>::iterator it = arr_tar.find(tar_name);
	if (it != arr_tar.end())
	{
		delete it->second;
	}
	arr_tar.erase(tar_name);
}







ATarget *TargetGenerator::createTarget(const std::string &tar_name)
{

	std::map<std::string, ATarget *>::iterator it = arr_tar.find(tar_name);
	if (it != arr_tar.end())
		return (arr_tar[tar_name]);
	return (NULL);
	
}























