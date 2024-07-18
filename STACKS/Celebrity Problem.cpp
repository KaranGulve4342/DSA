// GFG PRACTICE

//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        vector<int> IKnow(n, 0);
        vector<int> KnowMe(n, 0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(M[i][j] == 1){
                    KnowMe[j]++;
                    IKnow[i]++;   
                }
            }
        }
        
        for(int i = 0;i < n;i++){
            if(KnowMe[i] == n-1 && IKnow[i] == 0){
                return i;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends

// USING STACK
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        for(int i = 0;i < n;i++){
            st.push(i);
        }
        
        while(st.size() > 1){
            int person1 = st.top();
            st.pop();
            
            int person2 = st.top();
            st.pop();
            
            if(M[person1][person2] == 1){
                st.push(person2);
            }
            else{
                st.push(person1);
            }
        }
        
        int C = st.top();
        
        for(int i = 0;i < n;i++){
            if(i != C && (M[C][i] == 1 || M[i][C] == 0)){
                return -1;
            }
        }
        
        return C;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends