#include<iostream>
#include<stdio.h>
using namespace std;

class Node
{
	public:
	Node *prev;
	int data;
	 Node *next;
};

class DLL
{
    public:
    Node* first;
    
    DLL(){first=NULL;}
    DLL(int A[], int n);
    void Display(Node* head);
    void pairSum(int x);
    int countTriplets(int x);
    void rotate(Node **head, int N);
   
};

DLL::DLL(int A[], int n)
{
    Node* t,*last;
    int i;

    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }

}

void DLL::Display(Node *head)
{
    Node* p=head;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void DLL::pairSum(int x)
{
    Node* one = first; 
    Node *sec=first;

    while(sec->next)
     sec=sec->next;

     bool found = false;

     while(one && sec && one!=sec && sec->next!=one)
     {
         if(one->data+sec->data==x)
         {
             found=true;
             cout<<"("<<one->data<<","<<sec->data<<")"<<endl;

                one=one->next;
                sec=sec->prev;
        }
        else
        {
            if(one->data+sec->data<x)
                one=one->next;
            else
                sec=sec->prev;    
        }
     }

     if(found==false)
        cout<<"No Pair found";

}


int DLL::countTriplets(int x)
{
    Node* p1,*p2,*p3;
    int count=0;

    for(p1=first;p1!=NULL;p1=p1->next)
        for(p2=p1->next;p2!=NULL;p2=p2->next)
            for(p3=p2->next;p3!=NULL;p3=p3->next)
                if(p1->data+p2->data+p3->data==x)
                    count++;

   return count;                 
}

void DLL::rotate(Node **head, int N)
{
    if(N==0)
    return;

    Node *cur = *head;
    int count=1;

    while(count<N && cur)
    {
        cur=cur->next;
        count++;
    }

    if(cur==NULL)
    return;

    Node* Nth = cur;

    while(cur->next)
        cur=cur->next;

    cur->next = *head;

    (*head)->prev = cur;

    *head = Nth->next;

    (*head)->prev = NULL;

    Nth->next = NULL;    
}

int main()
{
    int arr[]={1,2,3,4,5};
    DLL obj(arr,5);

    obj.rotate(&obj.first, 2);
    obj.Display(obj.first);
    
    
}