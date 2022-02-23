#ifndef TEST_VECTOR_VECTOR_HPP
# define TEST_VECTOR_VECTOR_HPP

#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <typeinfo>
#include <cxxabi.h>
#include "../../Vector/Vector.hpp"

template <class T>
T f(int n)
{
	(void)n;
	return T();
}

template <>
int f<int>(int n)
{
	return n;
}

template <>
std::string f<std::string>(int n)
{
	std::stringstream ss;
	ss << n;
	return ss.str();
}

template <>
char f<char>(int n)
{
	return n + '0';
}

template <class Vector>
void show_vector_infos(Vector &vect, std::ofstream &file)
{
	file << "size: " << vect.size() << " | front:" << vect.front() << " | back:" << vect.back() << std::endl;
}

#include "test_insert.hpp"
#include "test_push_back.hpp"
#include "test_pop_back.hpp"
#include "test_elements_access.hpp"
#include "test_resize.hpp"
#include "test_clear.hpp"
#include "test_assign.hpp"
#include "test_erase.hpp"
#include "test_swap.hpp"
#include "test_operator_overload.hpp"

template <class Vector>
void test_vector(size_t count, int seed, std::ofstream &file)
{
	Vector vector;
	int status;
	char *type = abi::__cxa_demangle(typeid(typename Vector::value_type).name(), 0, 0, &status);

	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################ "<< type << "  #########################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	
	test_vector_pop_back(vector, file);
	test_vector_push_back(vector, file, count, seed);
	test_vector_pop_back(vector, file);

	file << "____________________________________________________________" << std::endl;
	file << "_________________________Max Size___________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "max_size:" << vector.max_size() << std::endl;

	test_vector_elements_access(vector, file);
	test_vector_resize(vector, file);
	test_vector_insert(vector, file);
	test_vector_clear(vector, file);
	test_vector_push_back(vector, file, count, seed);
	test_vector_assign(vector, file);
	test_vector_push_back(vector, file, count, seed);
	test_vector_erase(vector, file);
	test_vector_swap(vector, file);

	file << "____________________________________________________________" << std::endl;
	file << "_______________________Get Allocator________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "get_allocator max_size:" << vector.get_allocator().max_size() << std::endl;

	test_vector_operator_overload(vector, file);
	delete type;
}

#endif