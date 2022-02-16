#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <memory>
# include "../Map/Tree_node.hpp"

template <class Pair, class A = std::allocator<Pair> >
class bidirectional_iterator { 
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef ft::BiTreeNode<Pair> node;
		typedef std::bidirectional_iterator_tag iterator_category;

		bidirectional_iterator() : _node(nullptr), _is_end(false) {}
		bidirectional_iterator(const bidirectional_iterator &it) : _node(it._node), _is_end(false) {}
		bidirectional_iterator(node *n): _node(n), _is_end(false) {}
		~bidirectional_iterator(){}

		bidirectional_iterator& operator=(const bidirectional_iterator &it)
		{
			_node = it._node;
			return *this;
		}

		bool operator==(const bidirectional_iterator &it) const
		{
			return _node == it._node;
		}

		bool operator!=(const bidirectional_iterator &it) const
		{
			return _node != it._node;
		}

		bidirectional_iterator& operator++()
		{
			node *tmp = _node;
			while (tmp->data.first == _node->data.first)
			{
				if (tmp->right == NULL)
				{
					if (tmp == tmp->parent->right)
					{
						while (tmp == tmp->parent->right)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->right;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->right != NULL)
				{
					tmp = tmp->right;
					while (tmp->left != NULL)
						tmp = tmp->left;
				}
			}
			if (tmp != NULL)
				_node = tmp;
			return *this;
		}

		bidirectional_iterator operator++(int)
		{
			bidirectional_iterator tmp(*this);
			++_node;
			return tmp;
		}

		bidirectional_iterator& operator--()
		{
			--_node;
			return *this;
		}

		bidirectional_iterator operator--(int)
		{
			bidirectional_iterator tmp(*this);
			--_node;
			return tmp;
		}

		reference operator*() const
		{
			return *_node->data;
		}

		pointer operator->() const
		{
			return &_node->data;
		}

	private:
		node *_node;
		bool _is_end;
};

#endif