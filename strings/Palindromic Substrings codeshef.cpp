// codeshef contest 10th April

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;
    int count0 = 0;
    int count1 = 0;
    
    for(int i = 0; i < n; i++){
        if(str[i] == '1') count1++;
        else count0++;
    }
    
    int diff = abs(count0-count1);
    if(n%2 == 0){
        if(diff == 0) return "Bob";
        else return "Alice";
    }
    else{
        if(n == 1) return "Bob";
        else if(diff == 1) return "Alice";
        else return "Bob";
    }
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--){
	    cout<<solve()<<endl;
	}
	return 0;
}
