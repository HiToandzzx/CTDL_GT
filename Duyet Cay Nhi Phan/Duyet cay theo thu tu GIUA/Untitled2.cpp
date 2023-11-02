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

void PrintInorder(struct Node* node)
{
	if(node == NULL)
		return;
	PrintInorder(node->left);
	cout << node->data << " ";
	PrintInorder(node->right);
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
	
	cout << "\nInorder traversal of binary tree is: ";
	PrintInorder(root);
	return 0;
}
