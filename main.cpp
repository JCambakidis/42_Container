#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <typeinfo>
#include <cxxabi.h>
#include <sys/stat.h>
#include "./srcs/Vector/Vector.hpp"
#include "./srcs/Stack/Stack.hpp"
#include "./tests/vector/test_vector.hpp"
#include "./tests/map/test_map.hpp"
#include "./srcs/Map/RBTree.hpp"
#include "./srcs/Map/Map.hpp"

template <class T>
void test_vector(int seed, std::ofstream &my_file, std::ofstream &file)
{
 	size_t count = 10;
	ft::vector<T> my_vector_T;
	std::vector<T> vector_T;
	int status;

	my_file << "############################################################" << std::endl;
	my_file << "############################################################" << std::endl;
	my_file << "############################  "<< abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "  #########################" << std::endl;
	my_file << "############################################################" << std::endl;
	my_file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################ "<< abi::__cxa_demangle(typeid(T).name(), 0, 0, &status) << "  #########################" << std::endl;
	file << "############################################################" << std::endl;
	file << "############################################################" << std::endl;
	
	test_vector_pop_back(my_vector_T, vector_T, my_file, file);
	test_vector_push_back(my_vector_T, vector_T, my_file, file, count, seed);
	test_vector_pop_back(my_vector_T, vector_T, my_file, file);

	my_file << "____________________________________________________________" << std::endl;
	my_file << "_________________________Max Size___________________________" << std::endl;
	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "_________________________Max Size___________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	my_file << "max_size:" << my_vector_T.max_size() << std::endl;
	file << "max_size:" << vector_T.max_size() << std::endl;

	test_vector_elements_access(my_vector_T, vector_T, my_file, file);
	test_vector_resize(my_vector_T, vector_T, my_file, file);
	test_vector_insert(my_vector_T, vector_T, my_file, file);
	test_vector_clear(my_vector_T, vector_T, my_file, file);
	test_vector_push_back(my_vector_T, vector_T, my_file, file, count, seed);
	test_vector_assign(my_vector_T, vector_T, my_file, file);
	test_vector_push_back(my_vector_T, vector_T, my_file, file, count, seed);
	test_vector_erase(my_vector_T, vector_T, my_file, file);
	test_vector_swap(my_vector_T, vector_T, my_file, file);

	my_file << "____________________________________________________________" << std::endl;
	my_file << "_______________________Get Allocator________________________" << std::endl;
	my_file << "____________________________________________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	file << "_______________________Get Allocator________________________" << std::endl;
	file << "____________________________________________________________" << std::endl;
	my_file << "get_allocator max_size:" << my_vector_T.get_allocator().max_size() << std::endl;
	file << "get_allocator max_size:" << vector_T.get_allocator().max_size() << std::endl;

	test_vector_operator_overload(my_vector_T, vector_T, my_file, file);

	my_file << std::endl;
}

int main(int argc, char const *argv[])
{
	int seed;
	if (argc == 2)
		seed = atoi(argv[1]);
	else
		seed = 4;
	std::ofstream	my_file_vector;
	std::ofstream	file_vector;
	
	mkdir("./result", 0777);
	mkdir("./result/vector", 0777);
	my_file_vector.open("./result/vector/MyVector.txt");
	file_vector.open("result/vector/RealVector.txt");
	test_vector<char>(seed, my_file_vector, file_vector);
	test_vector<int>(seed, my_file_vector, file_vector);
	test_vector<std::string>(seed, my_file_vector, file_vector);

	std::ofstream	my_file_map;
	std::ofstream	file_map;
	mkdir("./result/map", 0777);
	my_file_map.open("result/map/MyMap.txt");
	file_map.open("result/map/RealMap.txt");

	std::map<const int, int> map;
	ft::map<const int, int> my_map;

	srand(seed);
 	for (size_t i = 0; i < 10; i++)
 	{
		const int first = rand() % 10;
		int second = rand() % (10 + 5);
		// p = std::pair<const int, int>(first, second);
		// my_p = ft::pair<const int, int>(first, second);
		//std::cout << &my_p << std::endl;
		map.insert(std::make_pair(first, second));
		my_map.insert(ft::make_pair(first, second));
 	}
	print_tree(my_map.get_tree()->getRoot());
	//show_map_infos(map, file_map);
	std::cout << "________________________-" << std::endl;
	show_map_infos(my_map, my_file_map);
	std::cout << "map size :" << map.end()->second << std::endl;
	std::cout << "my_map size :" << my_map.end()->second << std::endl;
	//my_map.clear();
	return 0;
}

/*#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include <map.hpp>
	#include <stack.hpp>
	#include "./srcs/Vector/Vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public ft::stack<T>
{
	public:
		MutantStack() {}
		MutantStack(const MutantStack<T>& src) { *this = src; }
		MutantStack<T>& operator=(const MutantStack<T>& rhs) 
		{
			this->c = rhs.c;
			return *this;
		}
		~MutantStack() {}

		typedef typename ft::stack<T>::container_type::iterator iterator;

		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }
};

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);

	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;
	ft::stack<int> stack_int;
	ft::vector<Buffer> vector_buffer;
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
	ft::map<int, int> map_int;

	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
	}

	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
	
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;

	{
		ft::map<int, int> copy = map_int;
	}
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
	return (0);
}*/