#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"

template <class T>
void	test_vector_swap(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_swap *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));
	my_vect.swap(my_vect2);
	my_file << "Vect 1" << std::endl;
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;
	my_file << "Vect 2" << std::endl;
	for (size_t i = 0; i < my_vect2.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect2[i] << std::endl;
	}
	my_file << "size: " << my_vect2.size() << " | capacity:" << my_vect2.capacity() << " | front:" << my_vect2.front() << " | back:" << my_vect2.back() << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_swap *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));
	vect.swap(vect2);
	file << "Vect 1" << std::endl;
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	file << "size: " << vect.size() << " | capacity:" << vect.capacity() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;
	file << "Vect 2" << std::endl;
	for (size_t i = 0; i < vect2.size(); i++)
	{
		file << "index:" << i << " | value:" << vect2[i] << std::endl;
	}
	file << "size: " << vect2.size() << " | capacity:" << vect2.capacity() << " | front:" << vect2.front() << " | back:" << vect2.back() << std::endl;

}