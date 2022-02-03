#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <memory>
#include <algorithm>
#include <functional>
#include "Pair.hpp"
#include "../Iterators/Bidirectional_iterator.hpp"
#include "../Iterators/Bidirectional_Const_iterator.hpp"
#include "../Iterators/reverseIterator.hpp"
#include "../Iterators/reverseConstIterator.hpp"

template < class Key, class T, class Compare = std::less<Key>, class A = std::allocator< pair<const Key,T> > >
class Map
{
	public:

	/**
	 * Typedef
	 */

		typedef Key key_type;
		typedef T mapped_type;
		typedef Compare key_compare;
	    typedef A allocator_type;
		typedef typename A::value_type value_type; 
		typedef typename A::reference reference;
		typedef typename A::const_reference const_reference;
		typedef typename A::pointer pointer;
		typedef typename A::difference_type difference_type;
		typedef typename A::size_type size_type;

		typedef reverseIterator<T, A> reverse_iterator;
   		typedef reverseConstIterator<T, A> const_reverse_iterator;
		typedef bidirectional_iterator<T, A> iterator;
		typedef bidirectional_const_iterator<T, A> const_iterator;

	/**
	 * Constructor
	 */

		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

		}	

		template <class InputIterator>
		map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

		}	

		map (const map& x)
		{

		}

		~map()
		{

		}

		map& operator= (const map& x)
		{

		}

	/**
	 *	Iterators
	 */

		iterator begin()
		{
			return iterator(&_datas[0]);
		}

		const_iterator begin() const {
			return const_iterator(&_datas[0]);
		}

		iterator end()
		{
			return iterator(&_datas[_size]);
		}

		const_iterator end() const
		{
			return const_iterator(&_datas[_size]);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(&_datas[_size]);
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(&_datas[_size]);
		}

		reverse_iterator rend()
		{
			return reverse_iterator(&_datas[0]);
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(&_datas[0]);
		}

	/**
	 * Capacity
	 */

		bool empty() const
		{

		}

		size_type size() const
		{

		}

		size_type max_size() const
		{

		}

	/**
	 * Elements access
	 */

		mapped_type& operator[] (const key_type& k)const
		{

		}

	/**
	 * Modifier
	 */

		pair<iterator,bool> insert (const value_type& val)const
		{

		}

		iterator insert (iterator position, const value_type& val)const
		{

		}

		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)const
		{

		}

		void erase (iterator position)const
		{

		}

		size_type erase (const key_type& k)const
		{

		}

		void erase (iterator first, iterator last)const
		{

		}

		void swap (map& x)const
		{

		}

		void clear()const
		{

		}

	/**
	 * Observers
	 */

		key_compare key_comp() const
		{

		}

		value_compare value_comp() const
		{

		}

	/**
	 * Operations
	 */

	    iterator find (const key_type& k)const
		{

		}

		const_iterator find (const key_type& k) const
		{

		}

		size_type count (const key_type& k) const
		{

		}

		iterator lower_bound (const key_type& k)const
		{

		}

		const_iterator lower_bound (const key_type& k) const
		{

		}

		iterator upper_bound (const key_type& k)const
		{

		}

		const_iterator upper_bound (const key_type& k) const
		{

		}

		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{

		}

		pair<iterator,iterator> equal_range (const key_type& k)const
		{

		}

	/**
	 * Allocator
	 */	

		allocator_type get_allocator() const
		{
			return _alloc;
		}

	private:
		allocator_type _alloc;
		size_type _size;
};

#endif