#include "settings.hpp"
int shortest = INT_MAX;
int size = 500;
int squared = ;
int ended = 0;
typedef std::map<int,int>::iterator iterator;
// typedef struct s_path
// {
// 	int x;
// 	int y;
// 	int tot_risk;
// }				Path;



void loop(std::vector<int> grid, int index, int risk)
{
	int new_risk = risk + grid[index];
	if (new_risk >= shortest)
	{
		ended++;
		std::cout << "end F: " << ended << std::endl;
		return ;
	}
	if (index == squared - 1)
	{
		if (risk < shortest)
		{
			shortest = risk;
			std::cout << "new shortest : " << shortest << std::endl;
		}
		ended++;
		std::cout << "end s: " << ended << std::endl;
		return;
	}
	if (index % size != size - 1 && index < squared - size)
	{
		if (grid[index + 1] < grid[index + size])
		{
			loop(grid, index + 1, new_risk);
			loop(grid, index + size, new_risk);
		}
		else
		{
			loop(grid, index + size, new_risk);
			loop(grid, index + 1, new_risk);
		}
	}
	else if (index % size != size - 1)
	{
		loop(grid, index + 1, new_risk);
	}
	else if (index < squared - size)
	{
		loop(grid, index + size, new_risk);
	}
}


void loopmap(std::vector<int> grid, std::map<int,int> map)
{
	for (iterator i = map.begin(); i != map.end(); ++i)
	{
		int check = 0;
		if (i->first % size != size - 1)
		{
			if (map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).first->second > i->second + grid[i->first + 1])
				{
					map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).first->second = i->second + grid[i->first + 1];
				}
			}
		}
		if (i->first < squared - size)
		{
			if (map.insert(std::make_pair<int,int>(i->first + size, i->second + grid[i->first + size])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first + size, i->second + grid[i->first + size])).first->second > i->second + grid[i->first + size])
				{
					map.insert(std::make_pair<int,int>(i->first + size, i->second + grid[i->first + size])).first->second = i->second + grid[i->first + size];
				}
			}
		}
	}
	if (std::prev(map.end())->first == squared - 1)
	{
		std::cout << "answer: " << std::prev(map.end())->second << std::endl;
	}
}










int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int set = 1;
	int n;
	char s[5];
	char s2[5];
	char s3[5];
	std::vector<int> arr;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%1d", &n);
		if (ret == EOF)
			break;
		if (ret == 0)
			break;

		arr.push_back(n);
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i];
		if (i % size == size - 1)
			std::cout << std::endl;
	}

	// std::cout<< std::endl << arr.size() << std::endl;
	// int x = 0;
	// int y = 0;
	// Path path;
	// path.x = 0;
	// path.y = 0;
	// path.tot_risk = 0;
	std::map<int, int> map;
	map.insert(std::make_pair<int,int>(0, 0));
	// std::cout << map.begin()->first << "    " << map.begin()->second << std::endl;
	loopmap(arr, map);
	


	
	// std::cout << "answer : " << shortest << std::endl;
	
}