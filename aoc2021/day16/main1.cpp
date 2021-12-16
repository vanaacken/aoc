#include "settings.hpp"
#include "Packet.hpp"
/*
3 bits version
3 bits ID
ID 4 literal value
ID 0 next 15 bits Total length in bits
ID 1 next 11 bits number of sub-packets contained
	after the subpacket is revealed
*/

int answer = 0;

std::string converter(std::string str)
{
	std::string ret = "";
	for (size_t i = 0; i < str.size(); i++)
	{
		switch (str[i])
		{
			case '0':
				ret.append("0000");
				break;
			case '1':
				ret.append("0001");
				break;
			case '2':
				ret.append("0010");
				break;
			case '3':
				ret.append("0011");
				break;
			case '4':
				ret.append("0100");
				break;
			case '5':
				ret.append("0101");
				break;
			case '6':
				ret.append("0110");
				break;
			case '7':
				ret.append("0111");
				break;
			case '8':
				ret.append("1000");
				break;
			case '9':
				ret.append("1001");
				break;
			case 'A':
				ret.append("1010");
				break;
			case 'B':
				ret.append("1011");
				break;
			case 'C':
				ret.append("1100");
				break;
			case 'D':
				ret.append("1101");
				break;
			case 'E':
				ret.append("1110");
				break;
			case 'F':
				ret.append("1111");
				break;
			default:
				break;
		}
	}
	return ret;
}

int getVersion(std::string str, int start)
{
	int ret = 0;
	if (str[start + 0] == '1')
		ret += 4;
	if (str[start + 1] == '1')
		ret += 2;
	if (str[start + 2] == '1')
		ret += 1;
	return ret;
}


int getType(std::string str, int start)
{
	int ret = 0;
	if (str[start + 3] == '1')
		ret += 4;
	if (str[start + 4] == '1')
		ret += 2;
	if (str[start + 5] == '1')
		ret += 1;
	return ret;
}


int getIdLen(std::string str, int start)
{
	if (str[start + 6] == '1')
		return (1);
	return 0;
}


int	parsePacket(std::string str, int start)
{
	int total_len = 6;
	int version;
	int id_type;
	int id_len;

	version = getVersion(str, start);
	std::cout << "version : " << version << std::endl;
	answer += version;
	id_type = getType(str, start);
	std::cout << "id_type : " << id_type << std::endl;
	int sub_len = 0;
	std::cout << "Whole : " << str << std::endl;
	std::cout << "Start : " << str.substr(0,6) << std::endl;
	if (id_type == 4)
	{
		std::cout << "part  :       " << str.substr(6) << std::endl;
		// std::cout << "part2 :            " << str.substr(11,5) << std::endl;
		// std::cout << "part3 :                 " << str.substr(16,5) << std::endl;
		// std::cout << "part4 :                      " << str.substr(21,5) << std::endl;
		while (sub_len + 5 < str.size())
		{
			std::string tmp = str.substr(6 + sub_len, 5);
			std::cout << "sub_len : " << sub_len << std::endl;
			std::cout << "part    : " << str.substr(6 + sub_len,5) << std::endl;
			if (tmp[0] == '0')
			{	
				total_len += 6 + sub_len + sub_len%4;
				std::cout << "total_len : " << total_len << std::endl;
				return (total_len);
			}
			
			sub_len += 5;
		}
		sub_len += 5;
		exit(1);
	}
	else
	{
		id_len = getIdLen(str, start);
		if (id_len == 1)
		{
			
		}
		if (id_len == 0)
		{

		}
	}
	return total_len;

}


std::vector<std::string> parser(std::string str)
{
	int start = 0;
	std::vector<std::string> arr;
	while (start < str.size())
	{
		int len = parsePacket(str, start);
		arr.push_back(str.substr(start, len));
		start = len;
	}
	return arr;
}


int main(void)
{
	FILE *file;
	int ret = 0;
	int count = 0;
	int set = 1;
	int n;
	char s[2];
	std::vector<int> arr;
	std::string str;
	file = fopen("resources", "read");
	while (ret != EOF)
	{
		ret = fscanf(file, "%1s", s);
		if (ret == EOF)
			break;
		if (ret == 0)
			break;
		str.append(s);
	}
	std::vector<std::string> packets;

	std::string conv = converter(str);
	packets = parser(conv);
	std::cout << "Converted : " << conv << std::endl;
	std::cout << "String    : " << str << std::endl;

	


	
	std::cout << "answer : " << answer << std::endl;
	
}