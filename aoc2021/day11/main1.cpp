#include "settings.hpp"

int n_flash = 0;



// std::vector<int> inc(std::vector<int> arr)
// {
// 	std::vector<int> next;
// 	next = arr;
// 	for (size_t i = 0; i < 100; i++)
// 	{
// 		next[i] +=1;
// 		if (next[i] > 9)
// 		{
// 			next[i] = -1;
// 			n_flash++;
// 		}
// 	}
// 	return next;
// }

// int top(std::vector<int> arr, int i)
// {
// 	int n = 0;
// 	if (i < 10)
// 	{
// 		return 0;
// 	}
// 	if (i % 10 > 0 && arr[i - (10 + 1)] == -1)
// 	{
// 		n++;
// 	}
// 	if (i % 10 < 10 - 1 && arr[i - (10 - 1)] == -1)
// 	{
// 		n++;
// 	}
// 	if (arr[i - 10] == -1){
// 		n++;
// 	}
// 	return (n);
// }

// int side(std::vector<int> arr, int i)
// {
// 	int n = 0;
// 	if (i % 10 > 0 && arr[i - 1] == -1)
// 	{
// 		n++;
// 	}
// 	if (i % 10 < 10 - 1 && arr[i + 1] == -1)
// 	{
// 		n++;
// 	}
// 	return (n);
// }

// int bot(std::vector<int> arr, int i)
// {
// 	int n = 0;
// 	if (i >= 100 - 10){
// 		return (0);
// 	}
// 	if (i % 10 > 0 && arr[i + (10 - 1)] == -1){
// 		n++;
// 	}
// 	if (i % 10 < 10 -1 && arr[i + (10 + 1)] == -1){
// 		n++;
// 	}
// 	if (arr[i + 10] == -1)
// 	{
// 		n++;
// 	}
// 	return (n);
// }







// std::vector<int> incTop(std::vector<int> arr, int i)
// {
// 	if (i < 10)
// 	{
// 		return arr;
// 	}
// 	if (i % 10 > 0 && arr[i - (10 + 1)] != -1)
// 	{
// 		arr[i - (10 + 1)] += 1;
// 	}
// 	if (i % 10 < 10 - 1 && arr[i - (10 - 1)] != -1)
// 	{
// 		arr[i - (10 - 1)] += 1;
// 	}
// 	arr[i - 10] += 1;
// 	return (arr);
// }

// std::vector<int> incSide(std::vector<int> arr, int i)
// {
// 	if (i % 10 > 0 && arr[i - 1] != -1) 
// 	{
// 		arr[i - 1] += 1;
// 	}
// 	if (i % 10 < 10 - 1 && arr[i + 1] != -1)
// 	{
// 		arr[i + 1] += 1;
// 	}
// 	return (arr);
// }

// std::vector<int> incBot(std::vector<int> arr, int i)
// {
// 	if (i >= 100 - 10){
// 		return (arr);
// 	}
// 	if (i % 10 > 0 && arr[i + (10 - 1)] != -1){
// 		arr[i + (10 - 1)] += 1;
// 	}
// 	if (i % 10 < 10 -1 && arr[i + (10 + 1)] != -1){
// 		arr[i + (10 + 1)] += 1;
// 	}
// 	arr[i + 10] += 1;
// 	return (arr);
// }






// std::vector<int> lights(std::vector<int> arr)
// {
// 	std::vector<int> next;
// 	next = arr;
// 	for (size_t i = 0; i < 100; i++)
// 	{
// 		if (arr[i] == -1)
// 		{
// 			next = incTop(arr, i);
// 			next = incBot(arr, i);
// 			next = incSide(arr, i);
// 		}
// 		else
// 		{
// 			next[i] += top(arr, i) + bot(arr, i) + side(arr, i);

// 		}
// 		if (arr[i] > 9)
// 		{
// 			arr[i] = -1;
// 			next = incTop(arr, i);
// 			next = incBot(arr, i);
// 			next = incSide(arr, i);

// 			n_flash++;
// 		}
// 	}
// 	return (next);
// }


// std::vector<int> reset(std::vector<int> arr)
// {
// 	for (size_t i = 0; i < 100; i++)
// 	{
// 		if (arr[i] == -1)
// 			arr[i] = 0;
// 	}
// 	return arr;
	
// }

// void print(std::vector<int> arr)
// {
// 	for (size_t i = 0; i < 10; i++)
// 	{
// 		for (size_t j = 0; j < 10; j++)
// 		{
// 			if (arr[i * 10 + j] == 0)
// 				std::cout << RED_BOLD << arr[i * 10 + j] << RESET_COLOR;
// 			else if (arr[i * 10 + j] == -1)
// 				std::cout << RED_BOLD << 0 << RESET_COLOR;
// 			else
// 				std::cout << arr[i * 10 + j];
		
// 		}
// 		std::cout << std::endl;
		
// 	}
// 	std::cout << std::endl;
	
// }

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

	for (size_t i = 0; i < 3; i++)
	{
		arr = inc(arr);
		std::vector<int> next;
		// std::cout << "----------START-------------" << std::endl;
		while (true)
		{

			next = lights(arr);
			if (next == arr)
				break;

			arr = next;
		}
		// std::cout << "----------END-----------" << std::endl;
		arr = reset(arr);
		std::cout << "n_flash : " << n_flash << std::endl;	
		print(arr);
	}
	


	
	
	std::cout << "n_flash : " << n_flash << std::endl;	
	return (0);
}
























