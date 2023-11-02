#include <iostream>
using namespace std;

void heapify(int a[], int N, int i){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if(l<N && a[l] > a[largest])
		largest = l;
	if(r<N && a[r] > a[largest])
		largest = r;
	if(largest != i){
		swap(a[i], a[largest]);
		heapify(a, N, largest);
	}
}

void heapSort(int a[], int N){
	for(int i=N/2-1 ; i>=0 ; i--)
		heapify(a, N, i);
	for(int i=N-1 ; i>0 ; i--){
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}

void printArray(int a[], int N){
	for(int i=0 ; i<N ; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
	int a[] = {12, 11, 13, 5, 6, 7};
	int N=sizeof(a)/sizeof(a[0]);
	heapSort(a, N);
	cout << "Day da sap xep: ";
	printArray(a, N);
}
