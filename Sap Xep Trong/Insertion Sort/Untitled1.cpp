#include <iostream>
using namespace std;

void InsertionSort(int a[], int n){
	for(int i=1 ; i<n ; i++){
		int key = a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
}
	
void printArray(int a[], int n){
	for(int i=0 ; i<n ; i++)
		cout << a[i] <<" ";
	cout << endl;
}

int main(){
	int a[]={5, 2, 4, 6, 1, 3};
	int n=sizeof(a)/sizeof(a[0]);
	InsertionSort(a, n);
	cout << "Day da sap xep: ";
	printArray(a, n);
	return 0;
}
