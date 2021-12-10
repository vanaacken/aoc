#include "settings.hpp"


/*
1 - 2

7 - 3

4 - 4

2 - 5
3 - 5
5 - 5

0 - 6
6 - 6
9 - 6


8 - 7

*/

typedef struct s_signal
{
	int		_value;
	bool	live;
}			t_signal;




int searcher(std::vector<std::string> arr, int n_digits)
{
	int count = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i].size() == n_digits)
		{
			count++;
		}
	}
	return count;
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int n;
	char str1[8];
	char str2[8];
	char str3[8];
	char str4[8];
	int answer = 0;
	int count = 0;
	file = fopen("resources", "read");
	std::vector<std::string> arr1;
	std::vector<std::string> arr2;

	while (ret != EOF)
	{
		ret = fscanf(file, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s | %s %s %s %s ", str1, str2, str3 ,str4);
		if (ret == EOF)
			break;
		arr1.push_back(str1);
		arr1.push_back(str2);
		arr1.push_back(str3);
		arr1.push_back(str4);
	}
	for (size_t i = 0; i < arr1.size(); i++)
	{
		if (arr1[i].size() == 2 || arr1[i].size() == 3 || arr1[i].size() == 4 || arr1[i].size() == 7)
		{
			answer++;
		}
	}
	std::cout << "answer : " << answer;

	std::cout << std::endl;
	
	


	
	std::cout << "answer : " << answer << std::endl;	
	return (0);
}
























