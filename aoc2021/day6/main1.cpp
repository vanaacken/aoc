#include "settings.hpp"

class LanternFish
{
private:
	int _internal_timer;
	int _days;
public:
	LanternFish();
	LanternFish(int n);
	~LanternFish();
	bool createnew();
	int getdays();
};

LanternFish::LanternFish():_internal_timer(7),_days(8)
{
}
LanternFish::LanternFish(int n):_internal_timer(7),_days(n)
{
}

LanternFish::~LanternFish()
{}

bool LanternFish::createnew()
{
	this->_days--;
	if (_days < 0)
	{
		this->_days = 6;
		return true;
	}
	return false;
}

int LanternFish::getdays()
{
	return _days;
}

std::vector<LanternFish> loop(std::vector<LanternFish> arr)
{
	std::vector<LanternFish> temp;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i].createnew() == true)
		{
			temp.push_back(LanternFish(8));
		}
		temp.push_back(LanternFish(arr[i].getdays()));
	}
	return temp;
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int n;
	file = fopen("resources", "read");
	std::vector<LanternFish> arr;
	while (ret != EOF)
	{
		ret = fscanf(file, "%d,",&n);
		if (ret == EOF)
			break;
		arr.push_back(LanternFish(n));
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i].getdays() << " ";
	}
	std::cout << std::endl;
	std::vector<LanternFish> arr1;
	std::vector<LanternFish> arr2;
	std::vector<LanternFish> arr3;
	std::vector<LanternFish> arr4;
	std::vector<LanternFish> arr5;
	int check = 0;
	for (size_t i = 0; i < 256; i++)
	{
		if (arr.size() % 4 == 0 && check == 0)
		{
			for (size_t j = 0; j < arr.size() / 4; j++)
			{
				arr1.push_back(arr[j]);
				arr2.push_back(arr[j + arr.size()/4 ]);
				arr3.push_back(arr[j + arr.size()/2]);
				arr4.push_back(arr[j + arr.size()/2 + arr.size()/4]);
				// arr.erase();
			}
			check = 4;	
		}
		// else if (arr.size() % 5 == 0 && check == 0)
		// {
		// 	for (size_t j = 0; j < arr.size() / 5; j++)
		// 	{
		// 		int fifth = arr.size()/5;
		// 		arr1.push_back(arr[j]);
		// 		arr2.push_back(arr[j + fifth ]);
		// 		arr3.push_back(arr[j + fifth + fifth]);
		// 		arr4.push_back(arr[j + fifth + fifth + fifth]);
		// 		arr5.push_back(arr[j + fifth + fifth + fifth + fifth]);
		// 		// arr.erase();
		// 	}
		// 	check = 5;	
		// }
		else if (arr.size() % 3 == 0 && check == 0)
		{
			for (size_t j = 0; j < arr.size() / 3; j++)
			{
				arr1.push_back(arr[j]);
				arr2.push_back(arr[j + arr.size()/3 ]);
				arr3.push_back(arr[j + arr.size()/3 + arr.size() /3]);
				// arr.erase();
			}
			check = 3;	
		}
		if (check != 0)
		{
			if (i >= 170)
			{
				std::cout << "day: " << i << std::endl;
			}
			arr1 = loop(arr1);
			arr2 = loop(arr2);
			arr3 = loop(arr3);
			arr4 = loop(arr4);
			arr5 = loop(arr5);
		}
		else
			arr = loop(arr);
		
		// std::cout << "day " << i << ": ";
		// for (size_t j = 0; j < arr.size(); j++)
		// {
		// 	if (j > 0)
		// 		std::cout << ", ";
		// 	std::cout << arr[j].getdays();
		// }
		// std::cout << std::endl;
		
	}
	std::cout << "n2 fish: " << arr1.size() + arr2.size() + arr3.size() + arr4.size();

	
	return (0);
}
























