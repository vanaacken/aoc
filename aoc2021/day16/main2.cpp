#include "settings.hpp"

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