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

namespace ft
{

	/**
	 * Red Black tree is a kind of self-balancing binary search tree. 
	 * Each node stores an extra bit representing "color" ("red" or "black").
	 * 
	 * @tparam Key - type of node's key
	 * @tparam T - type of node's datas
	 */
	template < class Key, class T, class A = std::allocator< ft::BiTreeNode< ft::pair<const Key, T> > > >
	class RBTree
	{
		public:

	/**
	 * Typedef
	 */

			typedef A allocator_type;
			typedef typename ft::BiTreeNode< ft::pair<const Key, T> > node;
			
		private:
			node *_root;
			node *_emptyNode;
			size_t _size;

	/**
	 * Rotators
	 */

		/**
		 * Rotate left x node.
		 *
		 * @param x node to rotate
		 * @return void
		 */
			void _rotation_left(node *x)
			{
				node *y = x->right;

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
		 * Rotate right x node.
		 *
		 * @param x - node to rotate
		 * @return void
		 */
			void _rotation_right(node *x)
			{
				node *y = x->left;

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
	 * Utils
	 */

		/**
		 * Find the best place of the node "n" and insert it in tree.
		 *
		 * @param root - actual pointer of tree's node
		 * @param n - node to add
		 * @return noid
		 */
			void _recursive_insert(node *root, node *n)
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
		 * Swap two nodes in tree, u and v.
		 *
		 * @param u - first node to swap
		 * @param v - second node to swap
		 * @return void
		 */
			void _swapNodes(node *u, node *v)
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
			node *_find_by_node(Key key, node *n)
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
			node *_insert_by_root_tree(node *root, node *n)
			{
				// Insert the new node in tree, but red black tree condictions are not respected.
				_recursive_insert(root, n);
				_size++;
				// Repare tree after insertion to respect red blakc tree conditions.
				_insert_repare_tree(n);
				root = n;
				// "root" don't point automatically to the root of tree. To return root, we need to move the pointer.
				while(parent(root) != NULL)
					root = parent(root);
				return root;
			}

		/**
		 * Place end node to the end of tree
		 * 
		 * @return void
		 */
			void _replaceNullNode()
			{
				node *tmp = _root;
				if (_emptyNode == NULL)
				{
					_emptyNode = _alloc.allocate(1);
					_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
					_emptyNode->color = -1;
				}
				if (_root == NULL)
				{
					_root = _emptyNode;
					return;
				}
				while (tmp->right != NULL)
					tmp = tmp->right;
				tmp->right = _emptyNode;
				_emptyNode->parent = tmp;
			}

		/**
		 * Detach end node
		 * 
		 * @return void
		 */
			void _detachNullNode()
			{
				if (_emptyNode == NULL)
				{
					_emptyNode = _alloc.allocate(1);
					_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
					_emptyNode->color = -1;
				}
				if (_emptyNode->parent != NULL && _emptyNode->parent->right == _emptyNode)
				{
					_emptyNode->parent->right = NULL;
					_emptyNode->parent = NULL;
				}
				if (_emptyNode == _root)
					_root = NULL;
			}

	/**
	 * Repairer
	 */

		/**
		 * Repare tree after _recursive_insert() to respect Red Black tree conditions.
		 *
		 * @param n - starting node
		 * @return void
		 */
			void _insert_repare_tree(node *n)
			{
				node *p;
				node *g;
				// If the parent of n is NULL, n is root and the root are always black.
				if(parent(n) == NULL || parent(n) == _emptyNode)
				{
					if (parent(n) == _emptyNode)
						_root = n;
					n->color = BLACK;
				}
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
		 * Repare tree after erase to respect red black tree conditions.
		 *
		 * @param n - starting node
		 * @return void
		 */
			void _eraseCorrection(node *n)
			{
				node *tmp = n;
				node *w = n;
				node *p = parent(tmp);
				while (tmp != _root && tmp->color == BLACK && w != NULL)
				{
					if (tmp == p->left)
					{
						// "w" is the brother of "tmp".
						w = p->right;
						// If "w" is red, we need to change his color in black and "p" in red.
						// Rotate "p" to balance the color and key value in left of "p". "tmp" is the new parent of "p".
						// Replace "w" to the right of "p".
						if (w != NULL && w->color == RED)
						{
							w->color = BLACK;
							p->color = RED;
							_rotation_left(p);
							w = p->right;
						}
						if (w != NULL)
						{
							// If left and right of "w" is black, we change the color of "w" to respect color balance.
							if ((w->left == NULL || w->left->color == BLACK) && (w->right == NULL || w->right->color == BLACK))
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
					}
					else
					{
						// "w" is the brother of "tmp".
						w = p->left;
						// If "w" is red, we need to change his color in black and "p" in red.
						// Rotate "p" to balance the color and key value right of "p". "tmp" is the new parent of "p".
						// Replace "w" to the left of "p".
						if (w != NULL && w->color == RED)
						{
							w->color = BLACK;
							p->color = RED;
							_rotation_right(p);
							w = p->left;
						}
						if (w != NULL)
						{
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
								if (w->left != NULL && w->left->color == BLACK)
								{
									if (w->right != NULL)
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
								if (w->left != NULL)
									w->left->color = BLACK;
								_rotation_right(p);
								tmp = _root;
							}
						}
						// If left and right of "w" is black, we change the color of "w" to respect color balance.
					}
				}
				if (tmp->color != -1)
					tmp->color = BLACK;
			}

		private:

			allocator_type _alloc;
		
		public:

	/**
	 * Constructor
	 */

		/**
		 * Empty red black tree constructor.
		 */
			RBTree(const allocator_type& alloc = allocator_type()): _root(NULL), _size(0), _alloc(alloc) 
			{
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

		/**
		 * Construct red black tree whitch n is root.
		 *
		 * @param n - new root of red black tree
		 */
			RBTree(node *n, const allocator_type& alloc = allocator_type()): _root(n), _size(0), _alloc(alloc) 
			{
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

		/**
		 * Construct red black tree whitch root of instance.
		 *
		 * @param instance - instance of tree which is copied
		 */
			RBTree(RBTree const &instance): _root(instance._root), _size(0), _alloc(instance._alloc) 
			{
				_emptyNode = _alloc.allocate(1);
				_alloc.construct(_emptyNode, node(NULL, ft::pair<const Key, T>(1, 0)));
				_emptyNode->color = -1;
			}

		/**
		 * Assign rhs's root in tree root.
		 *
		 * @param rhs - address of red black tree where root is assigned
		 */
			RBTree &operator=(RBTree const &rhs) { _root = rhs._root; _alloc = rhs._alloc; return *this; }

		/**
		 * Destruct red black tree and delete all nodes to free the memory.
		 */
			~RBTree(void) {clear(_root); _root = NULL; }

	/**
	 * Getter
	 */

		/**
		 * Return the root of red black tree.
		 *
		 * @return root of tree
		 */
			node *getRoot() { return _root; }

		/**
		 * Return the empty node.
		 * 
		 * @return emptyNode
		 */
			node *getEmptyNode() { return _emptyNode; }

		/**
		 * Return the size of tree
		 * 
		 * @return size of tree
		 */
			size_t get_size() { return _size; }

		/**
		 * Return the parent of node.
		 *
		 * @param n - node whose parent we want
		 * @return the parent of node
		 */
			node *parent(node *n){ return n->parent; }

		/**
		 * Return the grand parent of node.
		 *
		 * @param n - node whose grand parent we want
		 * @return the grand parent of node
		 */
			node *grand_parent(node *n)
			{
				node *p = parent(n);
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
			node *brother(node *n)
			{
				node *p = parent(n);
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
			node *uncle(node *n)
			{
				node *p = parent(n);
				node *g = grand_parent(n);

				if (g == NULL)
					return NULL;
				return brother(p);
			}

	/**
	 * Modifiers
	 */

		/**
		 * Insert pair "p" in root's tree. 
		 *
		 * @param p - pair we want to insert
		 * @return true if pair are inserted
		 */
			bool insert(ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = NULL;
				if (find(p->first) == NULL)
					tmp = _insert_by_root_tree(_root, createNode(p));
				else
				{
					_replaceNullNode();
					return false;
				}
				if (tmp == NULL)
				{
					_replaceNullNode();
					return false;
				}
				_root = tmp;
				_replaceNullNode();
				return true;
			}

		/**
		 * Insert constant pair "p" in root's tree. 
		 *
		 * @param p - pair we want to insert
		 * @return true if pair are inserted
		 */
			bool insert(const ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = NULL;
				if (find(p->first) == NULL)
					tmp = _insert_by_root_tree(_root, createNode(p));
				else
				{
					_replaceNullNode();
					return false;
				}
				if (tmp == NULL)
				{
					_replaceNullNode();
					return false;
				}
				_root = tmp;
				_replaceNullNode();
				return true;
			}

		/**
		 * Insert pair "p" with position in tree. 
		 * Start insertion from "position".
		 *
		 * @param position - starting node to insert new one
		 * @param p - pair we want to insert
		 * @return true if pair are inserted
		 */
			node *insert(ft::pair<const Key, T> position, const ft::pair<const Key, T> *p) {
				_detachNullNode();
				node *tmp = _insert_by_root_tree(find(position.first), createNode(p));
				_replaceNullNode();
				return tmp;
			}

		/**
		 * Delete the node with key in tree.
		 * After node are deleted, replace the nodes in tree to respect red black tree conditions.
		 * 
		 * @param key - key of node we want to delete
		 * @return true if key was erased
		 */
			bool erase(Key key)
			{
				node *z;
				// "z" the node to delete
				z = find(key);
				node *y = z;
				node *x;
				
				if (z == _emptyNode || z == NULL)
					return false;
				int y_original_color = y->color;
				// If left node of "z" is NULL, we just need to swap "z" with right value of "z"
				if (z->left == NULL)
				{
					x = z->right;
					_swapNodes(z, z->right);
				}
				// If right node of "z" is NULL, we just need to swap "z" with left value of "z"
				else if (z->right == NULL || z->right == _emptyNode)
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
					if (x != NULL && y->parent == z)
						x->parent = y;
					else if (z->right != NULL)
					{
						_swapNodes(y, y->right);
						y->right = z->right;
						if (z->right != NULL)
							z->right->parent = y;
					}
					_swapNodes(z, y);
					y->left = z->left;
					if (y->left != NULL)
						y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				z = NULL;
				_size--;
				_emptyNode->color = -1;
				if (y->color == -1 && y->parent != _root)
				{
					y->parent->right = y->left;
					y->left->parent = y->parent;
					y->left = NULL;
					y->right = NULL;
				}
				// Correct the tree from "x", "x" is the node from which the modification of the tree started.
				if (y_original_color == BLACK && x != NULL)
					_eraseCorrection(x);
				_detachNullNode();
				_replaceNullNode();
				return true;
			}

		/**
		 * Delete all nodes from n in tree to free the memory.
		 * 
		 * @param n - starting node, must be not NULL
		 * @return void
		 */
			void clear(node *n)
			{
				if (n != NULL)
				{
					if (n->color != -1)
					{
						if (n->left != NULL)
							clear(n->left);
						if (n->right != NULL)
							clear(n->right);
						if (n == _root)
						{
							_alloc.destroy(_root);
							_alloc.deallocate(_root, 1);
							_root = NULL;
						}
						else
						{
							_alloc.destroy(n);
							_alloc.deallocate(n, 1);
							n = NULL;
						}
					}
				}
				_alloc.destroy(_emptyNode);
				_alloc.deallocate(_emptyNode, 1);
				_emptyNode = NULL;
			}

	/**
	 * Lookup
	 */

		/**
		 * Find node with key value.
		 *
		 * @param key - key of pair we want to find
		 * @throw std::invalid_argument - Throw if no node are found
		 * @return node finded
		 */
			node *find(Key key)
			{
				node *tmp = _find_by_node(key, _root);
				return tmp;
			}

		/**
		 * Find minimum key value of node from node n.
		 * 
		 * @param n - starting node, must be not NULL
		 * @return node finded
		 */
			node *find_min(node *n)
			{
				assert(n != NULL);
				node *tmp = n;
				while (tmp->left != NULL)
					tmp = tmp->left;
				return tmp;
			}

		/**
		 * Find maximum key value of node from node n.
		 * 
		 * @param n - starting node, must be not NULL
		 * @return node finded
		 */
			node *find_max(node *n)
			{
				assert(n != NULL);
				node 	*tmp = n;
				while (tmp->right != NULL && tmp->right->color != -1)
					tmp = tmp->right;
				return tmp;
			}
		/**
		 * Create new node object with key and data.
		 * 
		 * @param p - data of new node
		 * @return pointer of node created. No linked Node with key and val
		 */
		node *createNode(const ft::pair<const Key, T> *p)
		{
			node *n = _alloc.allocate(1);
			_alloc.construct(n, node(NULL, *p));
			return n;
		}
	};


	/**
	 * Print on standard output the datas and color of nodes from node n
	 * 
	 * @param n - stating node
	 * @return void
	 */
	template < class Key, class T >
	void print_tree(ft::BiTreeNode< ft::pair<const Key, T> > *n)
	{
		if (n != NULL)
		{
			if (n->left != NULL)
				print_tree(n->left);
			if (n != NULL && n->color != -1)
				std::cout << "Data:[" << n->data.first << "," << n->data.second << "] | color:" << ((n->color == 0) ? "BLACK" : "RED") << std::endl;
			if (n->right != NULL)
				print_tree(n->right);
		}
	}
}

#endif