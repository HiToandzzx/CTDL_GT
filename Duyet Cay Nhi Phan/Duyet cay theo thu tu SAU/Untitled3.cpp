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

void PrintPostorder(struct Node* node)
{
	if(node == NULL)
		return;
	PrintPostorder(node->left);
	PrintPostorder(node->right);
	cout << node->data << " ";
}

int main()
{
	struct Node* root = newNode('J');
	root->left = newNode('D');
	root->left->left = newNode('A');
	root->left->right = newNode('G');
	root->left->right->left = newNode('E');
	root->left->right->left->right = newNode('F');
	root->left->right->right = newNode('H');
	
	root->right = newNode('R');
	root->right->right = newNode('T');
	root->right->left = newNode('M');
	root->right->left->right = newNode('P');
	root->right->left->right->right = newNode('Q');
	
	cout << "\nPostorder traversal of binary tree is: ";
	PrintPostorder(root);
	return 0;
}
