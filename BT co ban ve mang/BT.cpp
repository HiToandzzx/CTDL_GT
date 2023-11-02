//Ho ten: NGUYEN HUY TOAN
//MSSV: 63135741
//Lop: 63.CNTT-1

#include <stdio.h>
#define MAX 20

void NhapMang(int a[], int &n) {   
    do{  
		printf("Nhap so luong phan tu 1<= n <=20: "); 
        scanf("%d", &n);
    }while((n<1) || ( n>20));
    for(int i=0 ; i<n ; i++) {    
		printf("Phan tu thu A[%d]: ", i);
        scanf("%d",&a[i]);
 	}
}

void XuatMang (int a[], int &n){
	for (int i=0 ; i<n ; i++){
			printf("%5d ", a[i]);
	}
}
 
//TIM KIEM PHAN TU
void FindIndex(int a[], int n, int phantu){
	int find;
    for(int i=0; i<n ; i++){
        if(phantu==a[i]){
            find=i;
            break;
        }
    }
    	//if(find != NULL || find >= 0){
    	if(find>0){
        	printf("Tim thay phan tu %d tai vi tri %d", phantu, find);
    	}else{
        	printf("Khong tim thay phan tu %d", phantu);
    	}
}

//THEM PHAN TU
void InsertIndex(int a[], int index, int phantu, int &n){
    if(index <= 0){
        index = 0;
    }
    if(index >= n){
        index = n;
    }
    for(int i=n ; i>index ; i--){
        a[i] = a[i-1];
    }
    a[index] = phantu;
    n++;
}

//XOA PHAN TU
void DeleteIndex(int a[], int &n, int index){
    if(index < 0){
        index = 0;
    }
    if(index >= n){
        index = n-1;
    }
    for(int i=index ; i<n-1; i++){
        a[i] = a[i+1];
    }
    n--;
}

//SX TANG DAN
void SXTangDan(int a[], int &n){
    int tam;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                tam = a[i];
                a[i] = a[j];
                a[j] = tam;
            }
        }
    }
}

int main() {   
    int a[MAX], n;
    NhapMang(a, n); 
    printf("\nMang vua nhap la: ");
    XuatMang(a,n);
    
//TIM PHAN TU
	int phantu;
    printf("\nNhap phan tu can tim kiem: ");
    scanf("%d",&phantu);
    FindIndex(a,n,phantu);
    
//THEM PHAN TU    
    //Them Phan tu
	int PhanTu;
	printf("\n");
    printf("\nNhap phan tu can them: ");
    scanf("%d",&PhanTu);
    //Vi tri can them
    int index;
	    printf("Nhap vi tri can them: ");
	    scanf("%d",&index);
    InsertIndex(a, index, PhanTu, n);
    printf("Mang sau khi them phan tu %d la: ",PhanTu);
    XuatMang(a,n);
    
//XOA PHAN TU
	int INDEX;
	printf("\n");
    printf("\nNhap vi tri can xoa: ");
    scanf("%d",&INDEX);
    DeleteIndex(a, n, INDEX);
    printf("Mang sau khi xoa tai vi tri %d la:", INDEX);
    XuatMang(a,n);
    
//SX TANG DAN
	SXTangDan(a, n);
	printf("\n");
	printf("\nMang sau khi sx tang dan la: ");
	XuatMang(a,n);

    return 0;  
}

