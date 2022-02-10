#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <memory>
#include <algorithm>
#include "../Iterators/randomAccessIterator.hpp"
#include "../Iterators/randomAccessConstIterator.hpp"
#include "../Iterators/reverseIterator.hpp"
#include "../Iterators/reverseConstIterator.hpp"

/**
 * Vectors are sequence containers representing arrays that can change in size.
 * 
 * @tparam T - type of objects who can be use in this vector
 * @tparam A - allocator template of type "T" in standard library
 */

template <class T, class A = std::allocator<T> >
class vector
{

	public:

/**
 * 
 * Typedef
 * 
 */

	    typedef A allocator_type;
		typedef typename A::value_type value_type; 
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::pointer pointer;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;

		typedef reverseIterator<T, A> reverse_iterator;
   		typedef reverseConstIterator<T, A> const_reverse_iterator;
		typedef iterator<T, A> iterator;
		typedef const_iterator<T, A> const_iterator;

/**
 * 
 * Constructor
 * 
 */

	/**
	 * Create new empty vector with capacity 1.
	 * 
	 * @param alloc - reference to allocator
	 */
		explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_capacity = 1;
			_size = 0;
			_datas = _alloc.allocate(_capacity);
		}

	/**
	 * Create new vector with n capacity, completed by value.
	 * 
	 * @param n - size of new vector
	 * @param value - value of elements in new vector
	 * @param  alloc - reference to allocator
	 */
		explicit vector(size_t n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_capacity = n;
			_size = n;
			_datas = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_datas[i], value);
		}

	/**
	 * Create new vector with value between first and last, 
	 * the size of vector is the number of objects between first to last.
	 * This function use an input iterator.
	 * 
	 * @param first - starting iterator
	 * @param last - ending iterator
	 * @param alloc - reference to allocator
	 */
		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_size = 0;
			_capacity = 1;
			_datas = _alloc.allocate(_capacity);
			for ( ; first != last; first++)
				push_back(*first);
		}

	/**
	 * Create new vector with all attributes of instance reference.
	 * 
	 * @param instance - reference of an other vector
	 */
		vector(const vector &instance)
		{
			if (this != instance)
			{
				_capacity = instance._capacity;
				_alloc = instance._alloc;
				_size = instance._size;
				_datas = instance._datas;
			}
		}

	/**
	 * Assign all attributes of an vector to this vector object.
	 * 
	 * @param rhs - reference to an other vector
	 * @return reference of this
	 */
		vector &operator=(vector const &rhs)
		{
			if (this != rhs)
			{
				_capacity = rhs._capacity;
				_alloc = rhs._alloc;
				_size = rhs._size;
				_datas = rhs._datas;
			}
			return *this;
		}

	/**
	 * Destroy vector and clear all elements to deallocate memory.
	 */
		~vector(void)
		{
			clear();
		}

/**
 * 
 *	Iterators
 *
 */

	/**
	 * Get the first elements of vector's array.
	 * 
	 * @return address of the first element in vector's array
	 */
		iterator begin() {
			return iterator(&_datas[0]);
		}

	/**
	 * Get the first elements of vector's v in constant.
	 * 
	 * @return address of the first element in vector's v
	 */
		const_iterator begin() const {
			return const_iterator(&_datas[0]);
		}

	/**
	 * Get the last elements of vector's v.
	 * 
	 * @return address of the last element in vector's v
	 */
		iterator end() {
			return iterator(&_datas[_size]);
		}

	/**
	 * Get the last elements of vector's array in constant.
	 * 
	 * @return address of the last element in vector's array
	 */
		const_iterator end() const {
			return const_iterator(&_datas[_size]);
		}

	/**
	 * Get the last elements of vector's array.
	 * 
	 * @return address of the last element in vector's array
	 */
		reverse_iterator rbegin() {
			return reverse_iterator(&_datas[_size]);
		}

	/**
	 * Get the last elements of vector's array in constant.
	 * 
	 * @return address of the last element in vector's array
	 */
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(&_datas[_size]);
		}

	/**
	 * Get the first elements of vector's array.
	 * 
	 * @return address of the first element in vector's array
	 */
		reverse_iterator rend() {
			return reverse_iterator(&_datas[0]);
		}

	/**
	 * Get the first elements of vector's array in constant.
	 * 
	 * @return address of the first element in vector's array
	 */
		const_reverse_iterator rend() const {
			return const_reverse_iterator(&_datas[0]);
		}

/**
 * 
 * Capacity
 * 
 */

	/**
	 * Get the size of vector.
	 * 
	 * @return the size of vector
	 */
		size_type size() const 
		{
			return _size;
		}

	/**
	 * Get the max size of memory this vector can allocate, this size change by the type "size_type".
	 * 
	 * @return max size of memory can be allocated
	 */
		size_type max_size() const 
		{
			return  std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

	/**
	 * Change the size of datas's array, delete datas if the new size is smaller than before.
	 * If the new size is bigger, fill the new empty value with NULL if the parameter "val" was not use.
	 * If the new size is bigger, fill the new empty values with "val".
	 * 
	 * @param n - the new size of array
	 * @param val - value to fill (can be empty)
	 * @return void
	 */
		void resize (size_type n, value_type val = value_type())
		{
			if (_capacity < n)
			{
				// Allocate new capacity
				value_type *tmp = _datas;
				_datas = _alloc.allocate(n);

				// Fill new array with ancient values
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}
				// Add new values in array
				for (size_t i = _size; i < n; i++)
					_alloc.construct(&_datas[i], val);

				_alloc.deallocate(tmp, _capacity);
				_capacity = n;
				_size = n;
			}
			else if (_size > n)
			{
				// Allocate capacity in new array
				value_type *tmp = _datas;
				_datas = _alloc.allocate(_capacity);

				// Fill new array with "n" ancient values
				for (size_t i = 0; i < n; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}

				for (size_t i = n; i < _size; i++)
					_alloc.destroy(&tmp[i]);

				_alloc.deallocate(tmp, _capacity);
				_size = n;
			}
		}

	/**
	 * Get capacity of vector, capacity is the maximum value who was allocated for array.
	 * 
	 * @return capacity of vector's array
	 */
		size_type capacity() const 
		{
			return _capacity;
		}

	/**
	 * Get if array is empty
	 * 
	 * @return true if array is empty
	 */
		bool empty() const 
		{
			if (_size == 0)
				return true;
			return false;
		}

	/**
	 * Allocate new value of capacity, the new capacity need to be bigger than before.
	 * 
	 * @param n - new size of capacity
	 * @return void
	 */
		void reserve (size_t n) 
		{
			if (_capacity < n || _datas == NULL)
			{
				// Allocate new capacity
				pointer tmp = _datas;
				_datas = _alloc.allocate(n);

				// Fill new array with ancient values
				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}

				if (_datas != NULL)
					_alloc.deallocate(tmp, _capacity);
				_capacity = n;
			}
		}

/**
 * 
 * Element access
 * 
 */

	/**
	 * Get reference to the element in index "n" in array.
	 * 
	 * @param n - index of element
	 * @return reference to the value
	 */
		reference operator[](size_t n) 
		{
			return _datas[n];
		}

	/**
	 * Get reference to the element in index "n" in array in constant.
	 * 
	 * @param n - index of element
	 * @return reference to the value
	 */
		const_reference operator[](size_t n) const 
		{
			return _datas[n];
		}


	/**
	 * Get reference to the element in index "n" in array.
	 * 
	 * @param n - index of element
	 * @throw std::out_of_range - throw if "n" is bigger than size
	 * @return reference to the value
	 */
		reference at (size_t n) 
		{
			if (_size < n)
				throw std::out_of_range("vector");
			return _datas[n];
		}

	/**
	 * Get reference to the element in index "n" in array in constant.
	 * 
	 * @param n - index of element
	 * @throw std::out_of_range - throw if "n" is bigger than size
	 * @return reference to the value
	 */
		const_reference at (size_t n) const 
		{
			if (_size < n)
				throw std::out_of_range("vector");
			return _datas[n];
		}

	/**
	 * Get reference of the first element in array.
	 * 
	 * @return reference of the last value in array
	 */
		reference front () 
		{
			return _datas[0];
		}

	/**
	 * Get reference of the first element in array in contant.
	 * 
	 * @return reference of the last value in array
	 */
		const_reference front () const 
		{
			return _datas[0];
		}

	/**
	 * Get reference of the last element in array.
	 * 
	 * @return reference of the last value in array
	 */
		reference back () 
		{
			return _datas[_size - 1];
		}

	/**
	 * Get reference of the last element in array in contant.
	 * 
	 * @return reference of the last value in array
	 */
		const_reference back () const 
		{
			return _datas[_size - 1];
		}

/**
 * 
 * Modifiers
 * 
 */

	/**
	 * Clear vector's array and create new one with the values between "first" and "last".
	 * Capacity can be only increase.
	 * This function use an input iterator.
	 * 
	 * @param first - starting iterator
	 * @param last - endding iterator
	 * @return void
	 */
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			clear();
			check_capacity();
			for ( ; first != last; first++)
				push_back(*first);
		}
	
	/**
	 * Clear vector's array and create new one with size "n" and fill it with value "val".
	 * Capacity can be only increase.
	 * 
	 * @param n - new size of array
	 * @param val - value filled
	 * @return void
	 */
		void assign (size_type n, const value_type& val)
		{
			clear();
			check_capacity(n);
			for (size_t i = 0; i < n; i++)
				push_back(val);	
		}

	/**
	 * Add new element "val" in array, if the size equal capacity, 
	 * increase capacity by multiplicate this actual capacity by two. 
	 * 
	 * @param val - value to add
	 * @return void
	 */
		void push_back (const value_type& val)
		{
			check_capacity();
			_alloc.construct(&_datas[_size], val);
			_size++;
		}

	/**
	 * Delete the last element in array.
	 * 
	 * @return void
	 */
		void pop_back ()
		{
			_alloc.destroy(&_datas[_size - 1]);
			_size--;
		}

	/**
	 * Insert in array the value "val" in "position", "position" is an iterator of its own array.
	 * 
	 * @param position - iterator of its own array, position of the new added value
	 * @param val - value to add
	 * @return iterator of the first element of array
	 */
		iterator insert (iterator position, const value_type& val)
		{
			size_type index = position - begin();
			if (index <= _capacity)
			{
				check_capacity();
				for (size_t i = _size; i >= 0; i--)
				{
					// Move value in actual index to the next index and put the new one at the index
					if (i == index)
					{
						_alloc.construct(&_datas[i + 1], _datas[i]);
						_alloc.destroy(&_datas[i]);
						_alloc.construct(&_datas[i], val);
						break;
					}
					// Move value in actual index to the next index to have one free index when will be on the right index
					else
					{
						_alloc.construct(&_datas[i + 1], _datas[i]);
						_alloc.destroy(&_datas[i]);
					}
				}
				_size++;
			}
			return _datas;
		}

	/**
	 * Insert in array "n" elements of the value "val" in "position", "position" is an iterator of its own array.
	 * 
	 * @param position - iterator of its own array, position of the new added value
	 * @param n - number of added elements
	 * @param val - value to add
	 * @return void
	 */
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type index = position - begin();
			if (index <= _capacity)
			{
				if (_capacity - _size < n)
					reserve(_capacity + n);
				else
					check_capacity();

				for (size_t i = _size; i >= 0; i--)
				{
					// Move value in actual index to the next index + "n" and put the new one at the index
					if (i == index)
					{
						_alloc.construct(&_datas[i + n], _datas[i]);
						_alloc.destroy(&_datas[i]);
						for (size_t j = 0; j < n; j++)
							_alloc.construct(&_datas[i + j], val);
						break;
					}
					// Move value in actual index to the next index + "n" to have one free index when will be on the right index
					else
					{
						_alloc.construct(&_datas[i + n], _datas[i]);
						_alloc.destroy(&_datas[i]);
					}
				}
				_size += n;
			}
		}


	/**
	 * Insert in array, all elements pointed between "first" and "last" in "position", "position" is an iterator of its own array.
	 * This function use an input iterator.
	 * 
	 * @param position - iterator of its own array, position of the new added value
	 * @param first - starting iterator
	 * @param last - endding iterator
	 * @return void
	 */
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			size_type index = position - begin();
			if (index <= _capacity)
			{
				// Create new array
				value_type *tmp = _datas;
				size_type	size_tmp = _size;
				size_type	capacity_tmp = _capacity;
				_datas = _alloc.allocate(_capacity);

				// Fill new array with ancient values to position
				for (size_t i = 0; i < index; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}

				_size = index;

				// Add values between "first" and "last"
				for ( ; first != last; first++)
					push_back(*first);

				// Fill new array with ancient values
				for (size_t i = index; i < size_tmp; i++)
				{
					push_back(tmp[i]);
					_alloc.destroy(&tmp[i]);
				}
				_alloc.deallocate(tmp, capacity_tmp);
			}
		}

	/**
	 * Delete in array the element in "position" , "position" is an iterator of its own array.
	 * 
	 * @param position - iterator of its own array, position of deleted value
	 * @return iterator of the first element of array
	 */
		iterator erase (iterator position)
		{
			size_type index = position - begin();

			// Destroy the element in index
			_alloc.destroy(&_datas[index]);

			// Replace all next elements to fill correctly the array 
			for (size_t i = index; i < _size; i++)
			{
				_alloc.construct(&_datas[i], _datas[i + 1]);
				_alloc.destroy(&_datas[i + 1]);
			}

			_alloc.destroy(&_datas[_size - 1]);
			_size--;
			return _datas;
		}

	/**
	 * Delete all elements pointed between "first" and "last".
	 * "first" and "last" are iterators of its own array.
	 * 
	 * @param first - starting iterator
	 * @param last - endding iterator
	 * @return iterator of the first element of array
	 */
		iterator erase (iterator first, iterator last)
		{
			size_type index;
			size_type index_tmp;
			iterator tmp = first;
			// Destroy the elements from "first" to "last"
			for ( ; first != last; first++)
			{
				index = first - begin();
				_alloc.destroy(&_datas[index]);
				_size--;
			}
			// Replace all elements to fill correctly the array 
			for ( ; tmp != end(); tmp++)
			{
				index = last - begin();
				index_tmp = tmp - begin();
				_alloc.construct(&_datas[index_tmp], _datas[index]);
				_alloc.destroy(&_datas[index]);
				last++;
			}
			return _datas;
		}

	/**
	 * Swap all informations of himself and reference of vector.
	 * 
	 * @param x - address of vector we want to swap
	 * @return void 
	 */
		void swap (vector &x)
		{
			std::swap(_capacity, x._capacity);
			std::swap(_size, x._size);
			std::swap(_datas, x._datas);
			std::swap(_alloc, x._alloc);
		}

	/**
	 * Clear all datas in array and deallocate memory.
	 * 
	 * @return void
	 */
		void clear ()
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(&_datas[i]);
			
			_alloc.deallocate(_datas, _capacity);
			_datas = NULL;
			_size = 0;
		}

/**
 * 
 * Allocator
 * 
 */

	/**
	 * Get allocator of vector.
	 * 
	 * @return allocator reference
	 */
		allocator_type get_allocator() const
		{
			return _alloc;
		}

/**
 * 
 * Utils
 * 
 */

	/**
	 * Check if size of array are equal to capacity, if its true, increase capacity by multiplicate the actual value of capacity by two.
	 * If array is empty, allocate capacity
	 * 
	 * @return void 
	 */
		void check_capacity ()
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			if (_datas == NULL)
				reserve(_capacity);
		}

	/**
	 * Check if capacity are smaller than "n", if its true, allocate "n" capacity.
	 * Check if size of array are equal to capacity, if its true, increase capacity by multiplicate the actual value of capacity by two.
	 * If array is empty, allocate capacity
	 * 
	 * @param n - capacity value to check
	 * @return void 
	 */
		void check_capacity (size_type n)
		{
			if (_capacity < n)
				reserve(n);
			else if (_size == _capacity)
				reserve(_capacity * 2);
			else if (_datas == NULL)
				reserve(_capacity);
		}

	private:
		value_type		*_datas;
		allocator_type	_alloc;
		size_type		_size;
		size_type		_capacity;

};

/**
 * 
 * Non-member function overload
 * 
 */

/**
 * Overload of "==" operator
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if the two vectors are equal
 */
template <class T, class A>
bool operator== (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	if (lhs.max_size() == rhs.max_size() && lhs.get_allocator() == rhs.get_allocator() && lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return false;
		}
		return true;
	}
	return false;
}

/**
 * Overload of "!=" operator
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if the two vectors are not equal
 */
template <class T, class A>
bool operator!= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	if (lhs.max_size() == rhs.max_size() && lhs.get_allocator() == rhs.get_allocator() && lhs.size() == rhs.size() && lhs.capacity() == rhs.capacity())
	{
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs.at(i) != rhs.at(i))
				return true;
		}
		return false;
	}
	return true;
}

/**
 * Overload of "<" operator.
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if "lhs" are smaller than "rhs"
 */
template <class T, class A>
bool operator<  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

/**
 * Overload of "<=" operator.
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if "lhs" are smaller than "rhs" or equal
 */
template <class T, class A>
bool operator<= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs);
}

/**
 * Overload of ">" operator.
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if "lhs" are bigger than "rhs"
 */
template <class T, class A>
bool operator>  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (!lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) && lhs != rhs);
}

/**
 * Overload of ">=" operator.
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return true if "lhs" are bigger than "rhs" or equal
 */
template <class T, class A>
bool operator>= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (!lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs);
}

/**
 * Overload of "swap" function.
 * Swap all informations of himself and reference of vector.
 * 
 * @param lhs - address of vector
 * @param rhs - address of vector
 * @return void 
 */
template <class T, class A>
void swap (vector<T,A>& x, vector<T,A>& y)
{
	x.swap(y);
}

#endif