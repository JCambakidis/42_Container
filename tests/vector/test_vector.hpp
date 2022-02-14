#ifndef TEST_VECTOR_HPP
# define TEST_VECTOR_HPP

#include <stdlib.h>
#include <sstream>

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

#include "test_insert.cpp"
#include "test_push_back.cpp"
#include "test_pop_back.cpp"
#include "test_elements_access.cpp"
#include "test_resize.cpp"
#include "test_clear.cpp"
#include "test_assign.cpp"
#include "test_erase.cpp"
#include "test_swap.cpp"
#include "test_operator_overload.cpp"

template <class T>
void 	test_vector_push_back(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file, size_t count, int seed);

template <class T>
void	test_vector_pop_back(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void 	test_vector_elements_access(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_resize(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_clear(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_insert(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_assign(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_erase(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_swap(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

template <class T>
void	test_vector_operator_overload(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file);

#endif