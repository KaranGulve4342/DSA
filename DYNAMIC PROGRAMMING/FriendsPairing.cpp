#include<iostream>
using namespace std;

int f(int n){
    if(n == 1 || n == 2) return n;
    return f(n-1) + (n-1)*f(n-2);
}
int main() {
    cout<<f(5)<<"\n";
    return 0;
}

/*
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int prev1 = 1;
    int prev2 = 0;

    if(n == 0) return prev2;

    for(int i=  0;i <= n;i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<prev1<<endl;
}
*/