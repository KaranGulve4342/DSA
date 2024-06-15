// GFG

//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        unordered_set<int> s;
        list<int> indexes;
        int page_faults = 0;

        for (int i = 0; i < N; i++) {
            // If the set can hold more pages
            if (s.size() < C) {
                // If page is not present, add it to set and increment page fault
                if (s.find(pages[i]) == s.end()) {
                    s.insert(pages[i]);
                    page_faults++;
                    indexes.push_back(pages[i]);
                }
                // If page is already there, we need to update the position of this page
                else {
                    indexes.remove(pages[i]);
                    indexes.push_back(pages[i]);
                }
            }
            // If the set is full
            else {
                // If the page is not present in the set
                if (s.find(pages[i]) == s.end()) {
                    // Remove the first page from the list and set
                    int val = indexes.front();
                    indexes.pop_front();
                    s.erase(val);

                    // Insert the current page into set and list
                    s.insert(pages[i]);
                    indexes.push_back(pages[i]);

                    // Increment page faults
                    page_faults++;
                }
                // If the page is already there, we need to update the position of this page
                else {
                    indexes.remove(pages[i]);
                    indexes.push_back(pages[i]);
                }
            }
        }
        return page_faults;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}
// } Driver Code Ends