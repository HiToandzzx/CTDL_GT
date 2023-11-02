#include <iostream>

using namespace std;

struct node{
	int key;
	struct node *left, *right;
};

//TAO NUT
struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

//DUYET CAY
void inorder(struct node *root){
	if(root != NULL){
		//Duyet trai
		inorder(root->left);
		//Duyet goc
		cout << root->key << " -> ";
		//Duyet phai
		inorder(root->right);
	}
}

//CHEN NUT
struct node *insert(struct node *node, int key){
	//Tao nut moi neu cay rong
	if(node == NULL)
		return newNode(key);
	if(key < node->key)
		node->left = insert(node->left, key);
	else 
		node->right = insert(node->right, key);
	return node;
}

//TIM NUT SUCCESSOR
struct node *minValueNode(struct node *node){
	struct node *current = node;
	//Tim nut cuc trai
	while(current && current->left != NULL)
		current = current->left;
	return current;
}

//XOA NUT
struct node *deleteNode(struct node *root, int key){
	//Neu cay rong
	if(root == NULL)
		return root;
	//Tim nut can xoa
	if(key < root->key)
		root->left = deleteNode(root->left, key);
	else if(key > root->key)
		root->right = deleteNode(root->right, key);
	else{
		//Neu nut can xoa chi co 1 nut hoac khong co nut con
		if(root->left == NULL){
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL){
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		
		//Neu nut can xoa co 2 nut con
		struct node *temp = minValueNode(root->right);
		
		//Thay nut successor vao vi tri nut can xoa
		root->key = temp->key;
		
		//Xoa nut successor cu
		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}

int main(){
	struct node *root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);	
	
	cout << "Duyet cay: ";
	inorder(root);
	
	cout << "\nSau khi xoa nut 7: \n";
	root = deleteNode(root, 7);
	
	cout << "Duyet lai cay: ";
	inorder(root);
}
