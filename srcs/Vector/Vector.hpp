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
 */

template <class T, class A = std::allocator<T> >
class vector
{

	public:

	/**
	 * Typedef
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
	 * Constructor
	 */

		explicit vector(const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_capacity = 1;
			_size = 0;
			_datas = _alloc.allocate(_capacity);
		}

		explicit vector(size_t n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_capacity = n;
			_size = n;
			_datas = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_alloc.construct(&_datas[i], value);
		}

		template <class InputIterator>
        vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _alloc(alloc)
		{
			_size = 0;
			_capacity = 1;
			_datas = _alloc.allocate(_capacity);
			for ( ; first != last; first++)
				push_back(*first);
		}

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

		~vector(void)
		{
			clear();
		}

	/**
	 *	Iterators
	 */

		iterator begin() {
			return iterator(&_datas[0]);
		}

		const_iterator begin() const {
			return const_iterator(&_datas[0]);
		}

		iterator end() {
			return iterator(&_datas[_size]);
		}

		const_iterator end() const {
			return const_iterator(&_datas[_size]);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(&_datas[_size]);
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(&_datas[_size]);
		}

		reverse_iterator rend() {
			return reverse_iterator(&_datas[0]);
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(&_datas[0]);
		}

	/**
	 * Capacity
	 */

		size_type size() const 
		{
			return _size;
		}

		size_type max_size() const 
		{
			return  std::numeric_limits<size_type>::max() / sizeof(value_type);
		}

		void resize (size_type n, value_type val = value_type())
		{
			if (_capacity < n)
			{
				value_type *tmp = _datas;
				_datas = _alloc.allocate(n);

				for (size_t i = 0; i < _size; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}

				for (size_t i = _size; i < n; i++)
					_alloc.construct(&_datas[i], val);

				_alloc.deallocate(tmp, _capacity);
				_capacity = n;
				_size = n;
			}
			else if (_size > n)
			{
				value_type *tmp = _datas;
				_datas = _alloc.allocate(_capacity);

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

		size_type capacity() const 
		{
			return _capacity;
		}

		bool empty() const 
		{
			if (_size == 0)
				return true;
			return false;
		}

		void reserve (size_t n) 
		{
			if (_capacity < n || _datas == NULL)
			{
				pointer tmp = _datas;
				_datas = _alloc.allocate(n);

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
	 * Element access
	 */

		reference operator[](size_t n) 
		{
			return _datas[n];
		}

		const_reference operator[](size_t n) const 
		{
			return _datas[n];
		}

		reference at (size_t n) 
		{
			if (_size < n)
				throw std::out_of_range("vector");
			return _datas[n];
		}

		const_reference at (size_t n) const 
		{
			if (_size < n)
				throw std::out_of_range("vector");
			return _datas[n];
		}

		reference front () 
		{
			return _datas[0];
		}

		const_reference front () const 
		{
			return _datas[0];
		}

		reference back () 
		{
			return _datas[_size - 1];
		}

		const_reference back () const 
		{
			return _datas[_size - 1];
		}

	/**
	 * Modifiers
	 */

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last)
		{
			clear();
			check_capacity();
			for ( ; first != last; first++)
				push_back(*first);
		}
			
		void assign (size_type n, const value_type& val)
		{
			clear();
			check_capacity(n);
			for (size_t i = 0; i < n; i++)
				push_back(val);	
		}

		void push_back (const value_type& val)
		{
			check_capacity();
			_alloc.construct(&_datas[_size], val);
			_size++;
		}

		void pop_back ()
		{
			_alloc.destroy(&_datas[_size - 1]);
			_size--;
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type index = position - begin();
			if (index <= _capacity)
			{
				check_capacity();
				for (size_t i = _size; i >= 0; i--)
				{
					if (i == index)
					{
						_alloc.construct(&_datas[i + 1], _datas[i]);
						_alloc.destroy(&_datas[i]);
						_alloc.construct(&_datas[i], val);
						break;
					}
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
					if (i == index)
					{
						_alloc.construct(&_datas[i + n], _datas[i]);
						_alloc.destroy(&_datas[i]);
						for (size_t j = 0; j < n; j++)
							_alloc.construct(&_datas[i + j], val);
						break;
					}
					else
					{
						_alloc.construct(&_datas[i + n], _datas[i]);
						_alloc.destroy(&_datas[i]);
					}
				}
				_size += n;
			}
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{
			size_type index = position - begin();
			if (index <= _capacity)
			{
				value_type *tmp = _datas;
				size_type	size_tmp = _size;
				size_type	capacity_tmp = _capacity;
				_datas = _alloc.allocate(_capacity);
				for (size_t i = 0; i < index; i++)
				{
					_alloc.construct(&_datas[i], tmp[i]);
					_alloc.destroy(&tmp[i]);
				}
				_size = index;
				for ( ; first != last; first++)
					push_back(*first);
				for (size_t i = index; i < size_tmp; i++)
				{
					push_back(tmp[i]);
					_alloc.destroy(&tmp[i]);
				}
				_alloc.deallocate(tmp, capacity_tmp);
			}
		}

		iterator erase (iterator position)
		{
			size_type index = position - begin();
			_alloc.destroy(&_datas[index]);
			for (size_t i = index; i < _size; i++)
			{
				_alloc.construct(&_datas[i], _datas[i + 1]);
				_alloc.destroy(&_datas[i + 1]);
			}

			_alloc.destroy(&_datas[_size - 1]);
			_size--;
			return _datas;
		}

		iterator erase (iterator first, iterator last)
		{
			size_type index;
			size_type index_tmp;
			iterator tmp = first;
			for ( ; first != last; first++)
			{
				index = first - begin();
				_alloc.destroy(&_datas[index]);
				_size--;
			}
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

		void swap (vector &x)
		{
			std::swap(_capacity, x._capacity);
			std::swap(_size, x._size);
			std::swap(_datas, x._datas);
			std::swap(_alloc, x._alloc);
		}

		void clear ()
		{
			for (size_t i = 0; i < _size; i++)
				_alloc.destroy(&_datas[i]);
			
			_alloc.deallocate(_datas, _capacity);
			_datas = NULL;
			_size = 0;
		}

	/**
	 * Allocator
	 */

		allocator_type get_allocator() const
		{
			return _alloc;
		}

	/**
	 * Utils
	 */

		void check_capacity ()
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			if (_datas == NULL)
				reserve(_capacity);
		}

		void check_capacity (size_t n)
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
 * Non-member function overload
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

template <class T, class A>
bool operator<  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class A>
bool operator<= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs);
}

template <class T, class A>
bool operator>  (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (!lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) && lhs != rhs);
}

template <class T, class A>
bool operator>= (const vector<T,A>& lhs, const vector<T,A>& rhs)
{
	return (!lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) || lhs == rhs);
}

template <class T, class A>
void swap (vector<T,A>& x, vector<T,A>& y)
{
	x.swap(y);
}

#endif