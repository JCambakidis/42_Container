#ifndef TREE_BITREENODE_HPP
# define TREE_BITREENODE_HPP

namespace ft
{

	/**
	 * Structure of node for red black tree.
	 * 
	 * @tparam Key - type of key
	 * @tparam T - type of datas
	 */

	template < class Pair >
	struct BiTreeNode
	{
		BiTreeNode *parent;
		Pair data;
		BiTreeNode *left;
		BiTreeNode *right;
		int color;

		typedef Pair& reference;
		typedef Pair* pointer;

		/**
		 * Create node with empty key and data.
		 */
		BiTreeNode(void) : data(Pair()) {}

		BiTreeNode(BiTreeNode const &instance): parent(instance.parent), data(instance.data), left(instance.left), right(instance.right), color(instance.color){}

		/**
		 * Create node with parent and datas.
		 * 
		 * @param parents - parent's node of new node
		 * @param datas - new node's datas
		 */
		BiTreeNode(BiTreeNode *parents, Pair datas) : parent(parents), data(datas), left(NULL), right(NULL), color(0) {}

		/**
		 * Destruct node.
		 */
		~BiTreeNode(){}
	};
}

#endif