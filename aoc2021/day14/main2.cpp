#include "settings.hpp"
#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
typedef std::pair<std::string, std::string> key;
typedef std::map<key, unsigned long int> Map;
typedef std::map<key, unsigned long int>::iterator Map_iterator;
typedef	std::map<std::pair<std::string, std::string>, std::string >::iterator instruc_iterator;
typedef	std::list<std::string>::iterator list_iterator;;



Map loop(Map map, std::map<std::pair<std::string, std::string>, std::string > instruc)
{
	Map ret;
	for(Map_iterator i = map.begin(); i != map.end(); ++i)
	{
		key key1;
		key key2;
		unsigned long int value;
		std::string in = instruc.find(i->first)->second;
		value = i->second;
		key1 = std::make_pair<std::string, std::string>(i->first.first, in);
		key2 = std::make_pair<std::string, std::string>(in, i->first.second);
		// std::cout << "OLD   : " << i->first.first << i->first.second << std::endl;
		// std::cout << "INSER : " << in << std::endl;
		// std::cout << "KEY 1 : " << key1.first << key1.second << std::endl;
		// std::cout << "KEY 2 : " << key2.first << key2.second << std::endl;
		if (ret.insert(std::make_pair<key, unsigned long int>(key1, value)).second == false)
		{
			ret.insert(std::make_pair<key, unsigned long int>(key1, value)).first->second += value;
		}
		if (ret.insert(std::make_pair<key, unsigned long int>(key2, value)).second == false)
		{
			ret.insert(std::make_pair<key, unsigned long int>(key2, value)).first->second += value;
		}
	}
	return ret;
}


// int main ()
// {
//   time_t seconds;

//   seconds = time (NULL);
//   printf ("%ld seconds since January 1, 1970", seconds);

//   return 0;
int main(void)
{
	struct timeval stop, start;
	gettimeofday(&start, NULL);
	
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
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

	Map map;
	for(list_iterator i = list.begin(); i != list.end(); ++i)
	{
		if (i == list.begin())
			continue;
		key k = std::make_pair<std::string, std::string>(*(std::prev(i)), *i);
		if (map.insert(std::make_pair<key, unsigned long int>(k, 1)).second == false)
		{
			map.insert(std::make_pair<key, unsigned long int>(k, 1)).first->second += 1;
		}
	}
	// std::cout << "Keys : " << std::endl;;
	

	for (size_t i = 0; i < 40; i++)
	{
		Map ret;
		ret = loop(map, instruc);
		map.clear();
		map = ret;
	}
	// for (Map_iterator i = map.begin(); i != map.end(); ++i)
	// {
	// 	std::cout << i->first.first << i->first.second << "  n: " << i->second << std::endl;
	// }
	std::map<std::string, unsigned long int> counter;
	for (Map_iterator i = map.begin(); i != map.end(); ++i)
	{
		if (i == map.begin())
		{
			if (counter.insert(std::make_pair<std::string, unsigned long int>(i->first.first, i->second)).second == false)
			{
				counter.insert(std::make_pair<std::string, unsigned long int>(i->first.second, i->second)).first->second += i->second; 
			}
		}
		else
		{
			if (counter.insert(std::make_pair<std::string, unsigned long int>(i->first.second, i->second)).second == false)
			{
				counter.insert(std::make_pair<std::string, unsigned long int>(i->first.second, i->second)).first->second += i->second; 
			}
		}

	}
	unsigned long int max = 0;
	unsigned long int min = ULONG_MAX;
	for (std::map<std::string,unsigned long int>::iterator i = counter.begin(); i != counter.end(); ++i)
	{
		if (i->second > max)
			max = i->second;
		if (i->second < min)
			min = i->second;
	}
	

	std::cout << "answer : " << max - min << std::endl;
	gettimeofday(&stop, NULL);
	printf("time : %lu\n", (stop.tv_sec - start.tv_sec) * 1000 + (stop.tv_usec - start.tv_usec) / 1000); 
	// std::cout << "time : " << diff << std::endl;
}