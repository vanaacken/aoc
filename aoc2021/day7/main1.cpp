#include "settings.hpp"


int getmax(std::vector<int> arr)
{
	int n;
	n = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] > n)
			n = arr[i];
	}
	return n;
}

int getmin(std::vector<int> arr)
{
	int n;
	n = INT_MAX;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i] < n)
			n = arr[i];
	}
	return n;
}

int loop(int min, int max, std::vector<int> arr)
{
	int move_cost;
	move_cost = INT_MAX;
	for (size_t j = min; j < max; j++)
	{
		int diff = 0;
		for (size_t i = 0; i < arr.size(); i++)
		{
			// int extra = 0;
			int n = j - arr[i];
			if (n < 0)
				n = -n;
			diff += n;
			// for (size_t x = 1; x < n; x++)
			// {
			// 	diff += x;
			// }
			// if (j == 5)
			// 	std::cout << "diff : " << diff << std::endl;
		}
		if (diff < move_cost)
			move_cost = diff;
	}
	// std::cout << "move_cost: " << move_cost << std::endl;
	return move_cost;
	
}

int main(void)
{
	FILE *file;
	int ret = 0;
	int n;
	file = fopen("resources", "read");
	std::vector<int> input_arr;
	std::vector<int> move_cost;
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,",&n);
		if (ret == EOF)
			break;
		input_arr.push_back(n);
	}
		std::cout << "input : ";
	for (size_t i = 0; i < input_arr.size(); i++)
	{
		std::cout << input_arr[i] << " ";
	}
	std::cout << std::endl;
	
	int max;
	int min;
	max = getmax(input_arr);
	min = getmin(input_arr);
	std::cout << "max : " << max << std::endl; 
	std::cout << "min : " << min << std::endl; 
	int answer = loop(min, max, input_arr);
	std::cout << "answer : " << answer << std::endl;	
	return (0);
}
























