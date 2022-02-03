#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void test_vector_push_back(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{

	// My vector test
	my_file << "____________________________________________________________" << std::endl;
 	my_file << "_________________________Push Back__________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	my_file << std::endl << "************* test_vector_push_back *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		const int idx = rand() % count;
 		my_vect.push_back(f<T>(idx));
 		my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;
 	}
	
	// Vector test
	file << "____________________________________________________________" << std::endl;
 	file << "_________________________Push Back__________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_push_back *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		const int idx = rand() % count;
 		vect.push_back(f<T>(idx));
 		file << "size: " << vect.size() << " | capacity:" << vect.capacity() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;
 	}
}