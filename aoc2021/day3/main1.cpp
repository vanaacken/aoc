#include "settings.hpp"
int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;
 
        dec_value += last_digit * base;
 
        base = base * 2;
    }
 
    return dec_value;
}

int main(void)
{
	FILE *file;
	std::vector<std::string> arr;
	int pos[12];
	int gamma  = 0;
	int eps = 0;
	char str[12];
	int n;
	file = fopen("resources", "read");
	
	while (fscanf(file, "%s\n",str) != EOF)
	{
		arr.push_back(str);
	}
	std::cout << "length : " << arr.size() << std::endl;
	for (size_t i = 0; i < 12; i++)
	{
		for (size_t j = 0; j < arr.size(); j++)
		{
			if (arr[j][i] == '1')
			{
				pos[i]++;;
			}
		}
		if (pos[i] >= arr.size()/2)
		{
			pos[i] = 1;
		}
		else
		{
			pos[i] = 0;
		}

	}
	int b = 1;
	for (int i = 11; i >= 0; i--)
	{
		std::cout << "check" << std::endl;

		if (pos[i] == 1)
		{
			gamma += b;
		}
		else
		{
			eps += b;
		}
		b *= 2;

	}
	std::cout << "gamma: " << gamma << std::endl;
	std::cout << "eps  : " << eps << std::endl;
	std::cout << "multi: " << gamma * eps << std::endl;
	return (0);
}
























