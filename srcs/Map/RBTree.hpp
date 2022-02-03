#ifndef RBTREE_HPP
# define RBTREE_HPP

#include <iostream>
#include <iterator>
#include <stdexcept> 
#include <memory>
#include <algorithm>
#include <functional>
#include "Pair.hpp"
#include "Tree_node.hpp"

#define BLACK 0
#define RED 1

template < class Key, class T >
class RBTree
{
	private:
		BiTreeNode<Key, T> *_root;

		void recursive_insert(BiTreeNode<Key, T> *root, BiTreeNode<Key, T> *n)
		{
			if (root != NULL)
			{
				if (n->data.first < root->data.first)
				{
					if (root->left != NULL)
					{
						recursive_insert(root->left, n);
						return;
					}
					else
						root->left = n;
				}
				else
				{
					if (root->right != NULL)
					{
						recursive_insert(root->right, n);
						return;
					}
					else
						root->right = n;
				}
			}

			n->parent = root;
			n->left = NULL;
			n->right = NULL;
			n->color = RED;
		}

		void insert_repare_tree(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p;
			BiTreeNode<Key, T> *g;
			if(parent(n) == NULL)
				n->color = BLACK;
			else if (parent(n)->color == BLACK)
				return;
			else if (uncle(n) != NULL && uncle(n)->color == RED)
			{
				parent(n)->color = BLACK;
				uncle(n)->color = BLACK;
				g = grand_parent(n);
				g->color = RED;
				insert_repare_tree(g);
			}
			else
			{
				p = parent(n);
				g = grand_parent(n);
				if(g->left != NULL && g->left->right != NULL && n == g->left->right)
				{
					rotation_left(p);
					n = n->left;
				}
				else if (g->right != NULL && g->right->left != NULL && n == g->right->left)
				{
					rotation_right(p);
					n = n->right;
				}
				p = parent(n);
				g = grand_parent(n);
				if (n == p->left)
					rotation_right(g);
				else
					rotation_left(g);
				p->color = BLACK;
				g->color = RED;
			}
		}

		BiTreeNode<Key, T> *find(Key key, BiTreeNode<Key, T> *n)
		{
			if (n == NULL)
				return NULL;
			else if (n->data.first == key)
				return n;
			else if (n->data.first >= key)
				return find(key, n->left);
			else if (n->data.first <= key)
				return find(key, n->right);
			return NULL;
		}

	public:
		RBTree(void): _root(NULL) {}
		RBTree(BiTreeNode<Key, T> *n): _root(n) {}
		RBTree(RBTree const &instance) : _root(instance._root) {}
		RBTree &operator=(RBTree const &rhs) { _root = rhs._root; return *this;}

		~RBTree(void) {clear(_root); _root = NULL;}

		BiTreeNode<Key, T> *getRoot()
		{
			return _root;
		}

		BiTreeNode<Key, T> *parent(BiTreeNode<Key, T> *n)
		{
			return n->parent;
		}

		BiTreeNode<Key, T> *grand_parent(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p = parent(n);
			if (p == NULL)
				return NULL;
			return parent(p);
		}

		BiTreeNode<Key, T> *brother(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p = parent(n);
			if (p == NULL)
				return NULL;
			else if (p->left == n)
				return p->right;
			else
				return p->left;
		}
		
		BiTreeNode<Key, T> *uncle(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p = parent(n);
			BiTreeNode<Key, T> *g = grand_parent(n);

			if (g == NULL)
				return NULL;
			return brother(p);
		}

		void rotation_left(BiTreeNode<Key, T> *x)
		{
			BiTreeNode<Key, T> *y = x->right;

			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;

			if (x->parent != NULL)
			{
				if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
			}

			y->left = x;
			x->parent = y;
		}

		void rotation_right(BiTreeNode<Key, T> *x)
		{
			BiTreeNode<Key, T> *y = x->left;

			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->parent = x->parent;

			if (x->parent != NULL)
			{
				if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
			}

			y->right = x;
			x->parent = y;
		}

		BiTreeNode<Key, T> *insert(BiTreeNode<Key, T> *root, BiTreeNode<Key, T> *n)
		{
			recursive_insert(root, n);
			insert_repare_tree(n);
			root = n;
			while(parent(root) != NULL)
				root = parent(root);
			return root;
		}

		void insert(BiTreeNode<Key, T> *n) {
			this->_root = this->insert(this->_root, n);
		}


		BiTreeNode<Key, T> *find(Key key)
		{
			BiTreeNode<Key, T> *tmp = find(key, _root);
			if (tmp == NULL)
				throw std::invalid_argument("no key found");
			return tmp;
		}

		void erase(Key key)
		{
			(void)key;
		}

		void clear(BiTreeNode<Key, T> *n)
		{
			if (n->left != NULL)
			{
				clear(n->left);
				n->left = NULL;
			}
			if (n->right != NULL) {
				clear(n->right);
				n->right = NULL;
			}
			delete n;
		}

		BiTreeNode<Key, T> *createNode(Key key, T val)
		{
			pair<Key, T> p(key, val);
			BiTreeNode<Key, T> *n = new BiTreeNode<Key, T>(NULL, p);
			return n;
		}

		void print_tree(BiTreeNode<Key, T> *n)
		{
			if (n->left != NULL)
				print_tree(n->left);
			if (n != NULL)
				std::cout << "Data:[" << n->data.first << "," << n->data.second << "] | color:" << ((n->color == 0) ? "BLACK" : "RED") << std::endl;
			if (n->right != NULL)
				print_tree(n->right);
		}

};

#endif