// CODEFORCES 1000 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int a[n][m];int c=0;
		long long int s=0;int mi=10000;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				if(a[i][j]<0){
					c++;
                }
				mi=min(mi,abs(a[i][j]));
				s=s+abs(a[i][j]);
			}
		}//cout<<s<<endl;
		if(c%2==0) cout<<s<<endl;
		else cout<<s-2*mi<<endl;
	}
}