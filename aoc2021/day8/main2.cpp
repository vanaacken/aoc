#include "settings.hpp"


/*

2 - 5
3 - 5
5 - 5

0 - 6
6 - 6
9 - 6

1 - 2

7 - 3

4 - 4

8 - 7

*/

// typedef struct s_signal
// {
// 	bool	A;
// 	bool	B;
// 	bool	C;
// 	bool	D;
// 	bool	E;
// 	bool	F;
// 	bool	G;
// }			t_signal;



/*
how to find
	A
	B
		4 - 1 - d gives b
	C
	D FIRST
		8 - 4 gives d
	E
	F
	G
		










	0
		- missing d found above

	1 GIVEN
		given by 2 digits
	2


	3
		if 7 is in there then it is 3 otherwise


	4 GIVEN


	5
		find all from 5 are found in 6 otherwise it is 2


	6
		see 9 but otherway

	7 GIVEN


	8 GIVEN


	9
		after 0 then other 2 with 6 digits if all of 7 is there then it is 9



*/


class line
{
private:
	std::vector<std::string> _hints;
	std::vector<std::string> _solve;
	std::vector<std::pair< std::string, int> > _value;
	char A;
	char B;
	char C;
	char D;
	char E;
	char F;
	char G;
	std::string ZERO;
	std::string ONE;
	std::string TWO;
	std::string THREE;
	std::string FOUR;
	std::string FIVE;
	std::string SIX;
	std::string SEVEN;
	std::string EIGHT;
	std::string NINE;
	int _answer;



public:
	line(std::vector<std::string> hints, std::vector<std::string> solve);
	void solver();
	void prep();
	int get();
};

line::line(std::vector<std::string> hints, std::vector<std::string> solve)
{
	_hints = hints;
	_solve = solve;
	_answer = 0;
	prep();
	solver();
}


void line::prep()
{
	for (size_t i = 0; i < _hints.size(); i++)
	{
		int len = _hints[i].size(); 
		switch (len)
		{
		case 2:
			_value.push_back(std::make_pair<std::string, int>(_hints[i], 1));
			ONE = _hints[i];
			break;
		case 3:
			_value.push_back(std::make_pair<std::string, int>(_hints[i], 7));
			SEVEN = _hints[i];
			break;
		case 4:
			_value.push_back(std::make_pair<std::string, int>(_hints[i], 4));
			FOUR = _hints[i];
			break;
		case 7:
			_value.push_back(std::make_pair<std::string, int>(_hints[i], 8));
			EIGHT = _hints[i];
			break;
		default:
			_value.push_back(std::make_pair<std::string, int>(_hints[i], -1));
			break;
		}
	}

}


void line::solver()
{
// find a

// find 3 and 6
	for (size_t i = 0; i < _hints.size(); i++)
	{
		int len = _hints[i].size(); 
		switch (len)
		{
		case 5:
			if (_hints[i].find_first_of(ONE[0]) != std::string::npos && _hints[i].find_first_of(ONE[1]) != std::string::npos)
			{
				THREE = _hints[i];
			}
		break ;
		case 6:
			if (ONE.find_first_not_of(_hints[i].c_str()) != std::string::npos)
			{
				SIX = _hints[i];
			}
			else if (FOUR.find_first_not_of(_hints[i].c_str()) != std::string::npos)
			{
				ZERO = _hints[i];
			}
			else
			{
				NINE = _hints[i];
			}
		default:
			break;
		}
	}
	
// missing  2 5
	for (size_t i = 0; i < _hints.size(); i++)
	{
		int len = _hints[i].size(); 
		if (_hints[i] == THREE)
			len = 0;
		switch (len)
		{
		case 5:
			if (_hints[i].find_first_not_of(NINE.c_str()) != std::string::npos)
			{
				TWO = _hints[i];
			}
		default:
			break;
		}
	}


	for (size_t i = 0; i < _hints.size(); i++)
	{
		int len = _hints[i].size(); 
		if (_hints[i] == THREE || _hints[i] == TWO)
			len = 0;
		switch (len)
		{
		case 5:
				FIVE = _hints[i];
		default:
			break;
		}
	}

std::cout << ZERO << ": 0" << std::endl;
std::cout << ONE << ": 1" << std::endl;
std::cout << TWO << ": 2" << std::endl;
std::cout << THREE << ": 3" << std::endl;
std::cout << FOUR << ": 4" << std::endl;
std::cout << FIVE << ": 5" << std::endl;
std::cout << SIX << ": 6" << std::endl;
std::cout << SEVEN << ": 7" << std::endl;
std::cout << EIGHT << ": 8" << std::endl;
std::cout << NINE << ": 9" << std::endl;

	int factor = 1000;
for (size_t i = 0; i < _solve.size(); i++)
{
	int len = _solve[i].size();
	int tmp = 0;
	switch (len)
	{
	case 2:
		_answer += factor * 1;
		tmp = 1;
		break;
	case 3:
		_answer += factor * 7;
		tmp = 7;
		break;
	case 4:
		_answer += factor * 4;
		tmp = 4;
		break;
	case 5:
		if (_solve[i].find_first_not_of(TWO.c_str()) == std::string::npos)
		{
			tmp = 2;
			_answer += factor * 2;
		}
		else if(_solve[i].find_first_not_of(THREE.c_str()) == std::string::npos)
		{
			tmp = 3;
			_answer += factor * 3;
		}
		else if(_solve[i].find_first_not_of(FIVE.c_str()) == std::string::npos)
		{
			tmp = 5;
			_answer += factor * 5;
		}
		break;

	case 6:
		if(_solve[i].find_first_not_of(SIX.c_str()) == std::string::npos)
		{
			tmp = 6;
			_answer += factor * 6;
		}
		else if(_solve[i].find_first_not_of(NINE.c_str()) == std::string::npos)
		{
			tmp = 9;
			_answer += factor * 9;
		}
		else if (_solve[i].find_first_not_of(ZERO.c_str()) == std::string::npos)
		{
			tmp = 0;
			_answer += factor * 0;
		}
		break;
	case 7:
		tmp = 8;
		_answer += factor * 8;
		break;
	default:
		break;
	}
	std::cout << "number " << i + 1 << " : " << tmp << std::endl;
	std::cout << "string : " << _solve[i] << std::endl;
	std::cout << "answer: " << _answer << std::endl;


	factor /= 10;
}
	std::cout << "   answer: " << _answer << std::endl;

}


int line::get()
{
	return _answer;
}




int main(void)
{
	FILE *file;
	int ret = 0;
	int n;
	char s0[8];
	char s1[8];
	char s2[8];
	char s3[8];
	char s4[8];
	char s5[8];
	char s6[8];
	char s7[8];
	char s8[8];
	char s9[8];
	char str1[8];
	char str2[8];
	char str3[8];
	char str4[8];
	int answer = 0;
	int count = 0;
	file = fopen("resources", "read");
	std::vector<std::string> arr1;
	std::vector<std::string> arr2;
	std::vector<line> arr;
	while (ret != EOF)
	{
		arr1.clear();
		arr2.clear();
		ret = fscanf(file, "%s %s %s %s %s %s %s %s %s %s | %s %s %s %s ",\
		s0, s1, s2, s3, s4, s5, s6, s7, s8, s9,\
		str1, str2, str3 ,str4);
		if (ret == EOF)
			break;
		arr2.push_back(s0);
		arr2.push_back(s1);
		arr2.push_back(s2);
		arr2.push_back(s3);
		arr2.push_back(s4);
		arr2.push_back(s5);
		arr2.push_back(s6);
		arr2.push_back(s7);
		arr2.push_back(s8);
		arr2.push_back(s9);
		arr1.push_back(str1);
		arr1.push_back(str2);
		arr1.push_back(str3);
		arr1.push_back(str4);
		arr.push_back(line(arr2, arr1));
	}
	for (size_t i = 0; i < arr.size(); i++)
	{
	answer += arr[i].get();
		/* code */
	}
	
	// for (size_t i = 0; i < arr1.size(); i++)
	// {
	// 	if (arr1[i].size() == 2 || arr1[i].size() == 3 || arr1[i].size() == 4 || arr1[i].size() == 7)
	// 	{
	// 		answer++;
	// 	}
	// }
	// std::cout << "answer : " << answer;

	// std::cout << std::endl;
	
	


	
	std::cout << "answer : " << answer << std::endl;	
	return (0);
}
























