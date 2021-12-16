#include "settings.hpp"
int shortest = INT_MAX;
int size = 100;
int squared = size * size;
int size5 = size * 5;
int sq5 = size5 * size5;
int ended = 0;
typedef std::map<int,int>::iterator iterator;


void loopmap(std::vector<int> grid, std::map<int,int> map)
{
	int check = 0;
	std::map<int,int> ret;
	for (iterator i = map.begin(); i != map.end(); ++i)
	{
		if (i->first < sq5 - size5)
		{
			if (map.insert(std::make_pair<int,int>(i->first + size5, i->second + grid[i->first + size5])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first + size5, i->second + grid[i->first + size5])).first->second > i->second + grid[i->first + size5])
				{
					map.insert(std::make_pair<int,int>(i->first + size5, i->second + grid[i->first + size5])).first->second = i->second + grid[i->first + size5];
					check = 1;
				}
			}
		}
		if (i->first % size5 != size5 - 1)
		{
			if (map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).first->second > i->second + grid[i->first + 1])
				{
					map.insert(std::make_pair<int,int>(i->first + 1, i->second + grid[i->first + 1])).first->second = i->second + grid[i->first + 1];
					check = 1;
				}
			}
		}
		if (i->first > size5)
		{
			if (map.insert(std::make_pair<int,int>(i->first - size5, i->second + grid[i->first - size5])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first - size5, i->second + grid[i->first - size5])).first->second > i->second + grid[i->first - size5])
				{
					map.insert(std::make_pair<int,int>(i->first - size5, i->second + grid[i->first - size5])).first->second = i->second + grid[i->first - size5];
					check = 1;
				}
			}
		}
		if (i->first % size5 != 0)
		{
			if (map.insert(std::make_pair<int,int>(i->first - 1, i->second + grid[i->first - 1])).second == false )
			{
				if (map.insert(std::make_pair<int,int>(i->first - 1, i->second + grid[i->first - 1])).first->second > i->second + grid[i->first - 1])
				{
					map.insert(std::make_pair<int,int>(i->first - 1, i->second + grid[i->first - 1])).first->second = i->second + grid[i->first - 1];
					check = 1;
				}
			}
		}
	}
	if (check == 1)
		loopmap(grid, map);
	if (std::prev(map.end())->first == sq5 - 1)
	{
		std::cout << "size+ : " << map.size() << std::endl;
		std::cout << "answer: " << std::prev(map.end())->second << std::endl;
		// exit(1);
	}
}


std::vector<int> buildgrid(std::vector<int> arr)
{
	int grid[size5][size5];
	for (size_t i = 0; i < size5; i++)
	{
		for (size_t j = 0; j < size5; j++)
		{
			grid[i][j] = 0;
		}
	}
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		grid[i/size][i%size] = arr[i];
	}
	
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{

			for (size_t x = 0; x < 5; x++)
			{
				for (size_t y = 0; y < 5; y++)
				{
					grid[i + y*size][j + x*size] = grid[i][j];
					for (size_t count = 0; count < x+y; count++)
					{
						grid[i + y*size][j + x*size]++;
						if (grid[i + y*size][j + x*size] > 9)
							grid[i + y*size][j + x*size] = 1;
					}
				}
				
			}
		}
	}

	std::vector<int> ret;
	for (size_t i = 0; i < size5; i++)
	{
		for (size_t j = 0; j < size5; j++)
		{
			// std::cout << grid[i][j];
			ret.push_back(grid[i][j]);
		}
		// std::cout << std::endl;
	}
	
	return ret;
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
	// for (size_t i = 0; i < arr.size(); i++)
	// {
	// 	std::cout << arr[i];
	// 	if (i % size == size - 1)
	// 		std::cout << std::endl;
	// }
	std::vector<int> grid;
	grid = buildgrid(arr);
	std::map<int, int> map;
	map.insert(std::make_pair<int,int>(0, 0));
	// std::cout << map.begin()->first << "    " << map.begin()->second << std::endl;
	loopmap(grid, map);
	


	
	// std::cout << "answer : " << shortest << std::endl;
	
}