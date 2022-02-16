#include "test_vector.hpp"

template <class T>
void	test_vector_erase_p(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_erase_p *************" << std::endl << std::endl;
	typename ft::vector<T>::iterator my_it = my_vect.begin() + 2;
	my_vect.erase(my_it);
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	show_vector_infos(my_vect, my_file);

	// Vector test
	file << std::endl << "************* test_vector_erase_p *************" << std::endl << std::endl;
	typename std::vector<T>::iterator it = vect.begin() + 2;
	vect.erase(it);
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	show_vector_infos(vect, file);
}

template <class T>
void	test_vector_erase_fl(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
	my_file << std::endl << "************* test_vector_erase_fl *************" << std::endl << std::endl;
	my_vect.erase(my_vect.begin() + 1, my_vect.begin() + 3);
	for (size_t i = 0; i < my_vect.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
	}
	show_vector_infos(my_vect, my_file);

	// Vector test
	file << std::endl << "************* test_vector_erase_fl *************" << std::endl << std::endl;
	vect.erase(vect.begin() + 1, vect.begin() + 3);
	for (size_t i = 0; i < vect.size(); i++)
	{
		file << "index:" << i << " | value:" << vect[i] << std::endl;
	}
	show_vector_infos(vect, file);
}

template <class T>
void	test_vector_erase(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	my_file << "____________________________________________________________" << std::endl;
	my_file << "__________________________Erase_____________________________" << std::endl;
	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "__________________________Erase_____________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;

	test_vector_erase_p(my_vect, vect, my_file, file);
	test_vector_erase_fl(my_vect, vect, my_file, file);
}