#include "settings.hpp"
#define NONE 0
#define LEFT 1
#define RIGHT 2
#define TOP 3
#define BOT 4
int line_size = 100;


int findUp(std::vector<int> arr, int i)
{
	if (i < line_size )
	{
		return (i);
	}
	else
	{
		if (arr[i - line_size] < 9)
			return (i - line_size);
	}
	return (i);

}

int findDown(std::vector<int> arr, int i)
{
	if (i >= arr.size() - line_size)
	{
		return (i);
	}
	else
	{
		if (arr[i + line_size] < 9)
			return (i + line_size);
	}
	return (i);
}

int findLeft(std::vector<int> arr, int i)
{
	if (i % line_size == 0)
	{
		return (i);
	}
	else
	{
		if (arr[i - 1] < 9)
			return (i - 1);
	}
	return (i);
}

int findRight(std::vector<int> arr, int i)
{
	if (i % line_size == line_size - 1)
	{
		return (i);
	}
	else
	{
		if (arr[i + 1] < 9)
			return (i + 1);
	}
	return (i);
}

void printMap(std::map<int,int> m)
{
	typedef std::map<int,int>::iterator it;
	std::cout << "map indexes: : ";
	for (it i = m.begin(); i != m.end(); ++i)
	{
		if (i != m.begin())
		{
			std::cout << ", ";
		}
		std::cout << i->first;
	}
	std::cout << std::endl;
	
}

int findBasin(std::vector<int> arr, int i)
{
	std::map<int,int> map;
	map.clear();
	typedef std::map<int,int>::iterator it;
	map.insert(std::make_pair(i, 1));
	bool check = true;
	int size = map.size();
	std::cout << "i: " << i << std::endl;
	while(check == true)
	{
		for (it i = map.begin(); i != map.end(); ++i)
		{
			map.insert(std::make_pair(findDown(arr, i->first), 1));
			map.insert(std::make_pair(findUp(arr, i->first), 1));
			map.insert(std::make_pair(findLeft(arr, i->first), 1));
			map.insert(std::make_pair(findRight(arr, i->first), 1));

		}
		if (map.size() == size)
			check = false;
		// printMap(map);
		size = map.size();
	}
	return (size);
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int n;
	file = fopen("resources", "read");
	std::vector<int> arr;
	std::vector<int> low_index;
	std::vector<int> basins;
	while (ret != EOF)
	{
		ret = fscanf(file, "%1d", &n);
		if (ret == EOF)
			break;
			arr.push_back(n);
		
	}

	std::cout << "blurb:" << std::endl;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i % line_size == 0)
		{
			std::cout << "<" << std::endl;
			std::cout << ">";
		}
		std::cout << arr[i] << " "; 
	}
	



	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i < line_size)
		{
			if (i % line_size == 0)
			{
				if (arr[i] < arr[i + line_size]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
			else if (i % line_size == line_size - 1)
			{
				if (arr[i] < arr[i + line_size]
					&& arr[i] < arr[i-1])
				low_index.push_back(i);
			}
			else
			{
				if (arr[i] < arr[i + line_size]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
		}
		else if (i >= arr.size() - line_size)
		{
			if (i % line_size == 0)
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
			else if (i % line_size == line_size - 1)
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i-1])
				low_index.push_back(i);
			}
			else
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
		}
		else
		{
			if (i % line_size == 0)
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i+line_size]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
			else if (i % line_size == line_size - 1)
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i+line_size]
					&& arr[i] < arr[i-1])
				low_index.push_back(i);
			}
			else
			{
				if (arr[i] < arr[i - line_size]
					&& arr[i] < arr[i+line_size]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				low_index.push_back(i);
			}
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "low point arr:" << std::endl;
	for (size_t i = 0; i < low_index.size(); i++)
	{
		std::cout << "i : " << low_index[i] << std::endl;
		basins.push_back(findBasin(arr, low_index[i]));
	}
	
	std::sort(basins.begin(), basins.end());
	int size1 = basins[basins.size() - 1];
	int size2 = basins[basins.size() - 2];
	int size3 = basins[basins.size() - 3];
	std::cout << "size 1 : " << size1 << std::endl;
	std::cout << "size 2 : " << size2 << std::endl;
	std::cout << "size 3 : " << size3 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	
	
	std::cout << "answer : " << answer << std::endl;	
	std::cout << "answer : " << size1 * size2 * size3 << std::endl;	
	return (0);
}
























