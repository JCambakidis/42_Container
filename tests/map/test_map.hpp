#ifndef TEST_MAP_HPP
# define TEST_MAP_HPP

#include <map>
#include "../../srcs/Map/Map.hpp"

template <class Map>
void show_map_infos(Map &map, std::ofstream &file)
{
	file << "size: " << map.size() << " | begin:" << map.begin()->first << " | end:" << map.end()->first << std::endl;
	for(typename Map::iterator it = map.begin(); it != map.end(); ++it)
	{
		std::cout << it->first << " " << it->second << "\n";
	}
	file << "size: " << map.size() << " | begin:" << map.begin()->first << " | end:" << map.end()->first << std::endl;
	
}

#endif