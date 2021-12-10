#include "settings.hpp"


int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int n;
	file = fopen("resources", "read");
	std::vector<int> arr;

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
		if (i % 100 == 0)
		{
			std::cout << "<" << std::endl;
			std::cout << ">";
		}
		std::cout << arr[i] << " "; 
	}
	



	for (size_t i = 0; i < arr.size(); i++)
	{
		if (i < 100)
		{
			if (i % 100 == 0)
			{
				if (arr[i] < arr[i + 100]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
			else if (i % 100 == 99)
			{
				if (arr[i] < arr[i + 100]
					&& arr[i] < arr[i-1])
				answer += 1 + arr[i];
			}
			else
			{
				if (arr[i] < arr[i + 100]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
		}
		else if (i >= arr.size() - 100)
		{
			if (i % 100 == 0)
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
			else if (i % 100 == 99)
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i-1])
				answer += 1 + arr[i];
			}
			else
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
		}
		else
		{
			if (i % 100 == 0)
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i+100]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
			else if (i % 100 == 99)
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i+100]
					&& arr[i] < arr[i-1])
				answer += 1 + arr[i];
			}
			else
			{
				if (arr[i] < arr[i - 100]
					&& arr[i] < arr[i+100]
					&& arr[i] < arr[i-1]
					&& arr[i] < arr[i+1])
				answer += 1 + arr[i];
			}
		}
	}
	
	std::cout << std::endl;

	
	std::cout << "answer : " << answer << std::endl;	
	return (0);
}
























