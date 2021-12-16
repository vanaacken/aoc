#include "settings.hpp"
typedef	std::map<std::pair<std::string, std::string>, std::string >::iterator map_iterator;
typedef std::pair<std::string, std::string> eval;
typedef	std::list<std::string>::iterator list_iterator;;



std::list<std::string> loop(std::list<std::string> list, std::map<std::pair<std::string, std::string>, std::string > map)
{
	for (list_iterator i = list.begin(); i != list.end(); ++i)
	{
		if (i == list.begin())
			continue;
		eval e= std::make_pair<std::string,std::string>(*(std::prev(i)), *i);
		map_iterator found = map.find(e);
		if (found != map.end())
		{
			// std::string element = found->second;
			list.insert(i, found->second);
		}
	}
	return (list);
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int x;
	int y;
	int set = 1;
	char s[5];
	char s2[5];
	char s3[5];
	std::vector<std::string> arr;
	std::map<std::pair<std::string, std::string>, std::string > instruc;
	std::list<std::string> list;
	file = fopen("resources", "read");
	for (int i = 0; i < 20; i++)
	{
		ret = fscanf(file, "%1s", s);
		if (ret == EOF)
			break;
		if (ret == 0)
			break;

		list.push_back(s);
	}
	while (ret != EOF)
	{
		ret = fscanf(file, "%1s%1s %*s %1s\n", s2, s3, s);
		if (ret == EOF)
			break;
		std::pair<std::string, std::string> key = std::make_pair<std::string, std::string>(s2, s3);
		std::string value = s;
		instruc.insert(std::make_pair<std::pair<std::string, std::string>, std::string>(key, value));
	}

	for (map_iterator i = instruc.begin(); i != instruc.end(); ++i)
	{
		std::cout << "Key first : " << i->first.first << "; second : " << i->first.second << "; Value : " << i->second << std::endl;
	}
	std::cout << "Template : ";
	for(list_iterator i = list.begin(); i != list.end(); ++i)
	{
		std::cout << *i; 
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 40; i++)
	{
		std::cout << "Loop : " << i << std::endl;
		list = loop(list, instruc);
		// std::cout << "After step " << i << ": ";
		// for(list_iterator it = list.begin(); it != list.end(); ++it)
		// {
			// std::cout << *it;
		// }
		// std::cout << std::endl;
	}
	std::map<std::string, unsigned long long int> map;
	for(list_iterator it = list.begin(); it != list.end(); ++it)
	{
		if (map.insert(std::make_pair<std::string, unsigned long long int>(*it, 1)).second == false)
		{
			map.insert(std::make_pair<std::string, unsigned long long int>(*it, 1)).first->second += 1;
		}
	}
	unsigned long long int max = 0;
	unsigned long long int min = ULONG_MAX;
	for (std::map<std::string, unsigned long long int >::iterator i = map.begin(); i != map.end(); ++i)
	{
		std::cout << i->first << ", " << i->second << std::endl;
		if (i->second > max)
		{
			max = i->second;
		}
		if (i->second < min)
		{
			min = i->second;
		}
	}
	
	std::cout << "answer : " << max - min << std::endl;
	
}