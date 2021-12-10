#include "settings.hpp"


int main(void)
{
	FILE *file;
	int ret = 0;
	int n;
	long long int count;
	long long int days[9];
	long long int temp[9];
	int total_days = 256;
	for (size_t i = 0; i < 9; i++)
	{
		days[i] = 0;
	}
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,",&n);
		if (ret == EOF)
			break;
		days[n] += 1;
	}
	for (size_t i = 0; i < total_days; i++)
	{
		temp[0] = days[1];
		temp[1] = days[2];
		temp[2] = days[3];
		temp[3] = days[4];
		temp[4] = days[5];
		temp[5] = days[6];
		temp[6] = days[7] + days[0];
		temp[7] = days[8];
		temp[8] = days[0];
		for (size_t j = 0; j < 9; j++)
		{
			days[j] = temp[j];
		}
		
	}
	count = 0;
	for (size_t i = 0; i < 9; i++)
	{
		count += days[i];
	}
	std::cout << "day : "<< total_days << " :" << count << std::endl;
	return (0);
}
























