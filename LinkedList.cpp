#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

class LinkedList
{
    public:
        Node* first;

    public:
        LinkedList(){first=NULL;}
        LinkedList(int A[], int n);
        void Display(Node* head);
        void Reverse();
        void RReverse(Node *q, Node* p);
        Node *reverse(Node* p, int k);
        int isLoop();
        void removeLoop();
        Node* removeDup(Node* start);
        void moveFront(Node **head);
        Node* addone(Node* head);
        Node* mid(Node* head);
        void sort012();
        Node* delNHavGre(Node* head);
        Node* Segregate(Node* head);
        int getNth(int n);
        Node* SortedMerge(Node* a, Node* b);
        void SplitList(Node* head, Node** a, Node** b);
        void MergeSort(Node** headref);
        Node* mergesort();
        
        
       
};

void LinkedList::Reverse()
{
    Node *p=first, *q=NULL, *r=NULL;

    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first = q;
}

LinkedList::LinkedList(int A[], int n)
{
    Node* t, *last;
    int i=0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1;i<n;i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last=t;
    }
}

void LinkedList::Display(Node* head)
{
    Node *p = head;

    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

void LinkedList::RReverse(Node *q, Node* p)
{
    if(p)
    {
        RReverse(p,p->next);
        p->next=q;
    }
    else
        first=q;
}

Node* LinkedList::reverse(Node* head, int k)
{
    if (!head)
        return NULL;
    Node* current = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;
 
    
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if (next != NULL)
        head->next = reverse(next, k);

    return prev;       
}

int LinkedList::isLoop()
{
    Node *p,*q;
    p=q=first;

    do
    {
        p=p->next;
        q=q->next;
        q=q!=NULL?q->next:NULL;
    } while (p && q && p!=q);

    return p==q?true:false;
    
}

void LinkedList::removeLoop()
{
    if(first==NULL || first->next==NULL)
        return;

    Node* slow=first, *fast=first; 
    slow=slow->next;
    fast=fast->next->next;

    while(fast && fast->next)
    {
        if(slow==fast)
            break;
        slow=slow->next;
        fast=fast->next->next;    
    }   

    if(slow==fast)
    {
        slow=first;
        if(slow=fast)
            while(fast->next!=slow)
                fast=fast->next;
        else
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }        
    }

    fast->next=NULL;
}

Node* LinkedList::removeDup(Node* start)
{
    unordered_set<int> sort;
    Node* p=start,*q=NULL;

    while(p)
    {
        if(sort.find(p->data)==sort.end())
        {
            sort.insert(p->data);
            q=p;
        }
        else
        {
            q->next=p->next;
            delete p;
        }
        p=p->next;
    }

    return start; 
} 

void LinkedList::moveFront(Node **head)
{
    if(*head==NULL || (*head)->next==NULL)
        return;

    Node *seclast=NULL, *last=*head;

    while(last->next)
    {
        seclast=last;
        last=last->next;
    }

    seclast->next = NULL;
    last->next=*head;
    *head=last;
}

Node* LinkedList::addone(Node* head)
{
    Node* last=NULL, *cur=head;

    while(cur->next)
    {
        if(cur->data!=9)
            last=cur;

        cur=cur->next;    
    }

    if(cur->data!=9)
    {
        cur->data++;
        return head;
    }

    if(last==NULL)
    {
        last =new Node;
        last->data = 0;
        last->next = head;
        head = last;
    }

    last->data++;
    last=last->next;

    while(last)
    {
        last->data=0;
        last=last->next;
    }

    return head;
}

Node* LinkedList::mid(Node* head)
{
    Node* slow=head, *fast=head;

    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }

    return slow;
}

   void LinkedList::sort012()
   {
       int count[3]={0,0,0};
       Node* p=first;

       while(p)
       {
           count[p->data]+=1;
           p=p->next;
       }
       int i=0;
       p=first;

       while(p)
       {
           if(count[i]==0)
           ++i;
           else
           {
               p->data=i;
               --count[i];
               p=p->next;
           }
       }
   }

   Node* LinkedList::delNHavGre(Node* head)
   {
       if(head==NULL)
       return 0;

       Node* temp = head;
       Node* prev = NULL, *p=temp;
       while(temp && temp->next)
       {
           if(temp->data < temp->next->data)
           {
               prev = temp->next;
               temp->data = prev->data;
               temp->next = prev->next;
               temp=head;
           }
           else
            temp=temp->next;
       }
       return p;
   }

   Node* LinkedList::Segregate(Node* list)
   {
          Node* evenlist=NULL;
    Node* oddlist=NULL;
    Node *oddend=NULL,*evenend=NULL;
    Node* temp=list;
    while(temp!=NULL)
    {
        if(temp->data%2==0)
        {
            if(evenlist==NULL)
                evenlist=temp;
            else
                evenend->next=temp;
            
            evenend=temp;   
            
            
        }
        else
        {
            if(oddlist==NULL)
                oddlist=temp;
            else
                oddend->next=temp;
            
            oddend=temp;            
        }
        
        temp=temp->next;
    }
    
    if(oddlist == NULL || evenlist == NULL) 
            return list;
        
    
    evenend->next=oddlist;
    oddend->next=NULL;
    return evenlist;
   }

   int LinkedList::getNth(int n)
   {
       Node* p=first;
       int i=0;
       while(p->next)
       {
           p=p->next;
           i++;
       }
       int count=i+1-n;
       if(count<0)
        return -1;
        p=first;
        while(count--)
            p=p->next;

        return p->data;    
   }

   Node* LinkedList::SortedMerge(Node* a, Node* b)
   {
            Node *result;

            if(a==NULL)
                return b;
            else if(b==NULL)
                return a;

            if(a->data<=b->data)   
            {
                result=a;
                result->next=SortedMerge(a->next,b);
            }
            else
            {
                result=b;
                result->next=SortedMerge(a,b->next);
            } 
            return result;

        }

         void LinkedList::SplitList(Node* head, Node** a, Node** b)
         {
             Node* slow=head;
             Node* fast=head->next;

             if(fast)
             {
                 fast=fast->next;
                 if(fast)
                 {
                     fast=fast->next;
                     slow=slow->next;
                 }
             }

             *a = head;
             *b = slow->next;
             slow->next = NULL;
         }

         void LinkedList::MergeSort(Node** headref)
         {
             Node* head = *headref;
             Node* a;
             Node* b;
             if(head==NULL || head->next==NULL)
                return;

             SplitList(head,&a,&b);

             MergeSort(&a);
             MergeSort(&b);

             *headref = SortedMerge(a,b);   
         }

        Node* LinkedList::mergesort()
        {
            MergeSort(&first);
            return first;
        }

int main()
{
    
    int arr[]={5,4,3,2,1};

    LinkedList ll(arr,5);
    
   Node* t1=ll.mergesort();
   ll.Display(t1);
    

   
    

    
}