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

/**
 * Red Black tree is a kind of self-balancing binary search tree. 
 * Each node stores an extra bit representing "color" ("red" or "black").
 * 
 * @tparam Key - type of nodes key
 * @tparam T - type of nodes datas
 */

template < class Key, class T >
class RBTree
{
	private:
		BiTreeNode<Key, T> *_root;

	/**
	 * Rotate left node of x with x.
	 *
	 * @param x node to rotate
	 * @return void
	 */

		void _rotation_left(BiTreeNode<Key, T> *x)
		{
			BiTreeNode<Key, T> *y = x->right;

			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;

			y->parent = x->parent;

			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;

			y->left = x;
			x->parent = y;
		}

	/**
	 * Rotate right node of x with x.
	 *
	 * @param x - node to rotate
	 * @return void
	 */

		void _rotation_right(BiTreeNode<Key, T> *x)
		{
			BiTreeNode<Key, T> *y = x->left;

			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;

			y->parent = x->parent;

			if (x->parent == NULL)
				_root = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;

			y->right = x;
			x->parent = y;
		}

	/**
	 * Find the best place of node key and insert node in root tree.
	 *
	 * @param root - actual pointer of tree's node
	 * @param n - node to add
	 * @return noid
	 */

		void _recursive_insert(BiTreeNode<Key, T> *root, BiTreeNode<Key, T> *n)
		{
			if (root != NULL)
			{
				// If the key of "n" are smaller than "root" we search in left of node pointed by "root".
				if (n->data.first < root->data.first)
				{
					if (root->left != NULL)
					{
						_recursive_insert(root->left, n);
						return;
					}
					else
						root->left = n;
				}
				// If the key of "n" are bigger or equal than "root" we search in right of node pointed by "root".
				else
				{
					if (root->right != NULL)
					{
						_recursive_insert(root->right, n);
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

	/**
	 * Repare tree after _recursive_insert() to respect Red Black tree conditions.
	 *
	 * @param n - starting node
	 * @return void
	 */

		void _insert_repare_tree(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p;
			BiTreeNode<Key, T> *g;
			// If the parent of n is NULL, n is root and the root are always black.
			if(parent(n) == NULL)
				n->color = BLACK;
			// If the parent of n is black, we do nothing.
			else if (parent(n)->color == BLACK)
				return;
			// If the uncle is red, the uncle and parent is change to black and the grand parent is change to red
			// to respect the balance of colors in red black tree.
			else if (uncle(n) != NULL && uncle(n)->color == RED)
			{
				parent(n)->color = BLACK;
				uncle(n)->color = BLACK;
				g = grand_parent(n);
				g->color = RED;
				_insert_repare_tree(g);
			}
			else
			{
				p = parent(n);
				g = grand_parent(n);
				// If parent is red, we need to rotate parent node to balance the tree and change the colors of nodes
				if(g->left != NULL && g->left->right != NULL && n == g->left->right)
				{
					_rotation_left(p);
					n = n->left;
				}
				else if (g->right != NULL && g->right->left != NULL && n == g->right->left)
				{
					_rotation_right(p);
					n = n->right;
				}
				p = parent(n);
				g = grand_parent(n);
				if (n == p->left)
					_rotation_right(g);
				else
					_rotation_left(g);
				p->color = BLACK;
				g->color = RED;
			}
		}

	/**
	 * Swap two nodes in tree, u and v.
	 *
	 * @param u - first node to swap
	 * @param v - second node to swap
	 * @return void
	 */

		void _swapNodes(BiTreeNode<Key, T> *u, BiTreeNode<Key, T> *v)
		{
			if (u->parent == NULL)
				_root = v;
			else if (u == parent(u)->left)
				parent(u)->left = v;
			else
				parent(u)->right = v;
			if (u->parent == NULL)
				v->parent = NULL;
			else if (v != NULL)
				v->parent = u->parent;
		}

	/**
	 * Find the node with key number from n.
	 *
	 * @param key - the key to find
	 * @param n - starting node
	 * @return findinged node
	 */

		BiTreeNode<Key, T> *_find_by_node(Key key, BiTreeNode<Key, T> *n)
		{
			if (n == NULL)
				return NULL;
			else if (n->data.first == key)
				return n;
			else if (n->data.first >= key)
				return _find_by_node(key, n->left);
			else if (n->data.first <= key)
				return _find_by_node(key, n->right);
			return NULL;
		}

	/**
	 * Insert in root of red black tree the node n recurcively and repare it to respect red black tree conditions.
	 *
	 * @param root - root of tree in whitch we want to insert the node
	 * @param n - node to insert
	 * @return new root with node n inserted
	 */

		BiTreeNode<Key, T> *_insert_by_root_tree(BiTreeNode<Key, T> *root, BiTreeNode<Key, T> *n)
		{
			// Insert the new node in tree, but red black tree condictions are not respected.
			_recursive_insert(root, n);
			// Repare tree after insertion to respect red blakc tree conditions.
			_insert_repare_tree(n);
			root = n;
			// "root" don't point automatically to the root of tree. To return root, we need to move the pointer.
			while(parent(root) != NULL)
				root = parent(root);
			return root;
		}

	/**
	 * Repare tree after erase to respect red black tree conditions.
	 *
	 * @param n - starting node
	 * @return void
	 */

		void _eraseCorrection(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *tmp = n;
			BiTreeNode<Key, T> *w = n;
			BiTreeNode<Key, T> *p = parent(tmp);
			while (tmp != _root && tmp->color == BLACK)
			{
				if (tmp == p->left)
				{
					// "w" is the brother of "tmp".
					w = p->right;
					// If "w" is red, we need to change his color in black and "p" in red.
					// Rotate "p" to balance the color and key value in left of "p". "tmp" is the new parent of "p".
					// Replace "w" to the right of "p".
					if (w->color == RED)
					{
						w->color = BLACK;
						p->color = RED;
						_rotation_left(p);
						w = p->right;
					}
					// If left and right of "w" is black, we change the color of "w" to respect color balance.
					if (w->left->color == BLACK && w->right->color == BLACK)
					{
						w->color = RED;
						tmp = p;
					}
					else
					{
						// If "w" right is black, we need to change left color in black and "w" in red.
						// Rotate "w" to balance the color and keys values in right link of "w".
						// Replace "w" to the right of "p" after rotation.
						if (w->right->color == BLACK)
						{
							w->left->color = BLACK;
							w->color = RED;
							_rotation_right(w);
							w = p->right;
						}
						// If "w" color is black, "p" color is red, to respect the color conditions of tree,
						// we change the colors of "w", "p" and right of "w".
						// Rotate "p" to balance the lefts values of "p", to respect colors and keys conditions of tree.
						w->color = p->color;
						p->color = BLACK;
						w->right->color = BLACK;
						_rotation_left(p);
						tmp = _root;
					}
				}
				else
				{
					// "w" is the brother of "tmp".
					w = p->left;
					// If "w" is red, we need to change his color in black and "p" in red.
					// Rotate "p" to balance the color and key value right of "p". "tmp" is the new parent of "p".
					// Replace "w" to the left of "p".
					if (w->color == RED)
					{
						w->color = BLACK;
						p->color = RED;
						_rotation_right(p);
						w = p->left;
					}
					// If left and right of "w" is black, we change the color of "w" to respect color balance.
					if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))
					{
						w->color = RED;
						tmp = p;
					}
					else
					{
						// If "w" left is black, we need to change right color in black and "w" in red.
						// Rotate "w" to balance the color and keys values in left link of "w".
						// Replace "w" to the left of "p" after rotation.
						if (w->left->color == BLACK)
						{
							w->right->color = BLACK;
							w->color = RED;
							_rotation_left(w);
							w = p->left;
						}
						// If "w" color is black, "p" color is red, to respect the color conditions of tree,
						// we change the colors of "w", "p" and left of "w".
						// Rotate "p" to balance the rights values of "p", to respect colors and keys conditions of tree.
						w->color = p->color;
						p->color = BLACK;
						w->left->color = BLACK;
						_rotation_right(p);
						tmp = _root;
					}
				}
			}
			tmp->color = BLACK;
		}

	public:

	/**
	 * Empty red black tree constructor.
	 */
		RBTree(void): _root(NULL) {}

	/**
	 * Construct red black tree whitch n is root.
	 *
	 * @param n - new root of red black tree
	 */
		RBTree(BiTreeNode<Key, T> *n): _root(n) {}

	/**
	 * Construct red black tree whitch root of instance.
	 *
	 * @param instance - instance of tree which is copied
	 */
		RBTree(RBTree const &instance) : _root(instance._root) {}

	/**
	 * Assign rhs's root in tree root.
	 *
	 * @param rhs - address of red black tree where root is assigned
	 */
		RBTree &operator=(RBTree const &rhs) { _root = rhs._root; return *this; }

	/**
	 * Destruct red black tree and delete all nodes to free the memory.
	 */

		~RBTree(void) {clear(_root); _root = NULL; }

	/**
	 * Return the root of red black tree.
	 *
	 * @return root of tree
	 */

		BiTreeNode<Key, T> *getRoot() { return _root; }

	/**
	 * Return the parent of node.
	 *
	 * @param n - node whose parent we want
	 * @return the parent of node
	 */

		BiTreeNode<Key, T> *parent(BiTreeNode<Key, T> *n){ return n->parent; }

	/**
	 * Return the grand parent of node.
	 *
	 * @param n - node whose grand parent we want
	 * @return the grand parent of node
	 */

		BiTreeNode<Key, T> *grand_parent(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p = parent(n);
			if (p == NULL)
				return NULL;
			return parent(p);
		}

	/**
	 * Return the brother of node.
	 *
	 * @param n - node whose brother we want
	 * @return the brother of node
	 */


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

	/**
	 * Return the uncle of node.
	 *
	 * @param n - node whose uncle we want
	 * @return the uncle of node
	 */

		
		BiTreeNode<Key, T> *uncle(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> *p = parent(n);
			BiTreeNode<Key, T> *g = grand_parent(n);

			if (g == NULL)
				return NULL;
			return brother(p);
		}

	/**
	 * Insert node in tree.
	 *
	 * @param n - node we want to insert
	 * @return void
	 */

		void insert(BiTreeNode<Key, T> *n) {
			_root = _insert_by_root_tree(_root, n);
		}

	/**
	 * Find the node with key value.
	 *
	 * @param key - key of node we want to find
	 * @throw std::invalid_argument - Throw if no node are found
	 * @return node finded
	 */

		BiTreeNode<Key, T> *find(Key key)
		{
			BiTreeNode<Key, T> *tmp = _find_by_node(key, _root);
			if (tmp == NULL)
				throw std::invalid_argument("no key found");
			return tmp;
		}

	/**
	 * Delete the node with key in tree.
	 * After node are deleted, replace the nodes in tree to respect red black tree conditions.
	 * 
	 * @param key - key of node we want to delete
	 * @return void
	 */

		void erase(Key key)
		{
			// "z" the node to delete
			BiTreeNode<Key, T> *z = find(key);
			BiTreeNode<Key, T> *y = z;
			BiTreeNode<Key, T> *x;
			int y_original_color = y->color;
			
			// If left node of "z" is NULL, we just need to swap "z" with right value of "z"
			if (z->left == NULL)
			{
				x = z->right;
				_swapNodes(z, z->right);
			}
			// If right node of "z" is NULL, we just need to swap "z" with left value of "z"
			else if (z->right == NULL)
			{
				x = z->left;
				_swapNodes(z, z->left);
			}
			else
			{
				// Find the next value of "z" to replace it
				y = find_min(z->right);
				y_original_color = y->color;
				x = y->right;
				// Swap node "z" and "y"
				if (y->parent == z)
					x->parent = y;
				else
				{
					_swapNodes(y, y->right);
					y->right = z->right;
					y->right->parent = y;
				}
				_swapNodes(z, y);
				y->left = z->left;
				if (y->left != NULL)
					y->left->parent = y;
				y->color = z->color;
			}
			delete z;
			z = NULL;
			// Correct the tree from "x", "x" is the node from which the modification of the tree started.
			if (y_original_color == BLACK)
				_eraseCorrection(x);
		}

	/**
	 * Find minimum key value of node from node n.
	 * 
	 * @param n - starting node, must be not NULL
	 * @return node finded
	 */

		BiTreeNode<Key, T> *find_min(BiTreeNode<Key, T> *n)
		{
			BiTreeNode<Key, T> 	*min_left = NULL;
			BiTreeNode<Key, T> 	*min_right = NULL;
			BiTreeNode<Key, T> 	*tmp = n;

			assert(n != NULL);

			if (tmp->left != NULL)
				min_left = find_min(tmp->left);
			if (tmp->right != NULL)
				min_right = find_min(tmp->right);

			if (min_left == NULL && min_right != NULL)
				return (tmp->data.first < min_right->data.first) ? tmp : min_right;
			else if (min_right == NULL && min_left != NULL)
				return (tmp->data.first < min_left->data.first) ? tmp : min_left;
			else
			{
				if (min_left != NULL && min_left->data.first < tmp->data.first)
					tmp = min_left;
				if (min_right != NULL && min_right->data.first <tmp->data.first)
					tmp = min_right;
			}
			return tmp;
		}

	/**
	 * Delete all nodes from n in tree to free the memory.
	 * 
	 * @param n - starting node, must be not NULL
	 * @return void
	 */

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

	/**
	 * Create new node object with key and data.
	 * 
	 * @param key - key of new node in tree
	 * @param val - datas of new node
	 * @return new node with key and val and without links
	 */

		BiTreeNode<Key, T> *createNode(Key key, T val)
		{
			pair<Key, T> p(key, val);
			BiTreeNode<Key, T> *n = new BiTreeNode<Key, T>(NULL, p);
			return n;
		}

	/**
	 * Print on standard output the datas and color of nodes from node n
	 * 
	 * @param n - stating node
	 * @return void
	 */

		void print_tree(BiTreeNode<Key, T> *n)
		{
			if (n != NULL)
			{
				if (n->left != NULL)
					print_tree(n->left);
				if (n != NULL)
					std::cout << "Data:[" << n->data.first << "," << n->data.second << "] | color:" << ((n->color == 0) ? "BLACK" : "RED") << std::endl;
				if (n->right != NULL)
					print_tree(n->right);
			}
		}
};

#endif