#include "test_map.hpp"



template < class Key, class T >
void	test_map_insert_value_type(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_value_type *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		const int idx = rand() % count;
 		my_map.insert(pair<Key, T>(idx));
 		my_file << "size: " << my_vect.size() << " | capacity:" << my_vect.capacity() << " | front:" << my_vect.front() << " | back:" << my_vect.back() << std::endl;
 	}
	// Vector test
	file << std::endl << "************* test_map_insert_value_type *************" << std::endl << std::endl;

}

template < class Key, class T >
void	test_map_insert_position(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_position *************" << std::endl << std::endl;
	// Vector test
	file << std::endl << "************* test_map_insert_position *************" << std::endl << std::endl;

}

template < class Key, class T >
void	test_map_insert_first_last(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_first_last *************" << std::endl << std::endl;
	// Vector test
	file << std::endl << "************* test_map_insert_first_last *************" << std::endl << std::endl;
}

template < class Key, class T >
void	test_map_insert(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{

 	my_file << "____________________________________________________________" << std::endl;
 	my_file << "___________________________Insert___________________________" << std::endl;
 	my_file << "____________________________________________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;
 	file << "___________________________Insert___________________________" << std::endl;
 	file << "____________________________________________________________" << std::endl;

	test_map_insert_value_type(my_map, map, my_file, file, count, seed);
	test_map_insert_position(my_map, map, my_file, file, count, seed);
	test_map_insert_first_last(my_map, map, my_file, file, count, seed);
}