#include <iostream>
using namespace std;

void merge(int a[], int const left, int const mid, int const right){
	auto const subArrayOne = mid-left+1;
	auto const subArrayTwo = right-mid;
	auto *leftArray = new int(subArrayOne),
		 *rightArray = new int(subArrayTwo);
	for (auto i=0 ; i<subArrayOne ; i++)
		leftArray[i] = a[left+i];
	for (auto j=0 ; j<subArrayTwo ; j++)
		rightArray[j] = a[mid+1+j];
	auto indexOfSubArrayOne=0, indexOfSubArrayTwo=0;
	int indexOfMergedArray=left;
	while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
		if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]){
			a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else{
			a[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	while (indexOfSubArrayOne < subArrayOne){
		a[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	while (indexOfSubArrayTwo < subArrayTwo){
		a[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] leftArray;
	delete[] rightArray;
}

void mergeSort(int a[], int const begin, int const end){
	if (begin >= end)
		return;
	
	auto mid = begin+(end-begin)/2;
	mergeSort(a, begin, mid);
	mergeSort(a, mid+1, end);
	merge(a, begin, mid, end);
}

void printArray(int a[], int size){
	for(auto i=0 ; i<size ; i++)
	cout << a[i] << " ";
}

int main(){
	int a[] = {12, 11, 13, 5, 6, 7};
	auto a_size=sizeof(a)/sizeof(a[0]);
	
	cout<<"Day can sap xep: ";
	printArray(a, a_size);
	
	mergeSort(a, 0, a_size-1);
	
	cout << "\nDay da sap xep: ";
	printArray(a, a_size);
	return 0;
}
