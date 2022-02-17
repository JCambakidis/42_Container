#ifndef TEST_MAP_HPP
# define TEST_MAP_HPP

#include <map>
#include "../../srcs/Map/Map.hpp"


template <class Map>
void show_map_infos(Map &map, std::ofstream &file)
{
	for(typename Map::iterator it = map.begin(); it != map.end(); it++)
		file << "key:" << it->first << " | value:" << it->second << std::endl;
}
#include "test_insert.cpp"

template < class Key, class T >
void	test_map_insert(ft::map<Key, T> &my_map, std::map<Key, T> &map, std::ofstream &my_file, std::ofstream &file, size_t count, int seed);

#endif