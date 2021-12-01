#include "settings.hpp"

int	main(void)
{
	FILE *file;
	std::vector<int> arr;
	int n, ret, count, count2 = 0;
	file = fopen("resources", "read");
	
	while (fscanf(file, "%d\n",&n) != EOF)
	{
		arr.push_back(n);
		count2++;
	}
	std::cout << "total in arr : " << count2 << std::endl;
	size_t len = arr.size();
	for (size_t i = 0; i < len-3; i++)
	{
		if (arr[i] + arr[i + 1] + arr[i +2] <= arr[i + 1] + arr[i + 2] + arr[i + 3])
		{
			count++;
		}
	}
	std::cout << "count : " << count << std::endl;
	return (0);
}
