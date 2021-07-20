#include<bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

class Queue
{
    int front;
    int rear;
    int size;
    int *Q;
    public:
        Queue(){front=rear=-1;size=10;Q=new int[size];}
        Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}
        void enqueue(int x);
        int dequeue();
        void Display();
};

void Queue::enqueue(int x)
{
    if(rear == size-1)
        cout<<"Queue Full"<<endl;
    else
    {
        rear++;
        Q[rear]=x;
    }    
}
int Queue::dequeue()
{
    int x=-1;
    if(front==rear)
        cout<<"Queue Empty"<<endl;
    else
    {
        x = Q[front+1];
        front++;
    }   
    return x; 
}
void Queue::Display()
{
    for(int i=front+1;i<=rear;i++)
         cout<<Q[i]<<" ";
    cout<<endl;     
    
}

void modifyQ(queue<int>&q, int k)  //Reverse First K elements of Queue 
{
    if(q.empty() || k<=0)
        return ;

    stack<int>stk;

    for(int i=0;i<k;i++)
        {
            stk.push(q.front());
            q.pop();
        }

    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }    

    for(int i=0;i<q.size()-k;i++)
    {
        q.push(q.front());
        q.pop();
    }

}

void Reverse(queue<int>&q)
{
    if(q.empty())
        return;

    stack<int>stk;
    while(!q.empty())
    {
        stk.push(q.front());
        q.pop();
    }    

    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }
}

void Interleave(queue<int>&q)   //Interleave the first half of the queue with second half
{
    if(q.size()%2!=0)
        cout<<"Input even no. of elements"<<endl;
    stack<int> stk;
    int half = q.size()/2;

    // Push first half elements into the stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for(int i=0;i<half;i++)
    {
        stk.push(q.front());
        q.pop();
    }    

    // enqueue back the stack elements
    // queue: 16 17 18 19 20 15 14 13 12 11
    while(!stk.empty())
    {
        q.push(stk.top());
        stk.pop();
    }

    // dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
     for(int i=0;i<half;i++)
     {
         q.push(q.front());
         q.pop();
     }

      // Again push the first half elements into the stack
    // queue: 16 17 18 19 20, stack: 11(T) 12 13 14 15
      for(int i=0;i<half;i++)
      {
              stk.push(q.front());
        q.pop();
      }

        // interleave the elements of queue and stack
    // queue: 11 16 12 17 13 18 14 19 15 20
      while(!stk.empty())
      {
          q.push(stk.top());
          stk.pop();
          q.push(q.front());
          q.pop();
      }



}

vector<int> printFirstNegativeInt(int arr[],int n, int k)
{
    deque<int>di;
    vector<int>res;

    int i=0;
    for(i=0;i<k;i++)
        if(arr[i]<0)
            di.push_back(i);

    for(;i<n;i++)
    {
        if(!di.empty())
            res.push_back(arr[di.front()]);
        else
            res.push_back(0);

        while(!di.empty() && di.front() < (i-k+1))
            di.pop_front();

        if(arr[i]<0)
            di.push_back(i);            

    }

    if(!di.empty())
             res.push_back(arr[di.front()]);
        else
            res.push_back(0);

           return res; 
                
}

int minSumSq(string S, int k)
{
    int l = S.length();

    if(k>=l)
        return 0;

    int freq[MAX_CHAR] = {0};
    for(int i=0;i<l;i++)
        freq[S[i]-'a']++;

    priority_queue<int> q;

    for(int i=0;i<MAX_CHAR;i++)
        q.push(freq[i]);

    while(k--)
    {
        int temp = q.top();
        q.pop();
        temp-=1;
        q.push(temp);
    }            

    int res=0;
    while(!q.empty())
    {
        int temp = q.top();
        res += temp*temp;
        q.pop();
    }
    return res;
}

string FirstNonRepeating(string str)
    {
        queue<char> q;
        int charCount[26] = { 0 };
        string res;


        for (int i = 0; str[i]; i++) {

            q.push(str[i]);

            charCount[str[i] - 'a']++;

            while (!q.empty()) {
                if (charCount[q.front() - 'a'] > 1)
                    q.pop();
                else {
                    res.push_back(q.front());
                    break;
                }
            }

            if (q.empty())
                res.push_back('#');
        }
        return res;
    }

int main()
{
    string str = "aabc";
   

    cout<< FirstNonRepeating(str);


    
    
}