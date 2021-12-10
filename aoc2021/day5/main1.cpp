#include "settings.hpp"
typedef std::pair<int, int>	x_y_pair;
typedef std::map<x_y_pair, int> co_map;
typedef co_map::iterator it;


void	fillDia(int x1, int y1, int x2, int y2, co_map *map)
{
	int dx;
	int dy;
	int min_x = fmin(x1, x2);
	int min_y = fmin(y1, y2);
	dx = x1-x2;
	dy = y1-y2;
	if (dx > 0)
	{
		if (dy > 0)
		{
			for (size_t x = 0; x <= dx; x++)
			{
				x_y_pair first = std::make_pair<int,int>(min_x + x, min_y + x);
				if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
				{
					map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
				}
			}
		}
		if (dy < 0)
		{
			for (size_t x = 0; x <= dx; x++)
			{
				x_y_pair first = std::make_pair<int,int>(min_x + x, min_y - dy - x);
				if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
				{
					map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
				}
			}
		}
	}
	else if (dx < 0)
	{
		if (dy > 0)
		{
			for (size_t x = 0; x <= -dx; x++)
			{
				x_y_pair first = std::make_pair<int,int>(min_x -dx - x, min_y + x);
				if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
				{
					map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
				}
			}
		}
		if (dy < 0)
		{
			for (size_t x = 0; x <= -dx; x++)
			{
				x_y_pair first = std::make_pair<int,int>(min_x - dx - x, min_y - dy - x);
				if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
				{
					map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
				}
			}
		}
	}
}



void	fillMap(int x1, int y1, int x2, int y2, co_map *map)
{
	int dx;
	int dy;
	int min_x = fmin(x1, x2);
	int min_y = fmin(y1, y2);
	dx = x1-x2;
	dy = y1-y2;
	if (dx < 0)
		dx = -dx;
	if (dy < 0)
		dy = -dy;

	if (dy > 0 && dx > 0)
	{
		fillDia(x1,y1,x2,y2,map);
	}
	else if (dy == 0)
	{
		for (size_t x = 0; x <= dx; x++)
		{
			x_y_pair first = std::make_pair<int,int>(min_x + x, min_y);
			if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
			{
				map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
			}
		}
	}
	else if (dx == 0)
	{
		for (size_t y = 0; y <= dy; y++)
		{
			x_y_pair first = std::make_pair<int,int>(min_x, min_y + y);
			if (map->insert(std::make_pair<x_y_pair, int>(first, 1)).second == false)
			{
				map->insert(std::make_pair<x_y_pair, int>(first, 1)).first->second += 1;
			}
		}
		
	}
	
	





}



int main(void)
{
	FILE *file;
	int ret = 0;
	int x1;
	int x2;
	int y1;
	int y2;
	int max_x = 0;
	int max_y = 0;
	int count = 0;
	int count2 = 0;
	co_map map;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,%d -> %d,%d\n",&x1, &y1, &x2, &y2);
		max_x = fmax(max_x,fmax(x1,x2));
		max_y = fmax(max_y,fmax(y1,y2));
		if (ret == EOF)
			break;
		fillMap(x1,y1,x2,y2,&map);
	}
	max_x++;
	max_y++;
	int grid[max_x][max_y];
	for (size_t i = 0; i < max_y; i++)
	{
		for (size_t j = 0; j < max_x; j++)
		{
			grid[j][i] = 0;
		}
	}
	for (it i = map.begin(); i != map.end(); ++i)
	{
		grid[i->first.first][i->first.second] = i->second;
		if (i->second > 1)
		{
			count++;
		}
	}
	// for (size_t i = 0; i < max_y; i++)
	// {
	// 	for (size_t j = 0; j < max_x; j++)
	// 	{
	// 		if (grid[j][i] == 0)
	// 			std::cout << ".";
	// 		else
	// 			std::cout << grid[j][i];
		
	// 	}
	// 	std::cout << std::endl;
	// }



	std::cout << "total : " << count << std::endl;	
	return (0);
}
























