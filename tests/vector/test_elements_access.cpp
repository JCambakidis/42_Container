#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void test_vector_elements_access(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
 	my_file << "____________________________________________________________" << std::endl;
 	my_file << "______________________Elements Access_______________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
 	my_file << "index 3 -> operator[]:" << my_vect[3] << std::endl;	
 	try
 	{
 		my_file << "index 15 -> at:" << my_vect.at(15) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		my_file << e.what() << '\n';
 	}
 	try
 	{
 		my_file << "index 4 -> at:" << my_vect.at(4) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		my_file << e.what() << '\n';
 	}

	// Vector test
 	file << "____________________________________________________________" << std::endl;
 	file << "______________________Elements Access_______________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
 	file << "index 3 -> operator[]:" << vect[3] << std::endl;	
 	try
 	{
 		file << "index 15 -> at:" << vect.at(15) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		file << e.what() << '\n';
 	}
 	try
 	{
 		file << "index 4 -> at:" << vect.at(4) << std::endl;
 	}
 	catch(const std::exception& e)
 	{
 		file << e.what() << '\n';
 	}
}