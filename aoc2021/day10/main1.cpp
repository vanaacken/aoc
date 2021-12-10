#include "settings.hpp"
#define OPEN1 '('
#define CLOSE1 ')'
#define OPEN2 '['
#define CLOSE2 ']'
#define OPEN3 '{'
#define CLOSE3 '}'
#define OPEN4 '<'
#define CLOSE4 '>'

// int findOpen(std::string str, int start);


// int findClose(std::string str, int start, char opener)
// {
	
// }

// int findOpen(std::string str, int start)
// {
// 	char open;
// 	char format;
// 	int ret;
// 	for (size_t i = start; i < str.size(); i++)
// 	{
// 		open = str[start];
// 		ret = findClose(str, start + 1, open);
// 		if (ret > 0)
// 			return (ret);
// 	}
// 	return (0);
// }


// int splitter(std::string str)
// {
// 	int start = 0;
// 	std::cout << "\n\nSTRING TO SPLIT len(" << str.size() <<  ")>|  " << str << "  |<" << std::endl;
// 	for (size_t i = 1; i < str.size(); i++)
// 	{
// 		if (str[i - 1] == OPEN1 && str[i] == CLOSE1
// 		|| str[i - 1] == OPEN2 && str[i] == CLOSE2
// 		|| str[i - 1] == OPEN3 && str[i] == CLOSE3
// 		|| str[i - 1] == OPEN4 && str[i] == CLOSE4)
// 		{
// 			std::string temp1 = str.substr(0, i-1);
// 			std::string temp2 = str.substr(i+1 , str.size() - i - 1);
// 			std::cout << "TMP1 len(" << temp1.size() <<  ")>|  " << temp1 << "  |<" << std::endl;
// 			std::cout << "TMP2 len(" << temp2.size() <<  ")>|  " << temp2 << "  |<" << std::endl;
// 			std::string newstr = temp1 + temp2;
// 			return (splitter(newstr));
// 		}	
		
// 	}
	


// 	return (0);
// }

// int counter(std::string str)
// {
// 	int count1 = 0;
// 	int count2 = 0;
// 	int count3 = 0;
// 	int count4 = 0;
// 	char last_open;

// 	for (size_t i = 0; i < str.size(); i++)
// 	{
// 		if (str[i] == OPEN1)
// 			count1++;
// 		else if (str[i] == OPEN2)	
// 			count2++;
// 		else if (str[i] == OPEN3)	
// 			count3++;
// 		else if (str[i] == OPEN4)	
// 			count4++;
// 		if (str[i] == CLOSE1)
// 			count1--;
// 		else if (str[i] == CLOSE2)
// 			count2--;
// 		else if (str[i] == CLOSE3)
// 			count3--;
// 		else if (str[i] == CLOSE4)
// 			count4--;
// 		// std::cout << "HUH?: " << str[i] << std::endl;
// 		if (str[i] == CLOSE1 || str[i] == CLOSE2 || str[i] == CLOSE3 || str[i] == CLOSE4)
// 		{
// 			int max = 0;
// 			if (count1 > max)
// 				max = count1;
// 			if (count2 > max)
// 				max = count2;
// 			if (count3 > max)
// 				max = count3;
// 			if (count4 > max)
// 				max = count4;
// 			std::string delim;
// 			delim.clear();
// 			if (count1 == 1 || str[i] == CLOSE1)
// 				delim += "(";
// 			if (count2 == 1 || str[i] == CLOSE2)
// 				delim += "[";
// 			if (count3 == 1 || str[i] == CLOSE3)
// 				delim += "{";
// 			if (count4 == 1|| str[i] == CLOSE4)
// 				delim += "<";
// 			if (delim.size() == 0)
// 				return (-1);
// 			std::string sub = str.substr(0, i);
// 			std::cout << "\n    index: " << i << std::endl;
// 			std::cout << "character: " << str[i] << std::endl;
// 			std::cout << "count 1 : " << count1 << std::endl;
// 			std::cout << "count 2 : " << count2 << std::endl;
// 			std::cout << "count 3 : " << count3 << std::endl;
// 			std::cout << "count 4 : " << count4 << std::endl;
// 			std::cout << "MAX     : " << max << std::endl;
// 			std::cout << "DELIM   : " << delim << std::endl;
// 			std::cout << "prev char : " << str[sub.find_last_of(delim)] << std::endl;
// 			if (max == 0)
// 				return (-1);


// 			if (str[i] == CLOSE1 && count1 < max && str[sub.find_last_of(delim)] != OPEN1)
// 				return (0);
// 			if (str[i] == CLOSE2 && count2 < max && str[sub.find_last_of(delim)] != OPEN2)
// 				return (1);
// 			if (str[i] == CLOSE3 && count3 < max && str[sub.find_last_of(delim)] != OPEN3)
// 				return (2);
// 			if (str[i] == CLOSE4 && count4 < max && str[sub.find_last_of(delim)] != OPEN4)
// 				return (3);
// 		}
// 	}

// 	return (-1);
// }


int finder(std::string str)
{
 	int count1 = 0;
	int count2 = 0;
	int count3 = 0;
	int count4 = 0;
	std::vector<char> open;
	char last_open;
	char closer = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == OPEN1)
		{
			open.push_back(str[i]);
			last_open = str[i];
			count1++;
		}
		else if (str[i] == OPEN2)
		{
			open.push_back(str[i]);
			last_open = str[i];
			count2++;
		}	
		else if (str[i] == OPEN3)	
		{
			open.push_back(str[i]);
			last_open = str[i];
			count3++;
		}
		else if (str[i] == OPEN4)
		{
			open.push_back(str[i]);
			last_open = str[i];
			count4++;
		}
		if (str[i] == CLOSE1)
		{
			closer = str[i];
			count1--;
			if (open[open.size() - 1] == OPEN1)
			{
				open.pop_back();
				last_open = open[open.size() - 1];

			}
			else
				return (0);
		}
		else if (str[i] == CLOSE2)
		{
			closer = str[i];
			count2--;
			if (open[open.size() - 1] == OPEN2)
			{
				open.pop_back();
				last_open = open[open.size() - 1];

			}
			else
				return (1);
		}
		else if (str[i] == CLOSE3)
		{
			count3--;
			closer = str[i];
			if (open[open.size() - 1] == OPEN3)
			{
				open.pop_back();
				last_open = open[open.size() - 1];

			}
			else
				return (2);
		}
		else if (str[i] == CLOSE4)
		{
			closer = str[i];
			count4--;
			if (open[open.size() - 1] == OPEN4)
			{
				open.pop_back();
			last_open = open[open.size() - 1];

			}
			else
				return (3);
		}
			std::cout << "\nindex : " << i << std::endl;
			std::cout << "count 1 : " << count1 << std::endl;
			std::cout << "count 2 : " << count2 << std::endl;
			std::cout << "count 3 : " << count3 << std::endl;
			std::cout << "count 4 : " << count4 << std::endl;
			std::cout << "closer    : " << closer << std::endl;
			std::cout << "last open : " << last_open << std::endl;
			std::cout << "open vec  : ";
			for (size_t i = 0; i < open.size(); i++)
			{
				std::cout << open[i] << " ";
			}
			std::cout << std::endl;
			
		if (closer == 0)
			continue;
		// if (count1 == 0 && last_open != OPEN1)
		// 	return (0);
		// if (count2 == 0 && last_open != OPEN2)
		// 	return (1);
		// if (count3 == 0 && last_open != OPEN3)
		// 	return (2);
		// if (count4 == 0 && last_open != OPEN4)
		// 	return (3);
	}
	return (-1);
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int n[4];
	char str[150];
	file = fopen("resources", "read");
	std::vector<std::string> arr;

	while (ret != EOF)
	{
		ret = fscanf(file, "%s", str);
		if (ret == EOF)
			break;
			arr.push_back(str);
		
	}

	std::cout << "blurb:" << std::endl;
	
	n[0] = 0;
	n[1] = 0;
	n[2] = 0;
	n[3] = 0;
	// ret = finder(arr[2]);
	// std::cout << "RET: " << ret << std::endl;
	
	for (size_t i = 0; i < arr.size(); i++)
	{
		// std::cout << arr[i] << std::endl;; 
		int ret = finder(arr[i]);
		std::cout << "RET: " << ret << std::endl;
		n[ret]++; 
	}
	answer = n[0] * 3 + n[1] * 57 + n[2] * 1197 + n[3] * 25137;


	
	std::cout << "answer : " << answer << std::endl;	
	return (0);
}
























