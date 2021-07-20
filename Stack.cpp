#include<bits/stdc++.h>
using namespace std;

class Stack 
{
    int size;
    int top;
    int *S;

    public:
        Stack(int size)
        {
            this->size=size;
            top=-1;
            S=new int[size];
        }
        ~Stack(){delete[] S;}
        void Push(int x);
        int Pop();
        int Peek(int index);
        int isFull();
        int isEmpty();
        void Display();
        int stackTop();
        int stackMid();

};

        void Stack::Push(int x)
        {
            if(isFull())
                cout<<"Stack Overflow"<<endl;
            else
            {
                top++;
                S[top] = x;
            }    
        }
        int Stack::Pop()
        {
            int x=1;
            if(isEmpty())
                cout<<"Stack Underflow"<<endl;
            else
            {
                x = S[top];
                top--;
            }    
            return x;
        }
        int Stack::Peek(int index)
        {
            int x=-1;
            if(top-index+1<0 || top-index+1==size)
                cout<<"Invalid Position"<<endl;
            else
            x=S[top-index+1];

            return x;    
        }
        int Stack::isFull()
        {
            if(top==size-1)
                return 1;
            
            return 0;    
        }
        int Stack::isEmpty()
        {
            if(top==-1)
                return 1;

            return 0;    
        }
        void Stack::Display()
        {
            for(int i=top;i>=0;i--)
            cout<<S[i]<<" | ";

            cout<<endl;
        }
        int Stack::stackTop()
        {
            if(isEmpty())
                return -1;
            return S[top];    
        }

        int Stack::stackMid()
        {
            int x = (size-1)/2;
            return S[x];
        }

        string reverse(string s)
        {
            int n=s.length();
            Stack stk(n);

            for(int i=0;i<n;i++)
            stk.Push(s[i]);

            for(int i=0;i<n;i++)
            {
                s[i]=stk.stackTop();
                stk.Pop();
            }

            return s;
        }

        int evalPost(string s)
        {
              stack <int> st;
	
	        for(int i=0;i<s.length();i++)
	    {
	      if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
		    st.push((s[i]-'0'));	
		}	
		else
		{
			int val1 = st.top();
			st.pop();
			int val2 = st.top();
			st.pop();
			
			switch(s[i])
			{
				case '+':
					st.push((val2+val1));
				    break;
				    
				case '-':
					st.push((val2-val1));
					break;
					
				case '*':
					st.push((val2*val1));
					break;
					
				case '/':
					st.push((val2/val1));
					break;
			}
		}
	}
	return st.top();
        }    

 int getMaxArea(int hist[], int n)
{
    stack<int> stk;

    int max_area=0,tp,area_top;
    int i=0;
    while(i<n)
    {
        if(stk.empty() || hist[stk.top()] <= hist[i])
            stk.push(i++);

        else
        {
            tp = stk.top();
            stk.pop();

            area_top = hist[tp] * (stk.empty() ? i : i-stk.top()-1);

            if(max_area < area_top)
                max_area = area_top;
        }    
    }

    while(stk.empty()==false)
    {
        tp = stk.top();
        stk.pop();
        area_top = hist[tp] * (stk.empty() ? i : 
                                i - stk.top() - 1);
  
        if (max_area < area_top)
            max_area = area_top;
    }

    return max_area;
}
    int lenValidSubstr(string str)
    {
        stack<int> stk;
        stk.push(-1);
        int count=0;

        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='(')
                stk.push(i);

            else
            {
                if(!stk.empty())
                    stk.pop();

                 if(!stk.empty())
                 count=max(count, i-stk.top());

                 else
                    stk.push(i);
            }    
        }
        return count;
    }

    int redundantParan(string s)
    {
        stack<char> stk;
        bool flag = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
                stk.push(s[i]);

            else if(s[i]=='(')
                stk.push(s[i]);

            else if(s[i]==')')
            {
                if(stk.top()=='(')
                 {   flag=1;
                    break;
                 }
                while(stk.top()=='+' || stk.top()=='-' || stk.top()=='*' || stk.top()=='/')
                    stk.pop();       

                stk.pop();
            }   
                 
        }
        return flag;
        
    }

bool checkStackPerm(int A[], int B[], int n)
{
    queue<int> ip;
    for(int i=0;i<n;i++)
        ip.push(A[i]);

    queue<int> op;
    for(int i=0;i<n;i++)
        op.push(B[i]);    

    stack<int>stk;

    while(!ip.empty())
    {
        int val = ip.front();
        ip.pop();
        if(val == op.front())
        {
            op.pop();
            while(!stk.empty())
            {
                if(stk.top()==op.front())
                {
                    stk.pop();
                    op.pop();
                }
                else
                    break;
            }
        }
        else
        stk.push(val);
    }

    return(ip.empty() && stk.empty());    
}

void printNSE(int arr[], int n)
{
    stack<int>stk;

    stk.push(arr[0]);

    for(int i=1;i<n;i++)
    {
        if(stk.empty())
        {
            stk.push(arr[i]);
            continue;
        }

        while(!stk.empty() && stk.top()>arr[i])
        {
            cout<<stk.top()<<"-->"<<arr[i]<<endl;
            stk.pop();
        }
        stk.push(arr[i]);
    }

    while(!stk.empty())
    {
         cout << stk.top() << "-->" << -1 << endl;
        stk.pop();
    }
}

int main()
{    

  int A[]={11, 13, 21, 3};

  printNSE(A,4);
  

    
}        