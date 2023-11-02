#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left, * right;
};

Node* NewNode(int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

Node* InsertLevelOrder(int a[], int i, int n){
	Node *root = nullptr;
	if(i<n){
		root = NewNode(a[i]);
		root->left = InsertLevelOrder(a, 2 * i +1, n);
		root->right = InsertLevelOrder(a, 2 * i + 2, n);
	}
	return root;
}

void InOrder(Node* root){
	if(root != NULL){
		InOrder(root->left);
		cout << root->data << " ";
		InOrder(root->right);
	}
}

int main(){
	int a[] = {1,2,3,4,5,6,6,6,6};
	int n = sizeof(a)/sizeof(a[0]);
	Node* root = InsertLevelOrder(a, 0, n);
	InOrder(root);
}
