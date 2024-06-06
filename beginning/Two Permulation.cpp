// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int t;
    cin>>t;
    for(long long int i=0;i<t;i++){
        int n,a,b;
        cin>>n>>a>>b;
        if(a+b>=n){
            if(a==n && b==n){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
        else{
            int temp=n-a-b;
            if(temp>1){
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
    
    return 0;
}
