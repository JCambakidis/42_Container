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

		/**
		 * Create node with empty key and data.
		 */
		BiTreeNode(void) : data(Pair()) {}

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