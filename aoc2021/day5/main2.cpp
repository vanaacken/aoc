#include "settings.hpp"
typedef std::pair<int, int>	x_y_pair;
typedef std::map<x_y_pair, int> co_map;
typedef std::pair<co_map, bool> map_ret;

void	fillMap(int x1, int y1, int x2, int y2, co_map *map)
{

}



int main(void)
{
	FILE *file;
	int ret = 0;
	int x1;
	int x2;
	int y1;
	int y2;
	co_map map;
	std::map<int,int> test;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,%d -> %d,%d\n",&x1, &y1, &x2, &y2);
		fillMap(x1,y1,x2,y2,&map);
	}
	test.insert(std::make_pair<int,int>(1,1));

	return (0);
}
























