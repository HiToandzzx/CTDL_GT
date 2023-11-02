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

void PrintInorder(struct Node* node)
{
	if(node == NULL)
		return;
	PrintInorder(node->left);
	cout << node->data << " ";
	PrintInorder(node->right);
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
	struct Node* root = newNode(19); 				//1
	root->left = newNode(9); 						//2
	root->right = newNode(50); 						//2
	root->left->left = newNode(2); 					//3
	root->left->right = newNode(10); 				//3
	root->right->left = newNode(35); 				//3
	root->right->right = newNode(56); 				//3
	root->left->left->left = newNode(1); 			//4
	root->left->left->right = newNode(3); 			//4
	root->right->left->left = newNode(22); 			//4
	root->right->left->right = newNode(37); 		//4
	root->right->right->left = newNode(51); 		//4
	root->right->right->right = newNode(70); 		//4
	root->right->left->left->left = newNode(21); 	//5
	root->right->left->left->right = newNode(25); 	//5
	root->right->right->right->left = newNode(61); 	//5
	root->right->right->right->right = newNode(81); //5
	cout << "\nPreorder traversal of binary tree is: ";
	PrintPreorder(root);
	cout << "\n";
	
	cout << "\nInorder traversal of binary tree is: ";
	PrintInorder(root);
	cout << "\n";
	
	cout << "\nPostorder traversal of binary tree is: ";
	PrintPostorder(root);
	cout << "\n";
	return 0;
}
