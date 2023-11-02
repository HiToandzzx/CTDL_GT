#include <iostream>
using namespace std;

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

int partition(int a[], int low, int high){
	int pivot = a[high];
	int i = (low-1);
	
	for(int j=low ; j<=high ; j++){
		if(a[j] < pivot){
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[high]);
	return (i+1);
}

void QuickSort(int a[], int low, int high){
	if(low < high){
		int pi = partition(a, low, high);
		QuickSort(a, low, pi-1);
		QuickSort(a, pi+1, high);
	}
}

void printArray(int a[], int n){
	for(int i=0 ; i<n ; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {10, 7, 8, 9, 1, 5};
	int n=sizeof(a)/sizeof(a[0]);
	QuickSort(a, 0, n-1);
	cout << "Day da sap xep: ";
	printArray(a, n);
	return 0;
}
