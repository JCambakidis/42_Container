#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <sys/stat.h>
#include "../incs/Vector/Vector.hpp"
#include "../incs/tests/vector/test_vector.hpp"
#include "../incs/Stack/Stack.hpp"
#include "../incs/tests/map/test_map.hpp"
#include "../incs/Map/Map.hpp"

int main(int argc, char** argv)
{
	std::ofstream	my_file_vector;
	std::ofstream	file_vector;
	std::ofstream	my_file_map;
	std::ofstream	file_map;
	int rand_value;
	int my_tests = -1;
	int tests_type = -1;
	
	mkdir("./result", 0777);
	mkdir("./result/vector", 0777);
	mkdir("./result/map", 0777);

	if(argc == 2)
		my_tests = atoi(argv[1]);
	if(argc == 3)
		tests_type = atoi(argv[2]);
		
	if (my_tests != 0)
	{
		if (tests_type != 0)
			my_file_vector.open("./result/vector/MyVector.txt");
		if (tests_type != 1)
			my_file_map.open("result/map/MyMap.txt");
	}
	if (my_tests != 1)
	{
		if (tests_type != 0)
			file_vector.open("result/vector/RealVector.txt");
		if (tests_type != 1)
			file_map.open("result/map/RealMap.txt");
	}

/**
 * TESTS VECTOR
 */
	if (tests_type != 0)
	{
		for (size_t seed = 0; seed < 200; seed++)
		{
			srand(seed);
			rand_value = rand() % 100;
			if (my_tests != 1)
				test_vector<std::vector<int> >(rand_value, seed, file_vector);
			if (my_tests != 0)
				test_vector<ft::vector<int> >(rand_value, seed, my_file_vector);
		}
	}

/**
 * TESTS MAP
 */
	if (tests_type != 1)
	{
		for (size_t seed = 0; seed < 50; seed++)
		{
			srand(seed);
			rand_value = rand() % 100;
			if (my_tests != 1)
				test_map<std::map<int, char> >(rand_value, seed, file_map);
			if (my_tests != 0)
				test_map<ft::map<int, char> >(rand_value, seed, my_file_map);
		}
	}
	
	return 0;
}