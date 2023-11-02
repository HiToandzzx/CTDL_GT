#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct SinhVien
{
    int MSSV;
    char Ten[150];
    char Lop[150];
    float DTB;
};

struct Node
{
    SinhVien *data;
    Node *pNext;
};

struct SingleList
{
    Node *pHead;
};

void InNode(SingleList *&list)
{
    list=new SingleList;
    list->pHead=NULL;
}

//Nhap thong tin sinh vien
SinhVien *NhapSinhVien()
{
    SinhVien *sv = new SinhVien;
    cout<<"Nhap MSSV:";
    cin>>sv->MSSV;
    cin.ignore();
    cout<<"Nhap ho va ten:";
    gets(sv->Ten);

    cout<<"Nhap Lop:";
    gets(sv->Lop);

    cout<<"Nhap DTB:";
    cin>>sv->DTB;
    return sv;
}

//Tao node 
Node *CreateNode(SinhVien *sv)
{
    Node *pNode=new Node;
    if(pNode!=NULL)
    {
        pNode->data=sv;
        pNode->pNext=NULL;
    }
    else
    {
        cout<<"cap phat bo nho that bai!!!";
    }
    return pNode;
}

void InsertLast(SingleList *&list,SinhVien *sv)
{
    Node *pNode=CreateNode(sv);
    if(list->pHead==NULL)
    {
        list->pHead=pNode;
    }
    else
    {
        Node *pTmp=list->pHead;
         
        while(pTmp->pNext!=NULL)
        {
            pTmp=pTmp->pNext;
        }
        pTmp->pNext=pNode;
    }
}
//hien thi danh sach
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(pTmp!=NULL)
    {
        SinhVien *sv=pTmp->data;
        cout<<sv->MSSV<<"\t"<<sv->Ten<<"\t"<<sv->Lop<<"\t"<<sv->DTB<<"\t"<<"\n";
        pTmp=pTmp->pNext;
    }
}

//xoa sinh vien DTB<5
void RemoveNode(SingleList *&list,int DTB)
{
    Node *pDel=list->pHead;
    if(pDel==NULL)
    {
        cout<<"Danh sach rong!";
    }
    else
    {
        Node *pPre=NULL;
        while(pDel!=NULL)
        {
            SinhVien *sv=pDel->data;
            if(sv->DTB<5)
                break;
            pPre=pDel;
            pDel=pDel->pNext;
        }
        if(pDel==NULL)
        {
            cout<<"khong tim thay sv co DTB<5 "<<DTB;
        }
        else
        {
            if(pDel==list->pHead)
            {
                list->pHead=list->pHead->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
            else
            {
                pPre->pNext=pDel->pNext;
                pDel->pNext=NULL;
                delete pDel;
                pDel=NULL;
            }
        }
    }
}
void PrintList(SingleList *list)
{
    Node *pTmp=list->pHead;
    if(pTmp==NULL)
    {
        cout<<"Danh sach rong";
        return;
    }
    while(sv->Lop==Lop)
    {
        SinhVien *sv=pTmp->data;
        cout<<sv->MSSV<<"\t"<<sv->Ten<<"\t"<<sv->Lop<<"\t"<<sv->DTB<<"\t"<<"\n";
        pTmp=pTmp->pNext;
    }
}

int main(int argc, char** argv) {
    SingleList *list;
    InNode(list);
    SinhVien *A=NhapSinhVien();
    InsertLast(list,A);
    SinhVien *B=NhapSinhVien();
    InsertLast(list,B);
    SinhVien *C=NhapSinhVien();
    InsertLast(list,C);
    cout<<"Danh sach sinh vien: \n";
    PrintList(list);

float DTB;
RemoveNode(list,DTB);
    cout<<"\nSau khi xoa co DTB <5:\n";

    cout<<"\Ban muon xoa sinh vien o lop: ";
    int Lop;
    cin>>Lop;
    PrintList(list);
 

}
