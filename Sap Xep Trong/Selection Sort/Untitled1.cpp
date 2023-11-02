#include <iostream>
using namespace std;

void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void SelectionSort (int a[], int n){
	for(int i=0 ; i<n-1 ; i++){
		int min_idx = i;
		for(int j=i+1 ; j<n ; j++)
		if(a[j] < a[min_idx])
			min_idx = j;
		if(min_idx != i)
			swap(&a[min_idx], &a[i]);
	}
}

void printArray(int a[], int n){
	for(int i=0 ; i<n ; i++)
		cout << a[i] << " ";
	cout << endl;
}
	
int main(){
	int a[]={64, 25, 12, 22, 11};
	int n=sizeof(a)/sizeof(a[0]);
	SelectionSort(a, n);
	cout << "Day da sap xep: ";
	printArray(a, n);
}

