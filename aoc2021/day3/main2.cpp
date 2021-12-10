#include "settings.hpp"
// int binaryToDecimal(int n)
// {
//     int num = n;
//     int dec_value = 0;
 
//     // Initializing base value to 1, i.e 2^0
//     int base = 1;
 
//     int temp = num;
//     while (temp) {
//         int last_digit = temp % 10;
//         temp = temp / 10;
 
//         dec_value += last_digit * base;
 
//         base = base * 2;
//     }
 
//     return dec_value;
// }








std::vector<std::string> checker(std::vector<std::string> arr, int pos, int c)
{
	std::vector<std::string> temp;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i][pos] == c)
		{
			temp.push_back(arr[i]);
		}
	}
	if (temp.size() == 0)
	{
		return (arr);
	}
	return temp;
}

int checkLeastCommon(std::vector<std::string> arr, int index)
{
	int count = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if(arr[i][index] == '1')
		{
			count++;
		}
	}
	if (count < arr.size()/2 + arr.size()%2)
		return (1);
	return (0);	
}

int checkMostCommon(std::vector<std::string> arr, int index)
{
	int count = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if(arr[i][index] == '1')
		{
			count++;
		}
	}
	if (count >= arr.size()/2 + arr.size()%2)
		return (1);
	return (0);	
}

std::vector<std::string> loopLeast(std::vector<std::string> arr, int index)
{
	std::vector<std::string> temp;
	
	if (checkLeastCommon(arr, index) == 1)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			if(arr[i][index] == '1')
			{
				temp.push_back(arr[i]);
			}
		}	
	}
	else
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			if(arr[i][index] == '0')
			{
				temp.push_back(arr[i]);
			}
		}	
	}
	if (temp.size() == 0)
	{
		return (arr);
	}
	return temp;
}


std::vector<std::string> loopMost(std::vector<std::string> arr, int index)
{
	std::vector<std::string> temp;
	
	if (checkMostCommon(arr, index) == 1)
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			if(arr[i][index] == '1')
			{
				temp.push_back(arr[i]);
			}
		}	
	}
	else
	{
		for (size_t i = 0; i < arr.size(); i++)
		{
			if(arr[i][index] == '0')
			{
				temp.push_back(arr[i]);
			}
		}	
	}
	if (temp.size() == 0)
	{
		return (arr);
	}
	return temp;
}



int main(void)
{
	FILE *file;
	std::vector<std::string> arr;
	std::vector<std::string> oxy;
	std::vector<std::string> co2;
	int pos[12];
	char str[12];
	int n;
	file = fopen("resources", "read");
	while (fscanf(file, "%s\n",str) != EOF)
	{
		arr.push_back(str);
	}
	fclose(file);
	oxy = arr;
	co2 = arr;
	for (size_t i = 0; i < 12; i++)
	{
		oxy = loopMost(oxy, i);
		co2 = loopLeast(co2, i);
	}
	

















	std::cout << "oxy len: " << oxy.size() << std::endl;
	std::cout << "first element: " << oxy[0] << std::endl;
	std::cout << "co2 len: " << co2.size() << std::endl;
	std::cout << "first element: " << co2[0] << std::endl;

	int oxy_int = 0;
	int co2_int = 0;

	int b = 1;
	for (int i = 11; i >= 0; i--)
	{

		if (oxy[0][i] == '1')
		{
			oxy_int += b;
		}
		if (co2[0][i] == '1')
		{
			co2_int += b;
		}
		b *= 2;

	}
	std::cout << "oxy_int " << oxy_int << std::endl;
	std::cout << "co2_int  : " << co2_int << std::endl;
	std::cout << "multi: " << oxy_int * co2_int << std::endl;
	return (0);
}
























