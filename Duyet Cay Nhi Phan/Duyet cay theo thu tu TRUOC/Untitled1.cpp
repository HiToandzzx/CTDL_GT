#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void PrintPreorder(struct Node* node)
{
	if(node == NULL)
		return;
	cout << node->data << " ";
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

int main()
{
	
	struct Node* root = newNode(8);
	root->left = newNode(3);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->left->left = newNode(4);
	root->right = newNode(20);
	root->right->left = newNode(11);
	root->right->left->left = newNode(9);
	root->right->left->right = newNode(18);
	root->right->right = newNode(30);

	/*
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(8);
	root->left->right->left->right = newNode(11);
	root->left->right->right = newNode(9);
	
	root->right = newNode(3);
	root->right->right = newNode(7);
	root->right->left = newNode(6);
	root->right->left->right = newNode(10);
	root->right->left->right->right = newNode(12);
	*/
	
	/*
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->left->right = newNode(8);
	root->left->right = newNode(5);
	root->left->right->left = newNode(9);
	root->left->right->right = newNode(10);
	
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(11);
	*/

	cout << "\nPreorder traversal of binary tree is: ";
	PrintPreorder(root);

	return 0;
}
