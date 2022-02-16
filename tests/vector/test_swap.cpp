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
	show_vector_infos(my_vect, my_file);
	my_file << "Vect 2" << std::endl;
	for (size_t i = 0; i < my_vect2.size(); i++)
	{
		my_file << "index:" << i << " | value:" << my_vect2[i] << std::endl;
	}
	show_vector_infos(my_vect2, my_file);

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
	show_vector_infos(vect, file);
	file << "Vect 2" << std::endl;
	for (size_t i = 0; i < vect2.size(); i++)
	{
		file << "index:" << i << " | value:" << vect2[i] << std::endl;
	}
	show_vector_infos(vect2, file);

}