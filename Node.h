#ifndef NODE_H_
#define NODE_H_

template<typename T>
struct Node{

	T data;
	Node<T>* leftChild;
	Node<T>* rightChild;
	//Node() = default;
	Node(T data, Node<T>* rightChild, Node<T>* leftChild)
	:data{data},leftChild{nullptr},rightChild{nullptr}{}
	~Node(){

		delete leftChild;
		delete rightChild;

	}

};


#endif
