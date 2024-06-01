// CODEFORCES 900 RATED

#include<bits/stdc++.h>
using namespace std;

string doIntersect(int a, int b, int c, int d){
    int maxi = max(a, b);
    int mini = min(a, b);

    bool flag = false;

    if((mini < c && maxi > c) && (mini > d || maxi < d)){
        flag = true;
    }
    else if((mini < d && maxi > d) && (mini > c || maxi < c)){
        flag = true;
    }

    if(flag){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        if(a > b) swap(a, b);
        if(c > d) swap(c, d);

        cout << doIntersect(a, b, c, d) << endl;
    }
}