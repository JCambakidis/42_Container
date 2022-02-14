#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <fstream>
#include "../../srcs/Vector/Vector.hpp"
#include "test_vector.hpp"


template <class T>
void	test_vector_operator_overload_equal(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_equal *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect == my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect == my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect == my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
		
	// Vector test
	file << std::endl << "************* test_vector_operator_overload_equal *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect == vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect == vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect == vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_operator_overload_not_equal(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_not_equal *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect != my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect != my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect != my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_operator_overload_not_equal *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect != vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect != vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect != vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_operator_overload_inf(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_inf *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect < my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect < my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect < my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_operator_overload_inf *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect < vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect < vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect < vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_operator_overload_inf_equal(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_inf_equal *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect <= my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect <= my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect <= my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_operator_overload_inf_equal *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect <= vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect <= vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect <= vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_operator_overload_sup(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_sup *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect > my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect > my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect > my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_operator_overload_sup *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect > vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect > vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect > vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_operator_overload_sup_equal(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_operator_overload_sup_equal *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 100));
	ft::vector<T> my_vect3;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));

	my_file << "same" << std::endl;
	if (my_vect >= my_vect)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;
	
	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect >= my_vect2)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	my_file << std::endl;
	my_file << "diff:" << std::endl;
	if (my_vect >= my_vect3)
		my_file << "true" << std::endl;
	else
		my_file << "false" << std::endl;

	// Vector test
	file << std::endl << "************* test_vector_operator_overload_sup_equal *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 100));
	std::vector<T> vect3;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));

	file << "same" << std::endl;
	if (vect >= vect)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
	
	file << std::endl;
	file << "diff:" << std::endl;
	if (vect >= vect2)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;

	file << std::endl;
	file << "diff:" << std::endl;
	if (vect >= vect3)
		file << "true" << std::endl;
	else
		file << "false" << std::endl;
}

template <class T>
void	test_vector_external_function_swap(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_external_function_swap *************" << std::endl << std::endl;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 10; i++)
		my_vect2.push_back(f<T>(i * 100));
	swap(my_vect, my_vect2);
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
	file << std::endl << "************* test_vector_external_function_swap *************" << std::endl << std::endl;
	std::vector<T> vect2;
	for (size_t i = 0; i < 10; i++)
		vect2.push_back(f<T>(i * 100));
	swap(vect, vect2);
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


template <class T>
void	test_vector_operator_overload(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	my_file << "____________________________________________________________" << std::endl;
	my_file << "___________________Operators Overload_______________________" << std::endl;
	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "___________________Operators Overload_______________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	test_vector_operator_overload_equal(my_vect, vect, my_file, file);
	test_vector_operator_overload_not_equal(my_vect, vect, my_file, file);
	test_vector_operator_overload_inf(my_vect, vect, my_file, file);
	test_vector_operator_overload_inf_equal(my_vect, vect, my_file, file);
	test_vector_operator_overload_sup(my_vect, vect, my_file, file);
	test_vector_operator_overload_sup_equal(my_vect, vect, my_file, file);
	test_vector_external_function_swap(my_vect, vect, my_file, file);
}