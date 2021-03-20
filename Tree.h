#ifndef TREE_H_
#define TREE_H_
#include "Node.h"

template<typename T>
class Tree{

	Node<T>* root = nullptr;
	Node<T>* current = nullptr;
	int size = 0;

	Node<T>* inOrderSuccessor(T data);

	Node<T>* search(T data);



public:

	~Tree();
	Tree() = default;

	int getSize();
	bool searchNode(T data);

	Tree<T>& insert(T data);
	Tree<T>& deleteNode(T data);

	T getMinimumKey();
	T getMaximumKey();

};


#endif
