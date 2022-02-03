#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void	test_vector_clear(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
 	my_file << "____________________________________________________________" << std::endl;
 	my_file << "__________________________Clear_____________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	my_file << std::endl << "************* test_vector_clear *************" << std::endl << std::endl;
 	my_vect.clear();
 	my_file << "is empty ?:" << my_vect.empty() << std::endl;
 	my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << std::endl; 
	 
	// Vector test
 	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Clear_____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_clear *************" << std::endl << std::endl;
 	vect.clear();
 	file << "is empty ?:" << vect.empty() << std::endl;
 	file << "size: " << vect.size() << " | capacity:" << vect.capacity() << std::endl; 
}