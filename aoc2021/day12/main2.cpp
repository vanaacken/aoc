#include "settings.hpp"



int main(void)
{
	FILE *file;
	int ret = 0;
	long long int answer = 0;
	int count = 0;
	int n[4];
	char str[150];
	file = fopen("resources", "read");

	// while (ret != EOF)
	// {
	// 	ret = fscanf(file, "%s", str);
	// 	if (ret == EOF)
	// 		break;
	// 		arr.push_back(str);
		
	// }
	for (size_t i = 0; i < 100; i++)
	{
		std::cout << "Index : " << i << std::endl;
		std::cout << "x     : " << i%10 << std::endl;
		std::cout << "y     : " << i/10 << std::endl << std::endl;
	}
	
	
	std::cout << "answer     : " << answer << std::endl;	
	return (0);
}
























