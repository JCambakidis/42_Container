#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void test_vector_pop_back(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{

	// My vector test
	my_file << "____________________________________________________________" << std::endl;
 	my_file << "__________________________Pop Back__________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	my_file << std::endl << "************* test_vector_pop_back *************" << std::endl << std::endl;
	if (my_vect.size() > 0)
	{
 		my_vect.pop_back();
 		my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;
	}
	else
 		my_file << "Vector empty" << std::endl;
	
	// Vector test
	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Pop Back__________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_pop_back *************" << std::endl << std::endl;
	if (vect.size() > 0)
	{
 		vect.pop_back();
 		file << "size: " << vect.size() << " | capacity:" << vect.capacity() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;
	}
	else
 		file << "Vector empty" << std::endl;
}