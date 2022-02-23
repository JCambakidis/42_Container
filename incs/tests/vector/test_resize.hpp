#ifndef TEST_VECTOR_RESIZE_HPP
# define TEST_VECTOR_RESIZE_HPP

#include "test_vector.hpp"

template <class Vector>
void	test_vector_resize(Vector &vect, std::ofstream &file)
{
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
 	vect.resize(20, f<typename Vector::value_type>(5));
 	file << "resize 20 - 5" << std::endl;
 	for (size_t i = 0; i < vect.size(); i++)
 	{
 		file << "index:" << i << " | value:" << vect[i] << std::endl;
 	}
 	show_vector_infos(vect, file);
}

#endif