#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {4, 5, 7, 1, 2, 5, 0, 9, 4, 2};

    sort(v.begin(), v.end(), greater<int>()); // sorting in decreasing order

    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}