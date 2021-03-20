#include <iostream>
#include "Tree.h"

template<typename T>
Tree<T>::~Tree(){

	delete root;

}

template<typename T>
Node<T>* Tree<T>::inOrderSuccessor(T data){

	if(root == nullptr)
		throw std::invalid_argument("No element in list");

	Node<T>* foundNode = search(data);

	if(foundNode->rightChild != nullptr){
		foundNode = foundNode->rightChild;
		while(foundNode->leftChild != nullptr)
			foundNode = foundNode->leftChild;
		return foundNode;
	}

}

template<typename T>
Node<T>* Tree<T>::search(T data){

	if(root == nullptr){
		throw std::invalid_argument("There is no element in binary tree.");
	}

	if(root->data == data){
		return root;
	}

	Node<T>* temp = root;

	while(temp->data != data){

		if(data > temp->data)
			temp = temp->rightChild;
		else
			temp = temp->leftChild;
		if(temp->rightChild == nullptr && temp->leftChild == nullptr )
			break;

	}

	if(temp->data == data)
		return temp;
	else
		throw std::invalid_argument("There is no node with given data");

}

template<typename T>
int Tree<T>::getSize(){
	return this->size;
}

template<typename T>
bool Tree<T>::searchNode(T data){

	T searchFound = search(data)->data;
	if(searchFound != T{} )
		return true;
	else
		return false;

}


template<typename T>
Tree<T>& Tree<T>::insert(T data){

	if(root == nullptr){
		root = new Node<T>(data,nullptr,nullptr);
		size++;
		return *this;
	}

	current = root;

	Node<T>* parent = nullptr;

	while(current != nullptr){
		parent = current;
		if(data > current->data)
			current = current->rightChild;
		else
			current = current->leftChild;
	}

	if(data > parent->data)
		parent->rightChild = new Node<T>(data,nullptr,nullptr);
	else
		parent->leftChild = new Node<T>(data,nullptr,nullptr);

	size++;
	return *this;

}

template<typename T>
Tree<T>& Tree<T>::deleteNode(T data){

	if(root == nullptr)
		throw std::invalid_argument("No element in list.");

	Node<T>* parent = nullptr;
	current = root;
	while(current->data != data){
		parent = current;
		if(current->data < data)
			current = current->rightChild;
		else
			current = current->leftChild;
	}
	//deleting leaf
	if(current->leftChild == nullptr && current->rightChild == nullptr){

		if(parent->leftChild == current)
			parent->leftChild = nullptr;
		else
			parent->rightChild = nullptr;

		delete current;
		current = nullptr;
		size--;
		return *this;
	}
	//deleting 2 child node
	else if(current->leftChild != nullptr && current->rightChild != nullptr){

		Node<T>* successor = inOrderSuccessor(data);
		Node<T>* child = (successor->leftChild)? successor->leftChild: successor->rightChild;
		T val = successor->data;
		Node<T>* temp = current;
		while(temp != successor){
			parent = temp;
			if(successor->data < temp->data)
				temp = temp->leftChild;
			else
				temp = temp->rightChild;
		}
		if(parent->rightChild == temp)
			parent->rightChild = child;
		else
			parent->leftChild = child;

		delete temp;
		temp = nullptr;
		current->data = val;
		size--;
		return *this;

	}

	else{//delete 1 child node

		if(current->rightChild != nullptr)
			parent->rightChild = current->rightChild;
		else
			parent->leftChild = current->leftChild;
		delete current;
		current = nullptr;
		size--;
		return *this;

	}

}

template<typename T>
T Tree<T>::getMinimumKey(){

	if(root == nullptr){
		throw std::invalid_argument("No element in list.");
	}
	current = root;

	while(current->leftChild != nullptr)
		current = current->leftChild;

	return current->data;

}

template<typename T>
T Tree<T>::getMaximumKey(){

	if(root == nullptr)
		throw std::invalid_argument("No element in list");

	current = root;

	while(current->rightChild != nullptr)
		current = current->rightChild;

	return current->data;

}



