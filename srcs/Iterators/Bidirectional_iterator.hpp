#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <memory>
# include "../Map/Tree_node.hpp"

template <class Node>
class bidirectional_iterator { 
	public:
		typedef typename Node::reference reference;
		typedef typename Node::pointer pointer;
		typedef std::bidirectional_iterator_tag iterator_category;

		bidirectional_iterator() : _node(nullptr) {}
		bidirectional_iterator(const bidirectional_iterator &it) : _node(it._node) {}
		bidirectional_iterator(Node *n): _node(n) {}
		~bidirectional_iterator(){}

		Node *get_node() {return _node;}

		bidirectional_iterator& operator=(const bidirectional_iterator &it)
		{
			_node = new Node(*it._node);
			return *this;
		}

		bool operator==(const bidirectional_iterator &it) const
		{
			if(_node != NULL && it._node != NULL)
				return (_node->data.first == it._node->data.first) && (_node->data.second == it._node->data.second);
			return false;
		}

		bool operator!=(const bidirectional_iterator &it) const
		{
			return (_node->data.first != it._node->data.first) || (_node->data.second != it._node->data.second);
		}

		bidirectional_iterator& operator++()
		{
			Node *tmp = _node;
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
			Node *tmp = _node;
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

		bidirectional_iterator& operator--()
		{
			Node *tmp = _node;
			while (tmp->data.first == _node->data.first)
			{
				if (tmp->left == NULL)
				{
					if (tmp == tmp->parent->left)
					{
						while (tmp == tmp->parent->left)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->left;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->left != NULL)
				{
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
				}
			}
			if (tmp->left == NULL)
			{
				if (tmp == tmp->parent->left)
				{
					while (tmp == tmp->parent->left)
						tmp = tmp->parent;
					if (tmp->parent == NULL)
					{
						_node = _node->left;
						return *this;
					}
					tmp = tmp->parent;
				}
				else
					tmp = tmp->parent;
			}
			else if (tmp->left != NULL)
			{
				tmp = tmp->left;
				while (tmp->right != NULL)
					tmp = tmp->right;
			}
			if (tmp != NULL)
				_node = tmp;
			return *this;
		}

		bidirectional_iterator operator--(int)
		{
			Node *tmp = _node;
			while (tmp->data.first == _node->data.first)
			{
				if (tmp->left == NULL)
				{
					if (tmp == tmp->parent->left)
					{
						while (tmp == tmp->parent->left)
							tmp = tmp->parent;
						if (tmp->parent == NULL)
						{
							_node = _node->left;
							return *this;
						}
						tmp = tmp->parent;
					}
					else
						tmp = tmp->parent;
				}
				else if (tmp->left != NULL)
				{
					tmp = tmp->left;
					while (tmp->right != NULL)
						tmp = tmp->right;
				}
			}
			if (tmp->left == NULL)
			{
				if (tmp == tmp->parent->left)
				{
					while (tmp == tmp->parent->left)
						tmp = tmp->parent;
					if (tmp->parent == NULL)
					{
						_node = _node->left;
						return *this;
					}
					tmp = tmp->parent;
				}
				else
					tmp = tmp->parent;
			}
			else if (tmp->left != NULL)
			{
				tmp = tmp->left;
				while (tmp->right != NULL)
					tmp = tmp->right;
			}
			if (tmp != NULL)
				_node = tmp;
			return *this;
		}

		reference operator*() const
		{
			return _node->data;
		}

		pointer operator->() const
		{
			return &_node->data;
		}

	private:
		Node *_node;
};

#endif