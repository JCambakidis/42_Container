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
		 * @param x - map's reference
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
		 * @param x - map's reference
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
				return iterator(_tree->getEmptyNode());
			}

		/**
		 * Get the last constant map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			const_iterator end() const
			{
				return const_iterator(_tree->getEmptyNode());
			}

		/**
		 * Get the last map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			reverse_iterator rbegin()
			{
				return reverse_iterator(_tree->getEmptyNode());
			}

		/**
		 * Get the last constant map's tree element.
		 * 
		 * @return address of the last map's tree element
		 */
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(_tree->getEmptyNode());
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
		 * Get memory's max size can be allocate, this size change by the type "difference_type".
		 * 
		 * @return memory's max size can be allocated
		 */
			size_type max_size() const
			{
				return  _alloc.max_size();
			}

	/**
	 * Elements access
	 */

		/**
		 * Get tree element in key "k".
		 * 
		 * @param k - Key to search for
		 * @return value in key "k"
		 */
			mapped_type& operator[] (const key_type& k) const
			{
				node *tmp = _tree->find(k);
				if (tmp == NULL)
				{
					insert(ft::pair<Key, T>(k, _tree->getEmptyNode()->data.second));
					tmp = _tree->find(k);
				}
				return tmp->data.second;
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
				if (find(val.first) == _tree->getEmptyNode())
				{
					node *tmp = position.get_node();
					if ((_tree->getRoot()->data.first < tmp->data.first) && (_tree->getRoot()->data.first < val.first))
					{
						while (tmp != _tree->getRoot() && tmp->data.first < tmp->parent->data.first)
							tmp = tmp->parent;
						return _tree->insert(tmp->data, &val);
					}
					else if ((_tree->getRoot()->data.first < tmp->data.first) && (_tree->getRoot()->data.first > val.first))
					{
						while (tmp != _tree->getRoot() && tmp->data.first < tmp->parent->data.first)
							tmp = tmp->parent;
						return _tree->insert(tmp->data, &val);
					}
					return _tree->insert(_tree->getRoot()->data, &val);
				}
				return NULL;
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
					_tree->insert(&*first);
			}

		/**
		 * Delete node in tree at "position".
		 * 
		 * @param position - pair iterator
		 * @return void
		 */
			void erase (iterator position) const
			{
				ft::pair<const Key, T> tmp = *position;
				while (_tree->erase(tmp.first)){}
			}

		/**
		 * Delete all nodes in tree with "k" values.
		 * 
		 * @param k - Key to search for
		 * @return number of nodes deleted
		 */
			size_type erase (const key_type& k) const
			{
				key_type tmp = k;
				size_t res = 0;
				while (_tree->erase(tmp))
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
					_tree->erase(first->first);
			}

		/**
		 * Swap value under map and "x".
		 * 
		 * @param x - reference of map we want to swap values
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
		 * Returns the function object that compares the keys, which is a copy of this container's constructor argument comp.
		 * 
		 * @return key comparison function object.
		 */
			key_compare key_comp() const
			{
				key_compare kcomp;
				return kcomp;
			}

		/**
		 * Returns a function object that compares objects of type ft::map::value_type (key_value pairs) by using key_comp to compare the first components of the pairs.
		 * 
		 * @return value comparison function object.
		 */
			value_compare value_comp() const
			{
				value_compare vcomp;
				return vcomp;
			}

	/**
	 * Operations
	 */

		/**
		 * Find first element in map with ker "k" , and return an iterator pointing to the finded element.
		 * Return end() if no element was find.
		 * 
		 * @param k - Key to search for
		 * @return iterator of pair finded
		 */
			iterator find (const key_type& k)
			{
				node *tmp = _tree->find(k);
				if (tmp == NULL)
					return end();
				return iterator(tmp);
			}

		/**
		 * Find first element in map with ker "k" , and return an const_iterator pointing to the finded element.
		 * Return end() if no element was find.
		 * 
		 * @param k - Key to search for
		 * @return const_iterator of pair finded
		 */
			const_iterator find (const key_type& k) const
			{
				node *tmp = _tree->find(k);
				if (tmp == NULL)
					return end();
				return const_iterator(tmp);
			}

		/**
		 * Returns the number of elements with key that compares equivalent to the specified argument, 
		 * which is either 1 or 0 since this container does not allow duplicates.
		 * 
		 * @param k - Key to search for
		 * @return 1 if key is found
		 */		
			size_type count (const key_type& k) const
			{
				node *tmp = _tree->find(k);
				if (tmp == NULL)
					return 0;
				return 1;
			}

		/**
		 * Returns an iterator pointing to the first element in the container whose key is not considered to go before "k".
		 * Return end() if "k" is highter than the higthest element in map.
		 * 
		 * @param k - Key to search for
		 * @return iterator pointing to the first element not considered to go before "k". end() if "k" is highter than max key value in map
		 */
			iterator lower_bound (const key_type& k)
			{
				iterator tmp = find(k);
				if (tmp == _tree->getEmptyNode())
				{
					tmp = end();
					tmp--;
					if (k > tmp->first)
						return end();
					tmp = begin();
					while (tmp->first < k)
						tmp++;
					return tmp;
				}
				return tmp;
			}

		/**
		 * Returns an const_iterator pointing to the first element in the container whose key is not considered to go before "k".
		 * Return end() if "k" is highter than the higthest element in map.
		 * 
		 * @param k - Key to search for
		 * @return const_iterator pointing to the first element not considered to go before "k". end() if "k" is highter than max key value in map
		 */
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator tmp = find(k);
				if (tmp == _tree->getEmptyNode())
				{
					tmp = end();
					tmp--;
					if (k > tmp->first)
						return end();
					tmp = begin();
					while (tmp->first < k)
						tmp++;
					return tmp;
				}
				return tmp;
			}

		/**
		 * Returns an iterator pointing to the first element in the container whose key is considered to go after "k".
		 * Return end() if "k" is highter than the higthest element in map.
		 * 
		 * @param k - Key to search for
		 * @return iterator pointing to the first element not considered to go after "k". end() if "k" is highter than max key value in map
		 */
			iterator upper_bound (const key_type& k)
			{
				iterator tmp = find(k);
				if (tmp == _tree->getEmptyNode())
				{
					tmp = end();
					tmp--;
					if (k > tmp->first)
						return end();
					tmp = begin();
					while (tmp->first < k)
						tmp++;
					return tmp;
				}
				tmp++;
				return tmp;
			}

		/**
		 * Returns an const_iterator pointing to the first element in the container whose key is considered to go after "k".
		 * Return end() if "k" is highter than the higthest element in map.
		 * 
		 * @param k - Key to search for
		 * @return const_iterator pointing to the first element not considered to go after "k". end() if "k" is highter than max key value in map
		 */
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator tmp = find(k);
				if (tmp == _tree->getEmptyNode())
				{
					tmp = end();
					tmp--;
					if (k > tmp->first)
						return end();
					tmp = begin();
					while (tmp->first < k)
					return tmp;
				}
				return tmp;
			}

		/**
		 * Returns a range containing all elements with the given key in the container. 
		 * The range is defined by two const_iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. 
		 * Alternatively, the first const_iterator may be obtained with lower_bound(), and the second with upper_bound().
		 * 
		 * @param k - Key to search for
		 * @return pair of const_iterator, the first iterator may be obtained with lower_bound(), and the second with upper_bound()
		 */
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
			}

		/**
		 * Returns a range containing all elements with the given key in the container. 
		 * The range is defined by two iterators, one pointing to the first element that is not less than key and another pointing to the first element greater than key. 
		 * Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
		 * 
		 * @param k - Key to search for
		 * @return pair of iterator, the first iterator may be obtained with lower_bound(), and the second with upper_bound()
		 */
			ft::pair<iterator,iterator> equal_range (const key_type& k)
			{
				return ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
			}

	/**
	 * Getter
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

		/**
		 * Get tree of map.
		 * 
		 * @return tree
		 */
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