#include <stdio.h>


struct Node{
    int data;
    struct Node *next;
 };
 
void InNode(Node *n){
	while (n != NULL){
 		printf("%5d",n->data);
 		n=n->next;
	 }
 }
 
int main(){
 	Node* head = NULL;
 	Node* second = NULL;
 	Node* third = NULL;
 	
 	head = new Node();
 	second = new Node();
 	third = new Node();
 	
 	head->data = 1;
 	head->next = second;
 	
 	second->data = 2;
 	second->next = third;
 	
 	third->data = 3;
 	third->next = NULL;
 	
 	InNode(head);
 	return 0;
}
 
void ChenVaoDau(Node** head, int newdata){
	Node* newnode = new Node();
	newnode->data = newdata;
	newnode->next = (*head);
	(*head) = newnode;
}
