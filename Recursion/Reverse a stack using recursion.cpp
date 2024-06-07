// GFG POTD

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void Reverse(stack<int> &St){
        if(!St.empty()) {
            // Remove the top element
            int x = St.top();
            St.pop();
            // Reverse the remaining stack
            Reverse(St);
            // Insert the removed element at the bottom
            InsertAtBottom(St, x);
        }
    }
    
private:
    void InsertAtBottom(stack<int> &St, int x) {
        if(St.empty()) {
            St.push(x);
        } else {
            // Hold all items in Function Call Stack until we reach end
            int temp = St.top();
            St.pop();
            InsertAtBottom(St, x);
            // Push all the items held in Function Call Stack once the item is inserted at the bottom
            St.push(temp);
        }
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends