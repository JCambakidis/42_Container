#include "test_vector.hpp"

template <class T>
void	test_vector_insert_pv(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_insert_pv *************" << std::endl << std::endl;
	typename ft::vector<T>::iterator my_it = my_vect.begin();
	my_vect.insert(my_it, f<T>(5));
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	show_vector_infos(my_vect, my_file);

	// Vector test
	file << std::endl << "************* test_vector_insert_pv *************" << std::endl << std::endl;
	typename std::vector<T>::iterator it = std::begin(vect);
	vect.insert(it, f<T>(5));
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	show_vector_infos(vect, file);
}

template <class T>
void	test_vector_insert_pnv(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_insert_pnv *************" << std::endl << std::endl;
	typename ft::vector<T>::iterator my_it = my_vect.begin() + 3;
	my_vect.insert(my_it, (size_t)30, f<T>(10));
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	show_vector_infos(my_vect, my_file);

	// Vector test
	file << std::endl << "************* test_vector_insert_pnv *************" << std::endl << std::endl;
	typename std::vector<T>::iterator it = std::begin(vect) + 3;
	vect.insert(it, (size_t)30, f<T>(10));
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	show_vector_infos(vect, file);
}

template <class T>
void	test_vector_insert_pfl(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_insert_pfl *************" << std::endl << std::endl;
	typename ft::vector<T>::iterator my_it = my_vect.begin() + 5;
	ft::vector<T> my_vect2;
	for (size_t i = 0; i < 5; i++)
		my_vect2.push_back(f<T>(i * 10));
	my_vect.insert(my_it, my_vect2.begin(), my_vect2.end());
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	show_vector_infos(my_vect, my_file);

	// Vector test
	file << std::endl << "************* test_vector_insert_pfl *************" << std::endl << std::endl;
	typename std::vector<T>::iterator it = vect.begin() + 5;
	std::vector<T> vect2;
	for (size_t i = 0; i < 5; i++)
		vect2.push_back(f<T>(i * 10));
	vect.insert(it, vect2.begin(), vect2.end());
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	show_vector_infos(vect, file);
}

template <class T>
void	test_vector_insert(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	my_file << "____________________________________________________________" << std::endl;
	my_file << "__________________________Insert____________________________" << std::endl;
	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "__________________________Insert____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	test_vector_insert_pv(my_vect, vect, my_file, file);
	test_vector_insert_pnv(my_vect, vect, my_file, file);
	test_vector_insert_pfl(my_vect, vect, my_file, file);
}