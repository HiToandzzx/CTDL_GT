#include <iostream>
using namespace std;

void BubbleSort(int a[], int size){
	for(int step=0 ; step<(size-1) ; ++step){
		int swapped = 0;
		for(int i=0 ; i<(size-step-1) ; ++i){
			if(a[i] > a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				swapped = 1;
			}
		}
		if(swapped == 0)
		break;
	}
}

void printArray(int a[], int size){
	for(int i=0 ; i<size ; ++i){
		cout << " " << a[i];
	}
	cout << "\n";
}

int main(){
	int a[]={-2, 45, 0, 11, -9};
	int size=sizeof(a)/sizeof(a[0]);
	
	BubbleSort(a, size);
	
	cout << "Day sap xep tang dan: ";
	printArray(a, size);
}
