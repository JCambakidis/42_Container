#ifndef TREE_BITREENODE_HPP
# define TREE_BITREENODE_HPP

/**
 * Structure of node for red black tree.
 * 
 * @tparam Key - type of key
 * @tparam T - type of datas
 */

template < class Key, class T >
struct BiTreeNode
{
	BiTreeNode *parent;
	pair<Key, T> data;
	BiTreeNode *left;
	BiTreeNode *right;
	int color;

	/**
	 * Create node with empty key and data.
	 */
	BiTreeNode(void) : data(pair<Key, T>()) {}

	/**
	 * Create node with parent and datas.
	 * 
	 * @param parents - parent's node of new node
	 * @param datas - new node's datas
	 */
	BiTreeNode(BiTreeNode *parents, pair<Key, T>datas) : parent(parents), data(datas), left(NULL), right(NULL), color(0) {}

	/**
	 * Destruct node.
	 */
	~BiTreeNode(){}
};

#endif