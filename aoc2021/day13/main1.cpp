#include "settings.hpp"
typedef std::pair<int, int> xy_pair;
typedef std::vector<xy_pair>::iterator iterator;





std::vector<xy_pair> foldHor(std::vector<xy_pair> *arr, int pos)
{
	std::vector<xy_pair> ret;
	int dist;
	for (iterator it = arr->begin(); it != arr->end(); ++it)
	{
		if (it->second <= pos)
		{
			ret.push_back(*it);
			continue;
		}
		dist = it->second - pos;
		xy_pair in = std::make_pair(it->first, pos - dist);
		ret.push_back(in);
	}
	


	return ret;
}


std::vector<xy_pair> foldVert(std::vector<xy_pair> *arr, int pos)
{
	std::vector<xy_pair> ret;
	int dist;
	for (iterator it = arr->begin(); it != arr->end(); ++it)
	{
		if (it->first <= pos)
		{
			ret.push_back(*it);
			continue;
		}
		dist = it->first - pos;
		xy_pair in = std::make_pair(pos - dist, it->second);
		ret.push_back(in);
	}
	return ret;
}

std::vector<xy_pair> fold(std::vector<xy_pair> *arr, std::string dir, int pos)
{
	std::vector<xy_pair> ret;
	if (dir.compare("x=")== 0)
		ret = foldVert(arr, pos);
	else
		ret = foldHor(arr, pos);
	return ret;
}

size_t hash(xy_pair p)
{
	return (p.first * 113 + p.second * 229);
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
	char s[25];

	std::vector<xy_pair> arr;
	std::vector<std::pair<std::string, int > > instruc;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,%d\n", &x, &y);
		if (ret == EOF)
			break;
		if (ret == 0)
			break;

		xy_pair co = std::make_pair<int, int>(x, y);
		arr.push_back(co);
	}
	while (ret != EOF)
	{
		ret = fscanf(file, "%*s %*s %2s%d\n", s, &x);
		if (ret == EOF)
			break;
		instruc.push_back(std::make_pair<std::string, int>(s, x));
	}
	for (std::vector<xy_pair>::iterator i = arr.begin(); i != arr.end() ; ++i)
	{
		std::cout << i->first << ", " << i->second << std::endl;
	}
	std::map<int, int> map;
	for (size_t i = 0; i < instruc.size(); i++)
	{
		// std::cout << instruc[i].first << "     " << instruc[i].second << std::endl;
		std::vector<xy_pair> folded = fold(&arr, instruc[i].first, instruc[i].second);
		arr = folded;
	}
	for (iterator it = arr.begin(); it != arr.end(); ++it)
	{
		map.insert(std::make_pair<int, int>(hash(*it), 1));
	}
	int x_max=0;
	int y_max=0;
	for (iterator it = arr.begin(); it != arr.end(); ++it)
	{
		if (it->first > x_max)
			x_max = it->first;
		if (it->second > y_max)
			y_max = it->second;
	}
	std::cout << "xmax : " << x_max << "   ymax : " << y_max << std::endl;
	char grid[40][40];
	for (size_t i = 0; i < 40; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			grid[i][j] = '.';
		}
	}
	for (iterator i = arr.begin(); i != arr.end(); ++i)
	{
		grid[i->second][i->first] = '#';
	}

	for (size_t i = 0; i < 40; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}


	
	
	std::cout << "total dots : " << map.size() << std::endl;
	
}