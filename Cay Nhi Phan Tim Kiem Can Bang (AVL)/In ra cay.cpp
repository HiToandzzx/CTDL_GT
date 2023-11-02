// Ten: Tran Dai
// Lop: 63_CNTT-1
// MSSV: 63130162

// xay dung cay AVL de luu tru day so sau: 10 20 30 40 50 25
#include<iostream>
using namespace std;
// Cau truc mot nut
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

// Tinh chieu cao cua cay
int height(Node *N)
{
	if(N==NULL) return 0;
	return N->height;
}

// Tim gia tri lon hon giua 2 bien
int max(int a, int b)
{
	return (a>b)?a:b;
}

// Them nut moi
Node* newNode(int key)
{
	Node* node= new Node();
	node->key =key;
	node->left = NULL;
	node->right = NULL;
	node->height =1;
	return(node);
}

// Xoay Phai
Node* rightRotate(Node *y)
{
	Node *x = y->left;
	Node *T2 = x->right;
	// Thuc hien xoay phai
	x->right =y;
	y->left=T2;
	// Cap nhat lai chieu cao cua cay
	y->height = max(height(y->left),height(y->right))+1;
	x->height =max(height(x->left),height(x->right)+1);
	// Tra lai nut moi
	return x;
}
//Xoay trai
Node *leftRotate(Node *x)
{
	Node *y= x->right;
	Node *T2= y->left;
	// Thuc hien xoay trai
	y->left=x;
	x->right =T2;
	// Cap nhatg chieu cao cua cay
	x->height = max(height(x->left),height(x->right)+1);
	y->height = max(height(y->left),height(y->right))+1;
	// tra lai nut goc moi 
	return y;
}

// Tinh muc do can bang cua 1 goc bat ky
int getBalance(Node *N)
{
	if(N==NULL)
		return 0;
	return height(N->left) - height(N->right);
}
// Them nut de tao cay AVL
Node* insert(Node* node, int key)
{
	// Them nut nhu cay BST
	if(node==NULL)
		return (newNode(key));
	if(key<node->key)
		node->left = insert(node->left,key);
	else if(key>node->key)
		node->right = insert(node->right,key);
	else // Khong them nut da co key( cay ko co cac nut cay bang nhau)
		return node;
	
	//Cap nhat chieu cao cay
	node->height =1+ max(height(node->left),height(node->right));
	
	//Tinh muc do can bang
	int balance = getBalance(node);
	//Neu nut ko can bang, xet cac truong hop sau 
	
	
	// LL
	if(balance >1 && key< node->left->key)
		return rightRotate(node);
		
	//RR
	if(balance <-1 && key> node->right->key)
		return leftRotate(node);
		
	//LR
	if(balance >1 && key> node->left->key)
	{
		node->left =leftRotate(node->left);
		return rightRotate(node);	
	}
	
	//RL
	if(balance <-1 && key< node->right->key)
	{
		node->right =rightRotate(node->right);
		return leftRotate(node);	
	}	
	
	// Tra lai con tro cua nut
	return node;
}

int drawHelper(Node *root, int pic[][100], int r, int &c, int &maxRow){
	// Trai - Root - Phai
    if (root!=NULL) {
    	// Duyet trai
	    drawHelper(root->left, pic, r+2, c, maxRow);
	    
	    // them node vao mang
	    pic[r][c] = root->key;
	    
	    // neu co node trai them '/'
	    if (root->left!=NULL) pic[r+1][c-1] = 47;
	       
	    c += 2;
	    
	    // neu co node phai them '\'
	    if (root->right!=NULL) pic[r+1][c] = 92;
		
		// duyet phai 	
   	    drawHelper(root->right, pic, r+2, c, maxRow);
		
		// neu la node la thi vi tri + 3
		if (root->left==NULL && root->right==NULL) c += 3;   
	}
	// hang lon nhat
	maxRow = max(maxRow, r);
}


void draw(Node *root){
	int pic[100][100]={0};
	int r=0;
	int c=0;
	int maxRow=0;
	drawHelper(root, pic,r,c,maxRow);
	for (int i=0; i<=maxRow; i++){
		for (int j=0; j<=c; j++){
			if (pic[i][j]==0) cout<<' ';
			else if (pic[i][j]==47 || pic[i][j]==92) cout << (char) pic[i][j];
			else cout << pic[i][j];
		}
		cout << "\n";
	}
}


// Duyet cay
void preOrder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->key<<"\n";
		preOrder(root->left);	
		preOrder(root->right);
	}
}


int main()
{ 
	Node *root = NULL;
		root = insert(root,3);
		root = insert(root,5);
		root = insert(root,7);
		root = insert(root,23);
		root = insert(root,12);
		root = insert(root,76);
		root = insert(root,87);
		root = insert(root,54);
		root = insert(root,19);
		root = insert(root,4);

	
    draw(root);
	return 0;	
}

