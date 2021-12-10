#include "settings.hpp"




int main(void)
{
	FILE *file;
	std::vector<std::string> arr;

	file = fopen("resources", "read");
	while (fscanf(file, "%s\n",str) != EOF)
	{
		arr.push_back(str);
	}
	fclose(file);

	return (0);
}
























