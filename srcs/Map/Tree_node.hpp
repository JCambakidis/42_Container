#ifndef TREE_BITREENODE_HPP
# define TREE_BITREENODE_HPP

template < class Key, class T >
struct BiTreeNode
{
	BiTreeNode *parent;
	pair<Key, T> data;
	BiTreeNode *left;
	BiTreeNode *right;
	int color;

	BiTreeNode(void) : data(pair<Key, T>()) {}
	BiTreeNode(BiTreeNode *parents, pair<Key, T>datas) : parent(parents), data(datas), left(NULL), right(NULL), color(0) {}
	~BiTreeNode(){}
};

#endif