#include "settings.hpp"
#define LARGE 1
#define SMALL 2
#define START 3
#define END 4
int one_small = 0;
int total_paths = 0;
typedef std::vector< std::pair<std::string,std::string> > path_vector;
typedef std::pair<std::string,std::string> path_pair;


// class Cavern
// {
// private:
// 	std::vector<Cavern> connect;
// 	bool visited;
// 	int type;
// 	std::string name;
// public:
// 	Cavern(std::string name);
// 	~Cavern();
// };

// Cavern::Cavern(std::string n):name(n)
// {
// 	if (islower(n[0]))
// 		type = SMALL;
// 	else
// 		type = LARGE;
// }

// Cavern::~Cavern()
// {
// }


void split(std::string str, std::string *split1, std::string *split2)
{
	int i = str.find_first_of("-");
	*split1 = str.substr(0,i);
	*split2 = str.substr(i + 1, str.size() - i);


}

path_vector remover(path_vector conn)
{
	path_vector ret;
	for (size_t i = 0; i < conn.size(); i++)
	{
		if (conn[i].first.compare("end") == 0)
			continue;
		if (conn[i].second.compare("start") == 0)
			continue;
		ret.push_back(conn[i]);
	}
	return ret;
} 
void print(path_vector p)
{
	std::cout << "Path : ";
	for (size_t i = 0; i < p.size(); i++)
	{
		std::cout << p[i].first << " - " << p[i].second << " | "; 
	}
	std::cout << std::endl;
}


path_vector getVectorCave(path_vector arr, std::string start)
{
	path_vector ret;
	for (size_t i = 0; i < arr.size(); i++)
	{
		if (arr[i].first.compare(start) == 0)
			ret.push_back(arr[i]);
	}
	return ret;
}

int checkSmall(path_vector path, path_pair conn)
{
	int count = 0;
	for (size_t i = 1; i < path.size(); i++)
	{
		int count2 = 0;
		if (path[i].second.compare("end") && islower(path[i].second[0]))
		{
			// std::cout << "checking : " << path[i].second << std::endl;
			for (size_t j = 0; j < i; j++)
			{
				if (path[i].second.compare(path[j].second) == 0)
				{
					// std::cout << "---> " << path[j].second;	
					count2++;
				}
			}
			// std::cout << "  count2 :" << count2 << std::endl;
		}
		if (count2 > 1)
			return (0);
		if (count2 == 1)
			count++;
	}
	// std::cout << "count : " << count << std::endl;
	if (count < 2)
		return (1);
	return (0);

}

int countSmall(path_vector path)
{

	
	int count = 0;

	for (path_vector::iterator i = path.begin(); i != path.end(); ++i)
	{
		if (i->second.compare("end") && islower(i->second[0]))
			count++;
	}
	return count;
}



void loop(path_vector path, path_vector arr)
{
	path_vector options;
	if (path.empty())
	{
		options = getVectorCave(arr, "start");
	}
	else if (path[path.size() - 1].second.compare("end") == 0)
	{
		int count = countSmall(path);
		std::cout << "start";
		for (size_t i = 0; i < path.size(); i++)
		{
			std::cout << " - " << path[i].second;
		}
		std::cout << "   Count : " << count;
		std::cout << std::endl;
		total_paths++;
		return ;
	}
	else
	{
		options = getVectorCave(arr, path[path.size()-1].second);
	}
	if (options.size() == 0)
		return;
	for (size_t i = 0; i < options.size() ; i++)
	{
		path_vector next = path;
		if (checkSmall(next, options[i]))
		{
			next.push_back(options[i]);
			loop(next, arr);
		}
	}
	
}

int main(void)
{
	FILE *file;
	int ret = 0;
	int answer = 0;
	int count = 0;
	int n;
	char s1[6];

	std::string split1;
	std::string split2;
	std::string str;
	file = fopen("resources", "read");
	std::vector< std::pair<std::string,std::string> > conn;
	while (ret != EOF)
	{
		ret = fscanf(file, "%s\n", s1);
		if (ret == EOF)
			break;
		str = s1;
		split(str, &split1, &split2);
		conn.push_back(std::make_pair<std::string, std::string>(split1, split2));
	}
	// std::vector<Cavern> arr;
	size_t len = conn.size();
	for (size_t i = 0; i < len; i++)
	{
		conn.push_back(std::make_pair(conn[i].second, conn[i].first));
	}
	conn = remover(conn);
	for (size_t i = 0; i < conn.size(); i++)
	{
		std::cout << conn[i].first << "-" << conn[i].second << std::endl;
	}
	path_vector path;
	loop(path, conn);
	std::cout << "small cave once visited : " << one_small << std::endl;
	std::cout << "total paths : " << total_paths << std::endl;
}