// CODEFORCES 1100 RATED

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll T, n, l, r, i, j, c;
    cin >> T;
    
    while(T--){

        cin>>n>>l>>r;

        vector<ll> ans;
        
        c=1;
        ans.push_back(l);

        for(i=2; i<=n; i++)
        {
            if((l%i)!=0){
                j=l/i;
                
                j=(j+1)*i;
                
                if(j>=l && j<=r){
                    c++;
                    ans.push_back(j);
                }else{
                    break;
                }
            }
            else{
                ans.push_back(l);
                c++;
            }
        }
        
        if(c==n){
            cout<<"YES\n";
            for(i=0; i<n; i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
}

