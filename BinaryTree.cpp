#include<bits/stdc++.h>
using namespace std;
int f=1;
int ans;
unordered_map<string,int>mp;
class Node
{
    public:
    Node* left;
    int data;
    Node* right;
};

class Tree
{
    public:
    Node* root;
    Tree(){root=nullptr;}
    ~Tree(){}    
    
    void createTree();

    void RecursivepreOrder(Node* p);
    void IterativepreOrder(Node* p);

    void RecursiveinOrder(Node* p);
    void IterativeinOrder(Node* p);

    void RecursivepostOrder(Node* p);

    void levelOrder(Node* p);
    void levelOrder1(Node* root);
    void reverseLevelOrder(Node* p);


    int height(Node* p);
    int heightGFG(Node* root);

    bool isBalanced(Node* root);

    int diameter(Node* p);

    Node* mirror(Node* root);

    vector<int> leftView(Node* root);
    vector<int> rightView(Node* root);
    vector<int> topView(Node* root);
    vector<int> bottomView(Node* root);

    vector<int> zigzagTraversal(Node* root);
    vector<int> diagonalTraversal(Node* root);
//Boundary Traversal Functions
    void LeftTree(Node* root, vector<int>&ans);
    void Leaf(Node* root, vector<int>&ans);
    void RightTree(Node* root, vector<int>&ans);
    vector<int> BoundaryTraversal(Node* root);
 //end

 // check if BTree is SumTree
    int solve(Node* root);
    bool isSumTree(Node* root);   
// end    

//check if all leaf are at same level
    void solve(Node* root, int h, int &ma);
    bool checkifSameLev(Node* root);
//end

//Duplicate SubTree in BT
    string solveSubTree(Node* root);
    bool dupSub(Node* root);
//end    

// Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) 

void sumOfLongRootToLeafPath(Node* root, int sum, int len, int &maxLen, int &maxSum);
int sumOfLongRootToLeafPath(Node* root);
//end

// Find Largest subtree in a sum

    int findLargestSumTreeUtil(Node* root, int &ans);
    int findLargestSumTree(Node* root);
//end    

    void printallksumpathsinabinarytree(Node* root, vector<int>& path,int k);

    Node* LCA(Node* root, int n1, int n2);

    //Minimum Distance Between 2nodes
    int solve(Node* root,int val);
    //Node* LCA
    int minDist(Node*root,int a,int b);
    
    vector<int> recurIn(Node* root);

};

vector<int> Tree::recurIn(Node* root)
{
    vector<int>arr;
    if(root!=NULL)
        {
            recurIn(root->left);
            arr.push_back(root->data);
            recurIn(root->right);
        }
    return arr;
}

void Tree::createTree()
{
    Node* p;
    Node *t;
    int x;
    queue<Node*>q;

    root = new Node;
    cout<<"Enter root data: "<<flush;
    cin>>x;
    
    root->data = x;
    root->left = root->right = nullptr;
 
    q.emplace(root);

    while(!q.empty())
    {
        p = q.front();
        q.pop();

        cout<<"Enter left child of "<<p->data<<": "<<flush;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->left = t;
            q.emplace(t);
        }

         cout<<"Enter right child of "<<p->data<<": "<<flush;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->left = t->right = nullptr;
            p->right = t;
            q.emplace(t);
        }

     }
}

void Tree::RecursivepreOrder(Node* p)
{
    if(p)
    {
        cout<<p->data<<" "<<flush;
        RecursivepreOrder(p->left);
        RecursivepreOrder(p->right);
    }
}

void Tree::IterativepreOrder(Node* p)
{
    stack<Node*>stk;
    while(p || !stk.empty())
    {
        if(p)
        {
            cout<<p->data<<" ";
            stk.push(p);
            p=p->left;
        }
        else
        {
            p=stk.top();
            stk.pop();
            p=p->right;
        }
    }
}

void Tree::RecursiveinOrder(Node* p)
{
    if(p)
    {
        RecursiveinOrder(p->left);
        cout<<p->data<<" ";
        RecursiveinOrder(p->right);
    }
}

void Tree::IterativeinOrder(Node* p)
{
      stack<Node*>stk;
    while(p || !stk.empty())
    {
        if(p)
        {
            stk.push(p);
            p=p->left;
        }
        else
        {
            p=stk.top();
            stk.pop();
            cout<<p->data<<" ";
            p=p->right;
        }
    }
}

void Tree::RecursivepostOrder(Node* p)
{
    if(p)
    {
        RecursivepostOrder(p->left);
        RecursivepostOrder(p->right);
        cout<<p->data<<" ";
    }

}

 void Tree::levelOrder(Node* p)
 {
     queue<Node*> q;
     cout<<p->data<<" ";
     q.emplace(p);
     while(!q.empty())
     {
         p = q.front();
         q.pop();
         if(p->left)
         {
             cout<<p->left->data<<" ";
             q.emplace(p->left);
         }
         if(p->right)
         {
             cout<<p->right->data<<" ";
             q.emplace(p->right);
         }
     }
 }

void Tree::reverseLevelOrder(Node* p)
{
    stack<Node*>stk;
    queue<Node*>q;

    q.push(p);

    while(!q.empty())
    {
        p = q.front();
        q.pop();
        stk.push(p);

          if(p->right)
            q.push(p->right); 

        if(p->left)
            q.push(p->left);   
    }

    while(!stk.empty())
    {
        p = stk.top();
        cout<<p->data<<" ";
        stk.pop();
    }

}

void Tree::levelOrder1(Node* root)
{
     queue<Node*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		Node* temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			//insert a new null for the next level
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}

	}
	return;
}

int Tree::height(Node* p)
{
    if(p==NULL)
        return 0;

    int h1 = height(p->left);
    int h2 = height(p->right);
    return 1+max(h1,h2);       
}

int Tree::diameter(Node* p)
{
    if(p==NULL)
        return 0;

     int d1 = height(p->left) + height(p->right);
     int d2 = diameter(p->left);
     int d3 = diameter(p->right);

   return max(d1, max(d2,d3));

}

 Node* Tree::mirror(Node* root)
 {
     if(root==NULL)
        return root;

     Node* temp = root->left;
     root->left = root->right;
     root->right = temp;   

     if(root->left)
        mirror(root->left);
     if(root->right)
        mirror(root->right);

    return root;       
 }

   vector<int> Tree::leftView(Node* root)
 {
     vector<int> arr;
    if (!root)
        return {};
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        int n = q.size();
         
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            if (i == 1)
                arr.push_back(temp->data);
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return arr;
       
 }

  vector<int> Tree::rightView(Node* root)
  {
       vector<int> arr;
    if (!root)
        return {};
 
    queue<Node*> q;
    q.push(root);
 
    while (!q.empty())
    {    
        int n = q.size();
         
        for(int i = 1; i <= n; i++)
        {
            Node* temp = q.front();
            q.pop();
                 
            if (i == n)
                arr.push_back(temp->data);
             
            // Add left node to queue
            if (temp->left != NULL)
                q.push(temp->left);
 
            // Add right node to queue
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
    return arr;
  }

   vector<int> Tree::topView(Node* root)
   {
       if(root==NULL)
        return {};

       vector<int>arr;
       queue<pair<Node*,int>>q;
       map<int,int>mp;
       q.push({root,0});

       while(!q.empty()) 
       {
           Node* temp = q.front().first;
           int h = q.front().second;
           q.pop();

           if(!mp[h])
            mp[h] = temp->data;

            if(temp->left)
                q.push({temp->left,h-1});

            if(temp->right)
                q.push({temp->right,h+1});
          }
          for(auto x:mp)
                arr.push_back(x.second);        

        return arr;
   }

vector<int> Tree::bottomView(Node* root)
{
    if(root==NULL)
        return {};

       vector<int>arr;
       queue<pair<Node*,int>>q;
       map<int,int>mp;
       q.push({root,0});

       while(!q.empty()) 
       {
           Node* temp = q.front().first;
           int h = q.front().second;
           q.pop();

       
            mp[h] = temp->data;

            if(temp->left)
                q.push({temp->left,h-1});

            if(temp->right)
                q.push({temp->right,h+1});
          }
          for(auto x:mp)
                arr.push_back(x.second);        

        return arr;
}

vector<int> Tree::zigzagTraversal(Node* root)
{
    if(root==NULL)
        return {};
    vector<int>ans;
    queue<Node*>q;
    int f=1;
    q.push(root);
    while(!q.empty())
        {
            vector<int>temp;
            int sz = q.size();
            while(sz--)
            {
                Node* t = q.front();
                temp.push_back(t->data);
                q.pop();

                if(t->left)
                    q.push(t->left);
                if(t->right)
                    q.push(t->right);    
            }
            if(f%2==0)
                reverse(temp.begin(),temp.end());
            for(auto x:temp)
                ans.push_back(x); 
                f=!f;   
        }    
        return ans;
}

vector<int> Tree::diagonalTraversal(Node* root)
{
    if(root==NULL)
        return {};
    vector<int>ans;
    queue<Node*>q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        while(temp)
        {
            if(temp->left)
                q.push(temp->left);
            ans.push_back(temp->data);
            temp = temp->right;    
        }
    }
    return ans;    
}

 int Tree::heightGFG(Node* root)
 {
     if(root==NULL)
        return 0;

     return 1+max(heightGFG(root->left),heightGFG(root->right));   
 }

bool Tree::isBalanced(Node* root)
{
    if(root==NULL)
        return 1;

    int h1 = heightGFG(root->left);
     int h2 = heightGFG(root->right);

     if(abs(h1-h2)<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;

     return 0;   

}

void Tree::LeftTree(Node* root, vector<int>&ans)
{
    if(!root)
        return;
    if(root->left)
        {
            ans.push_back(root->data);
            LeftTree(root->left,ans);
        }    
    else if(root->right)
    {
        ans.push_back(root->data);
        LeftTree(root->right,ans);
    }    
}
void Tree::Leaf(Node* root, vector<int>&ans)
{
    if(!root)
        return;
    Leaf(root->left,ans);
    if(!root->left and !root->right)
        ans.push_back(root->data);
    Leaf(root->right,ans);        
}
void Tree::RightTree(Node* root, vector<int>&ans)
{
if(!root)
        return;
        if(root->right)
        {
            RightTree(root->right,ans);
            ans.push_back(root->data);
        }
        else if(root->left)
        {
            RightTree(root->left,ans);
            ans.push_back(root->data);
        }
}
vector<int> Tree::BoundaryTraversal(Node* root)
{
if(!root)
        return {};
    vector<int>ans;
    ans.push_back(root->data);
    LeftTree(root->left,ans);
    Leaf(root,ans);
    RightTree(root->right,ans);

    return ans;    
}

 int Tree::solve(Node* root)
 {
     if(!root)  return 0;
     if(!root->left and !root->right)   return root->data;
     if(f==0)
        return 0;
     int left = solve(root->left);
     int right = solve(root->right);
     if(left+right != root->data)   f=0;

     return left + right + root->data;   
 }
bool Tree::isSumTree(Node* root)
{
    f=1;
    solve(root);
    return f;
}

void Tree::solve(Node* root, int h, int &ma)
{
    if(!root)
        return;
    if(ans==0)
        return;
    if(!root->left and !root->right)
        {
            if(ma==-1)
                ma = h;
            else
            {
                if(ma!=h)
                    ans=0;
            }    
            return;
        }
        solve(root->left,h+1,ma);
        solve(root->right,h+1,ma);
                
}
bool Tree::checkifSameLev(Node* root)
{
    int ma=-1,h=0;
    ans = 1;
    solve(root,h,ma);
    return ans;
}

string Tree::solveSubTree(Node* root)
{
    if(!root)
        return "*";
    string s = "";
    if(!root->left and !root->right)
        {
            s = to_string(root->data);
            return s;
        }
     s += to_string(root->data);
     s += solveSubTree(root->left);
     s += solveSubTree(root->right);
     mp[s]++;

     return s;       
}
bool Tree::dupSub(Node* root)
{
    mp.clear();
    solveSubTree(root);
    for(auto x:mp)
        if(x.second>=2)
            return true;
    return false;        
}

void Tree::sumOfLongRootToLeafPath(Node* root, int sum, int len, int &maxLen, int &maxSum)
{
    if(!root)
    {
        if(maxLen < len)  
        {
            maxLen = len;
            maxSum = sum;
        }
        else if(maxLen==len and maxSum < sum)
            maxSum = sum;
        return;    
    }
    sumOfLongRootToLeafPath(root->left, sum+root->data, len+1, maxLen, maxSum);
    sumOfLongRootToLeafPath(root->right, sum+root->data, len+1, maxLen, maxSum);
}

int Tree::sumOfLongRootToLeafPath(Node* root)
{
    if(!root)
        return 0;
    int maxSum = INT_MIN, maxLen = 0;
    sumOfLongRootToLeafPath(root,0,0,maxLen,maxSum);
    return maxSum;    
}


    int Tree::findLargestSumTreeUtil(Node* root, int &ans)
    {
      if(!root)
        return 0;

      int currSum = root->data + findLargestSumTreeUtil(root->left,ans) + findLargestSumTreeUtil(root->right,ans);

      ans = max(ans,currSum);
      return currSum;  

    }
    int Tree::findLargestSumTree(Node* root)
    {
          if(!root)
            return 0;
        int ans = INT_MIN;
        findLargestSumTreeUtil(root,ans);
        return ans;    
    }

    void Tree::printallksumpathsinabinarytree(Node* root, vector<int>& path,int k)
    {
        if(!root)
            return;
         path.push_back(root->data);
         printallksumpathsinabinarytree(root->left,path,k);
         printallksumpathsinabinarytree(root->right,path,k);

         int f=0;
         for(int j = path.size()-1;j>=0;j--)
         {
             f+=path[j];
             if(f==k)
             {
                 for(int m=j;m<path.size();m++)
                    cout<<path[m]<<" ";
                cout<<endl;    
             }
         }
         path.pop_back();   
    }

     Node* Tree::LCA(Node* root, int n1, int n2)
     {
         if(!root)
            return NULL;
         if(root->data==n1 || root->data==n2)
            return root;

         Node* leftlca = LCA(root->left,n1,n2);
         Node* rightlca = LCA(root->right,n1,n2);

         if(leftlca and rightlca)
            return root;

         return leftlca?leftlca:rightlca;    
     }

     int Tree::solve(Node* root,int val)
     {
         if(!root)
            return 0;
         if(root->data==val)
            return 1;
         int a = solve(root->left,val);
         int b = solve(root->right,val);

         return !a && !b?0:a+b+1;      
     }
    
    int Tree::minDist(Node*root,int a,int b)
    {
        Node* lca = LCA(root,a,b);
        int x = solve(lca,a);
        int y = solve(lca,b);
        return x+y-2;
    }

int main()
{
    Tree bt;
     bt.createTree();
     cout<<endl;

   auto it = bt.recurIn(bt.root);
   for(auto x:it)
    cout<<x<<" ";
 
}