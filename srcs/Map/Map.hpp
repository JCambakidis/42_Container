#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <memory>
#include <algorithm>
#include <functional>
#include "Pair.hpp"
#include "RBTree.hpp"
#include "../Iterators/Bidirectional_iterator.hpp"
#include "../Iterators/Bidirectional_Const_iterator.hpp"
#include "../Iterators/reverseIterator.hpp"
#include "../Iterators/reverseConstIterator.hpp"

namespace ft
{

	/**
	 * Map is a sorted associative container that contains key-value pairs with unique keys. 
	 * Keys are sorted by using the comparison function Compare. 
	 * Search, removal, and insertion operations have logarithmic complexity. 
	 * Maps are usually implemented as red-black trees.
	 * 
	 * @tparam Key - type of key
	 * @tparam T - type of datas
	 * @tparam Compare - implementation-defined strict total order
	 * @tparam A - allocator template of pair in standard library
	 */

	template < class Key, class T, class Compare = std::less<Key>, class A = std::allocator< ft::pair<const Key, T> > >
	class map
	{
		public:

	/**
	 * Typedef
	 */

			typedef Key key_type;
			typedef T mapped_type;
			typedef Compare key_compare;
			typedef A allocator_type;
			typedef typename A::template rebind< ft::RBTree<Key, T> >::other new_alloc;
			typedef typename ft::BiTreeNode< ft::pair<const Key, T> > node;
			typedef typename A::value_type value_type; 
			typedef typename A::reference reference;
			typedef typename A::const_reference const_reference;
			typedef typename A::pointer pointer;
			typedef typename A::difference_type difference_type;
			typedef typename A::size_type size_type;
			typedef reverseIterator<node> reverse_iterator;
			typedef reverseConstIterator<node> const_reverse_iterator;
			typedef bidirectional_iterator<node> iterator;
			typedef bidirectional_const_iterator<node> const_iterator;

	/**
	 * Intern Class
	 */

		/**
		 * Function object that compares objects of type ft::map::value_type (key-value pairs) by comparing of the first components of the pairs.
		 */
			class value_compare
			{
				protected:
					Compare _comp;
				private:
					/* data */
				public:
					value_compare(): _comp(new Compare()){}
					~value_compare(){}

					/**
					 * Compare two value_type and return the result of comparator stored.
					 * 
					 * @param lhs - first value_type to compare
					 * @param rhs - second value_tuype to compare
					 * @return result of comparator stored
					 */
					bool operator()( const value_type& lhs, const value_type& rhs ) const
					{
						return _comp(lhs.first, rhs.first);
					}
			};
		
	/**
	 * Constructor
	 */

		/**
		 * Construct new empty map.
		 * 
		 * @param comp - Compare's address, set to default Compare
		 * @param alloc - Allocator's address, set to default allocator
		 */
			explicit map (const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc()): _alloc(alloc), _comp(comp)
			{
				_tree = _alloc.allocate(1);
				_alloc.construct(_tree, RBTree<Key, T>());
			}

		/**
		 * Construct new map filled with the value between "first" and "last".
		 *
		 * @param first - starting iterator
		 * @param last - ending iterator
		 * @param comp - Compare's address, set to default Compare
		 * @param alloc - Allocator's address, set to default allocator
		 */
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const new_alloc& alloc = new_alloc()): _alloc(alloc), _comp(comp)
			{
				_tree =_alloc.allocate(1);
				_alloc.construct(_tree, RBTree<Key, T>());
				for ( ;first != last; first++)
					_tree->insert(first);
			}

		/**
		 * Construct new map filled with an other map's values.
		 * 
		 * @param x - map's address
		 */
			map (const map& x)
			{
				if (x != this)
				{
					_alloc = x._alloc;
					_comp = x._comp;
					_tree = x._tree;
				}
			}

		/**
		 * Destroy map, delete all map's tree values and free memory.
		 */
			~map()
			{
				clear();
			}

		/**
		 * Allocate map's values with an other map's values.
		 * 
		 * @param x - map's address
		 * @return address of this
		 */
			map& operator= (const map& x)
			{
				if (x != this)
				{
					_alloc = x._alloc;
					_comp = x._comp;
					_tree = x._tree;
				}
				return *this;
			}

	/**
	 *	Iterators
		*/

		/**
		 * Get the first map's tree element.
		 * 
		 * @return address of the first map's tree element
		 */
			iterator begin()
			{
				return iterator(_tree->find_min(_tree->getRoot()));
			}

		/**
		 * Get the first constant map's tree element.
		 * 
		 * @return address of the first map's tree element
		 */
			const_iterator begin() const {
				return const_iterator(_tree->find_min(_tree->getRoot()));
			}

		/**
		 * Get the last map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			iterator end()
			{
				return iterator(_tree->find_max(_tree->getRoot())->right);
			}

		/**
		 * Get the last constant map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			const_iterator end() const
			{
				return const_iterator(_tree->find_max(_tree->getRoot())->right);
			}

		/**
		 * Get the last map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			reverse_iterator rbegin()
			{
				return reverse_iterator(_tree->find_max(_tree->getRoot()));
			}

		/**
		 * Get the last constant map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_tree->find_max(_tree->getRoot()));
			}

		/**
		 * Get the first map's tree element.
		 * 
		 * @return address of the first map's tree element
		 */
			reverse_iterator rend()
			{
				return reverse_iterator(_tree->find_min(_tree->getRoot()));
			}

		/**
		 * Get the first constant map's tree element.
		 * 
		 * @return address of the first map's tree element
		 */
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(_tree->find_min(_tree->getRoot()));
			}

	/**
	 * Capacity
	 */

		/**
		 * Check is map is empty.
		 * 
		 * @return true if map is empty
		 */
			bool empty() const
			{
				return (_tree->get_size() == 0) ? true : false;
			}

		/**
		 * Get map's size.
		 * 
		 * @return map's size
		 */
			size_type size() const
			{
				return _tree->get_size();
			}

		/**
		 * Get memory's max size can be allocate, this size change by the type "size_type".
		 * 
		 * @return memory's max size can be allocated
		 */
			size_type max_size() const
			{
				return  std::numeric_limits<size_type>::max() / sizeof(value_type);
			}

	/**
	 * Elements access
	 */

		/**
		 * Get tree element in key "k".
		 * 
		 * @param k - key of finded value
		 * @return value in key "k"
		 */
			mapped_type& operator[] (const key_type& k) const
			{
				return _tree->find(k)->data.second;
			}

	/**
	 * Modifier
	 */

		/**
		 * Insert pair in tree
		 * 
		 * @param val - datas of new node - value_type is pair<key_type, T>
		 * @return pair < values insered, true if is insered >
		 */
			ft::pair<iterator,bool> insert (const value_type &val) const
			{
				bool is_inserted = _tree->insert(&val);
				iterator it = iterator(_tree->find(val.first));
				return ft::pair<iterator, bool>(it, is_inserted);
			}

		/**
		 * Insert pair in tree at position.
		 * 
		 * @param position - iterator of BiTreeNode, node position to start insertion
		 * @param val - datas of new node - value_type is pair<key_type, T>
		 * @return pair insered
		 */
			iterator insert (iterator position, const value_type& val) const
			{
				_tree->insert(*position, &val);
				return _tree->find(val.first);
			}
			

		/**
		 * Insert pairs between "first" and "last" in tree.
		 * 
		 * @param first - iterator of pair, first pair inserted
		 * @param last - iterator of pair, last pair inserted
		 * @return void
		 */
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) const
			{
				for ( ;first != last; first++)
					_tree->insert(*first);
			}

		/**
		 * Delete node in tree at "position".
		 * 
		 * @param position - pair iterator
		 * @return void
		 */
			void erase (iterator position) const
			{
				ft::pair<const Key, T> tmp = position;
				_tree->erase(tmp.first);
			}

		/**
		 * Delete all nodes in tree with "k" values.
		 * 
		 * @param k - key of nodes who was deleted
		 * @return number of nodes deleted
		 */
			size_type erase (const key_type& k) const
			{
				size_t res = 0;
				while (_tree->erase(k))
					res++;
				return res;
			}

		/**
		 * Delete nodes pointed by "first" to "last".
		 * 
		 * @param first - pair iterator
		 * @param last - pair iterator
		 * @return void
		 */
			void erase (iterator first, iterator last) const
			{
				for ( ;first != last; first++)
					_tree->erase(first);
			}

		/**
		 * Swap value under map and "x".
		 * 
		 * @param x - address of map we want to swap values
		 * @return void
		 */
			void swap (map& x) const
			{
				map *tmp = this;
				_tree = x._tree;
				x._tree = tmp->_tree;
			}

		/**
		 * Clean all elements in tree and map and free memory allocated.
		 * 
		 * @return void 
		 */
			void clear()
			{
				if (_tree != NULL)
				{
					_tree->clear(_tree->getRoot());
					_alloc.destroy(_tree);
					_alloc.deallocate(_tree, 1);
					_tree = NULL;
				}
			}

	/**
	 * Observers
	 */

		/**
		 * 
		 * 
		 */
			key_compare key_comp() const
			{
				key_compare kcomp;
				return kcomp;
			}

			value_compare value_comp() const
			{

			}

	/**
	 * Operations
	 */

		/**
		 * Find first element in map with ker "k".
		 * 
		 * @param k - key research
		 * @return iterator of pair finded
		 */
			iterator find (const key_type& k)
			{
				return iterator(_tree->find(k));
			}

		/**
		 * Find first element in map with ker "k".
		 * 
		 * @param k - key research
		 * @return const_iterator of pair finded
		 */
			const_iterator find (const key_type& k) const
			{
				return const_iterator(_tree->find(k));
			}

			// size_type count (const key_type& k) const
			// {

			// }

			// iterator lower_bound (const key_type& k) const
			// {

			// }

			// const_iterator lower_bound (const key_type& k) const
			// {

			// }

			// iterator upper_bound (const key_type& k) const
			// {

			// }

			// const_iterator upper_bound (const key_type& k) const
			// {

			// }

			// ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			// {

			// }

			// ft::pair<iterator,iterator> equal_range (const key_type& k) const
			// {

			// }

	/**
	 * Allocator
	 */	

		/**
		 * Get allocator of map.
		 * 
		 * @return allocator
		 */
			new_alloc get_allocator() const
			{
				return _alloc;
			}

			ft::RBTree<Key, T> *get_tree()
			{
				return _tree;
			}

		private:
			new_alloc _alloc;
			key_compare _comp;
			ft::RBTree<Key, T> *_tree;
	};
}

#endif