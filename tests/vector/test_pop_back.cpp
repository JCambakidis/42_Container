#include "test_vector.hpp"

template <class T>
void test_vector_pop_back(ft::vector<T> &my_vect, std::vector<T> &vect, std::ofstream &my_file, std::ofstream &file)
{

	// My vector test
	my_file << "____________________________________________________________" << std::endl;
 	my_file << "__________________________Pop Back__________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
	my_file << std::endl << "************* test_vector_pop_back *************" << std::endl << std::endl;
	if (my_vect.size() > 0)
	{
 		my_vect.pop_back();
 		show_vector_infos(my_vect, my_file);
	}
	else
 		my_file << "Vector empty" << std::endl;
	
	// Vector test
	file << "____________________________________________________________" << std::endl;
 	file << "__________________________Pop Back__________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
	file << std::endl << "************* test_vector_pop_back *************" << std::endl << std::endl;
	if (vect.size() > 0)
	{
 		vect.pop_back();
 		show_vector_infos(vect, file);
	}
	else
 		file << "Vector empty" << std::endl;
}