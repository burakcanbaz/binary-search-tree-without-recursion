#include <iostream>
#include "Tree.h"
#include "Tree.cpp"

int main(){

	Tree<int> bst;
	bst.insert(20);  // insert node with given data to binary search tree.
	bst.insert(10);
	bst.insert(35);
	bst.insert(5);
	bst.insert(12);
	bst.insert(34);
	bst.insert(49);
	bst.insert(52);
	bst.insert(47);

	bst.deleteNode(12); // delete node with given data from binary search tree.
	bst.deleteNode(20);

	std::cout << bst.getMaximumKey() << std::endl;  // get maximum key from binary search tree.
	std::cout << bst.getMinimumKey() << std::endl;  // get minimum key from binary search tree.
	std::cout << bst.getSize() << std::endl;  		// get size of binary search tree's nodes.
	std::cout << bst.searchNode(5) << std::endl;	// search node with given data if data exists return true else
	std::cout << bst.searchNode(7) << std::endl;	// throw error and terminate it.


}





