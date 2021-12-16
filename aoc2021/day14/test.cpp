#include "settings.hpp"





int main(void)
{
	typedef std::map<int, int>::iterator iterator;
	std::map<int, int> map;
	for (size_t i = 0; i < 10; i++)
	{
		map.insert(std::make_pair<int, int>(i, i));
	}
	for (iterator i = map.begin(); i != map.end(); ++i)
	{
		std::cout << i->second << std::endl;
	}
	












}