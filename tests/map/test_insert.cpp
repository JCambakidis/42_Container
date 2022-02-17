#include "test_map.hpp"

template < class Key, class T >
void	test_map_insert_value_type(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_value_type *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		Key my_idx = rand() % (count);
		T my_value = rand() % (count * 20);
 		my_map.insert(ft::make_pair(my_idx, my_value));
 		show_map_infos(my_map, my_file);
 	}
	// Vector test
	file << std::endl << "************* test_map_insert_value_type *************" << std::endl << std::endl;
	srand(seed);
 	for (size_t i = 0; i < count; i++)
 	{
 		Key idx = rand() % (count);
		T value = rand() % (count * 20);
 		map.insert(std::make_pair(idx, value));
 		show_map_infos(map, file);
 	}
}

template < class Key, class T >
void	test_map_insert_position(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_position *************" << std::endl << std::endl;
	srand(seed);
	typename ft::map<Key, T>::iterator my_it = my_map.begin();
 	for (size_t i = 0; i < count / 2; i++)
 	{
 		Key my_idx = rand() % (count * 10);
		T my_value = rand() % (count * 20);
 		my_map.insert(my_it, ft::make_pair(my_idx, my_value));
 		show_map_infos(my_map, my_file);
 	}
	// Vector test
	file << std::endl << "************* test_map_insert_position *************" << std::endl << std::endl;
	srand(seed);
	typename std::map<Key, T>::iterator it = map.begin();
 	for (size_t i = 0; i < count / 2; i++)
 	{
 		Key idx = rand() % (count * 10);
 		T value = rand() % (count * 20);
 		map.insert(it, std::make_pair(idx, value));
 		show_map_infos(map, file);
 	}
}

template < class Key, class T >
void	test_map_insert_first_last(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed)
{
	// My vector test
	my_file << std::endl << "************* test_map_insert_first_last *************" << std::endl << std::endl;
	srand(seed);
	typename ft::map<Key, T>::iterator my_it_1 = map.find(count / 3);
	typename ft::map<Key, T>::iterator my_it_2 = map.find(count / 2);
 	for (size_t i = 0; i < count; i++)
 	{
 		my_map.insert(my_it_1, my_it_2);
 		show_map_infos(my_map, my_file);
 	}
	// Vector test
	file << std::endl << "************* test_map_insert_first_last *************" << std::endl << std::endl;
	srand(seed);
	typename std::map<Key, T>::iterator it_1 = map.find(count / 3);
	typename std::map<Key, T>::iterator it_2 = map.find(count / 2);
 	for (size_t i = 0; i < count; i++)
 	{
 		map.insert(it_1, it_2);
 		show_map_infos(map, file);
 	}
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
	//test_map_insert_first_last(my_map, map, my_file, file, count, seed);
}