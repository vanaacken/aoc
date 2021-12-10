#include "settings.hpp"

// forward x
// down x
// up x

int main(void)
{
	FILE *file;
	std::vector<std::pair<std::string, int> > arr;
	int n;
	char movement[8];
	int hor = 0;
	int depth = 0;
	int aim = 0;
	file = fopen("resources", "read");
	
	while (fscanf(file, "%s %d\n",movement, &n) != EOF)
	{
		arr.push_back(std::make_pair<std::string, int>(movement, n));
	}
	std::cout << "array size: " << arr.size() << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i].first.compare("forward") == 0)
		{
			hor += arr[i].second;
			depth += (aim * arr[i].second); 
		}
		else if (arr[i].first.compare("down") == 0)
		{
			aim += arr[i].second;
		}
		else if (arr[i].first.compare("up") == 0)
		{
			aim -= arr[i].second;
		}
	}
	std::cout << "check : " << arr[554].first << arr[554].second << std::endl;
	
	std::cout << "horizontal : " << hor << std::endl;
	std::cout << "depth      : " << depth << std::endl;
	std::cout << "multiplied : " << hor * depth << std::endl;




	return (0);
}
























