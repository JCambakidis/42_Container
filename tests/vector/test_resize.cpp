#include "test_vector.hpp"

template <class T>
void	test_vector_resize(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{
	// My vector test
 	my_file << "____________________________________________________________" << std::endl;
 	my_file << "___________________________Resize___________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	my_file << std::endl << "************* test_vector_resize *************" << std::endl << std::endl;
 	my_vect.resize(3);
 	my_file << "resize 3" << std::endl;
 	for (size_t i = 0; i < my_vect.size(); i++)
 	{
 		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
 	}
 	show_vector_infos(my_vect, my_file);
 	my_vect.resize(18);
 	my_file << "resize 18" << std::endl;
 	for (size_t i = 0; i < my_vect.size(); i++)
 	{
 		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
 	}
 	show_vector_infos(my_vect, my_file);
 	my_vect.resize(20, f<T>(5));
 	my_file << "resize 20 - 5" << std::endl;
 	for (size_t i = 0; i < my_vect.size(); i++)
 	{
 		my_file << "index:" << i << " | value:" << my_vect[i] << std::endl;
 	}
 	show_vector_infos(my_vect, my_file);

	// Vector test
 	file << "____________________________________________________________" << std::endl;
 	file << "___________________________Resize___________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_resize *************" << std::endl << std::endl;
 	vect.resize(3);
 	file << "resize 3" << std::endl;
 	for (size_t i = 0; i < vect.size(); i++)
 	{
 		file << "index:" << i << " | value:" << vect[i] << std::endl;
 	}
 	show_vector_infos(vect, file);
 	vect.resize(18);
 	file << "resize 18" << std::endl;
 	for (size_t i = 0; i < vect.size(); i++)
 	{
 		file << "index:" << i << " | value:" << vect[i] << std::endl;
 	}
 	show_vector_infos(vect, file);
 	vect.resize(20, f<T>(5));
 	file << "resize 20 - 5" << std::endl;
 	for (size_t i = 0; i < vect.size(); i++)
 	{
 		file << "index:" << i << " | value:" << vect[i] << std::endl;
 	}
 	show_vector_infos(vect, file);
}