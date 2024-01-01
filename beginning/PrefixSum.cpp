/*
#include<iostream>
#include<vector>
using namespace std;

void runningSum(vector<int>&v){
    for(int i=1;i < v.size();i++){
        v[i]+=v[i-1];
    }
    return;
}

int main(){
    int n;
    cin>>n;

    vector<int>v;
    for(int i = 0;i < n;i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }

    runningSum(v);

    for(int i = 0;i< n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
*/
/*
#include<iostream>
#include<vector>
using namespace std;

bool checkPrefixSuffixSum(vector<int> &v)
{
    int total_sum = 0;
    for(int i = 0;i < v.size();i++){
        total_sum+=v[i];
    }

    int prefix_sum = 0;
    for(int i = 0;i < v.size();i++)
    {
        prefix_sum += v[i];
        int suffix_sum = total_sum - prefix_sum;

        if(suffix_sum == prefix_sum){
            return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;

    vector<int>v;
    for(int i = 0;i < n;i++)
    {
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
}
*/

// Given an array of integers of size n. Answer q queries where you need top print the sum of values in a given range of indices from l to r(both included)

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int>v(n+1,0);
    for(int i = 1;i <= n;i++){
        cin>>v[i];
    }

    // Calculate prefix sum array
    for(int i = 1;i <= n;i++)
    {
        v[i] += v[i-1];
    }

    int q;
    cin>>q;

    while(q--){
        int l,r;
        cin>>l>>r;

        int ans = 0;
        // ans = prefixsumarray[r] - prefixsumarray[l-1]
        ans = v[r] - v[l-1];
        cout<<ans;
    }
    return 0;
}