#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	string info;
	Node* leftchild;
	Node* rightchild;

	// Constructor for the node class
	Node(string i, Node* l, Node* r)
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree {
public:
	Node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; // Initializing ROOT to NULL
	}
	void insert(string element) // Insert a node in the binary search tree
	{
		Node* newNode = new Node(element, NULL, NULL); // Allocate memory for the new node
		newNode->info = element; // Assign value to the data field of the new node
		newNode->leftchild = NULL; // Make the left child of the new node point to NULL
		newNode->rightchild = NULL; // Make the right child of the new node point NULL

		Node* parent = NULL;
		Node* currentNode = NULL;
		
		search(element, parent, currentNode); // locate the node which be the parent of the node to be inserted

		if (parent == nullptr) // If the parent is NULL (Tree is empty)
		{
			ROOT = newNode; // Mark the new node as ROOT
			return; // EXIT
		}

		if (element < parent->info) // if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = newNode; // Make the left child of the parent point to the new node
		}

		else if (element > parent->info) // If the value in the data field of the new node is grater than that of the parent
		{
			parent->rightchild = newNode; // Make the right child of the parent point to the new node
		}

	}
	void search(string element, Node*& parent, Node*& currentNode)
	{
		currentNode = ROOT;
		parent = nullptr;
		while ((currentNode != nullptr) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}
};
