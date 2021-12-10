#pragma once




class Number
{
private:
	int _value;
	bool _marked;
public:
	Number(int n);
	Number();
	void print();
	void markNumber(int n);
	int getFalseNum();
	bool getMark();
};


class Card
{
private:
	Number	_grid[5][5];
	int		_sum;
	int		_card_index;
	bool	_done;
public:
	Card(int input[5][5], int index);
	Card();
	void print();
	void checkNumber(int n);
	int	isBingo();
	int isHor(int y);
	int isVer(int x);
	int getSum();
};











