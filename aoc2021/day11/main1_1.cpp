#include "settings.hpp"

int n_flash = 0;

typedef struct s_Point
{
	int x;
	int y;
	int index;
}				Point;

class Jelly
{
private:
	int _value;
	bool _flashed;
	int _index;
	Point	_point;
	std::vector<Point> _neighbours;

public:
	Jelly(int value, int index);
	void inc();
	void reset();
	std::vector<Point> flash();
	int getValue();
};

Jelly::Jelly(int value, int index):_value(value),_index(index), _flashed(false)
{
	_point.x = _index % 10;
	_point.y = _index / 10;
	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			if (x == 0 && y == 0
				|| _point.x + x < 0
				|| _point.x + x > 9
				|| _point.y + y < 0
				|| _point.y + y > 9)
			continue;
			else
			{
				Point tmp;
				tmp.x = _point.x + x;
				tmp.y = _point.y + y;
				tmp.index = tmp.y * 10 + tmp.x;
				_neighbours.push_back(tmp);
			}
		}
	}
}

void Jelly::inc()
{
	if (_flashed == false)
		_value++;
}

void Jelly::reset()
{
	_flashed = false;
}


std::vector<Point> Jelly::flash()
{
	if (_value > 9 && _flashed == false)
	{
		_flashed = true;
		n_flash++;
		_value = 0;
		return (_neighbours);
	}
	std::vector<Point> tmp;
	return tmp;
}




int Jelly::getValue()
{
	return _value;
}



 void print(std::vector<Jelly> arr)
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			if (arr[i * 10 + j].getValue() == 0)
				std::cout << RED_BOLD << arr[i * 10 + j].getValue() << RESET_COLOR;
			else if (arr[i * 10 + j].getValue() == -1)
				std::cout << RED_BOLD << 0 << RESET_COLOR;
			else
				std::cout << arr[i * 10 + j].getValue();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	
}

int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int n;
	file = fopen("resources", "read");
	std::vector<Jelly> arr;
	int index = 0;
	while (ret != EOF)
	{
		ret = fscanf(file, "%1d", &n);
		if (ret == EOF)
			break;
		arr.push_back(Jelly(n, index));
		index++;
	}
	print(arr);

	for (size_t i = 0; i < 50000; i++)
	{
		for (size_t i1 = 0; i1 < 100; i1++)
		{
			arr[i1].inc();
		}
		for (size_t i2 = 0; i2 < 100; i2++)
		{

			std::vector<Point> ret = arr[i2].flash();
			if (ret.empty())
			{
				continue;
			}
			for (size_t f = 0; f < ret.size(); f++)
			{
				arr[ret[f].index].inc();
				i2 = -1;
			}
		}
		for (size_t i3 = 0; i3 < 100; i3++)
		{
			arr[i3].reset();
		}
		for (size_t i4 = 0; i4 < 100; i4++)
		{
			if (arr[i4].getValue() > 0)
				break;
			if (i4 == 99)
			{
				std::cout << "index i : " << i << std::endl;
				print(arr);
				exit(0);
			}
		}
				print(arr);
		
	}
	




		std::cout << "n_flash : " << n_flash << std::endl;	
}