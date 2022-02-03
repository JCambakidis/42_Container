#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void	test_vector_assign_nv(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_assign_nv *************" << std::endl << std::endl;
 	my_vect.assign((size_t)15, f<T>(8));
 	for (size_t i = 0; i < my_vect.size(); i++)
 	{
 		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
 	}
 	my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_assign_nv *************" << std::endl << std::endl;
 	vect.assign((size_t)15, f<T>(8));
 	for (size_t i = 0; i < vect.size(); i++)
 	{
 		file << "index:" << i << " | value:" << vect[i] << std::endl;
 	}
 	file << "size: " << vect.size() << " | capacity:" << vect.capacity() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;
}

template <class T>
void	test_vector_assign_fl(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_assign_fl *************" << std::endl << std::endl;
	vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));
	my_vect.assign(my_vect2.begin(), my_vect2.end());
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_assign_fl *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));
	vect.assign(vect2.begin(), vect2.end());
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	file << "size: " << vect.size() << " | capacity:" << vect.capacity() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;

}

template <class T>
void	test_vector_assign(vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	my_file << "____________________________________________________________" << std::endl;
 	my_file << "__________________________Assign____________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Assign____________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;

	test_vector_assign_nv(my_vect, vect, my_file, file);
	test_vector_assign_fl(my_vect, vect, my_file, file);
}