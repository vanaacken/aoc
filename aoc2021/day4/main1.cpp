#include "settings.hpp"
#include "extra.hpp"

// NUMBER FUNCTIONS
Number::Number(){}
Number::Number(int n):
_value(n),_marked(false){}

void Number::print()
{
	if (_marked == true)
	{
		std::cout << RED_BOLD << _value << " ";
	}
	else
	{
		std::cout << RESET_COLOR << _value << " ";
	}
}

void Number::markNumber(int n)
{
	if (_value == n)
	{
		_marked = true;
	}
}

int Number::getFalseNum()
{
	if (_marked == false)
		return _value;
	return 0;
}

bool Number::getMark()
{
	return _marked;
}

// CARD FUNCTIONS
Card::Card(int input[5][5], int index):_sum(0),_card_index(index),_done(false)
{

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			_grid[i][j] = Number(input[i][j]);
		}
	}
}

void Card::print()
{
	std::cout << BLUE_BOLD "BINGO CARD" RESET_COLOR << std::endl;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			_grid[i][j].print();
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Card::checkNumber(int n)
{
		for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			_grid[i][j].markNumber(n);
		}
	}
}

int Card::isBingo()
{
	if (_done == true)
		return (0);
	for (size_t i = 0; i < 5; i++)
	{
		if (isVer(i) == 5 || isHor(i) == 5)
		{
			_done = true;
			return (1);
		}
	}
	return (0);
}

int Card::isHor(int y)
{
	int count = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (_grid[y][i].getMark() == true)
		{
			count++;
		}
	}
	return (count);
}

int Card::isVer(int x)
{
		int count = 0;
	for (size_t i = 0; i < 5; i++)
	{
		if (_grid[i][x].getMark() == true)
		{
			count++;
		}
	}
	return (count);
}

int Card::getSum()
{
	_sum = 0;
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t j = 0; j < 5; j++)
		{
			_sum += _grid[i][j].getFalseNum();
		}
	}
	return _sum;
}

int main(void)
{
	FILE *file;
	std::vector<int> bingo;
	int n;
	char c;
	int ret = 0;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%d%c",&n, &c);
		bingo.push_back(n);
		std::cout << "n:" << n << " ";
		if (c == '\n')
		{
			std::cout << "\n\n";
			break;
		}
	}
	std::vector<Card> bingo_cards;
	int input[5][5];
	int index = 1;
	while(ret != EOF)
	{
		for (size_t i = 0; i < 5; i++)
		{
			for (size_t j = 0; j < 5; j++)
			{
				ret = fscanf(file, "%d", &input[i][j]);
			}
		}
		bingo_cards.push_back(Card(input,index));
		index++;
	}
	int checker = 0;
	for (size_t n = 0; n < bingo.size(); n++)
	{
		for (size_t i = 0; i < bingo_cards.size(); i++)
		{
			bingo_cards[i].checkNumber(bingo[n]);
			if(bingo_cards[i].isBingo())
			{
				std::cout << "sum   : " << bingo_cards[i].getSum() << std::endl;
				std::cout << "number: " << bingo[n] << std::endl;
				std::cout << "answer: " << bingo_cards[i].getSum() * bingo[n] << std::endl;;
			}
		}
	}

	// for (size_t i = 0; i < bingo_cards.size(); i++)
	// {
	// 	bingo_cards[i].print();
	// }
	



	return (0);
}
























