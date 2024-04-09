/*

t = int(input())
for _ in range(t):
    n, c, d = map(int, input().split())
    elements = list(map(int, input().split()))

    square = [[0 for _ in range(n)] for _ in range(n)]
    square[0][0] = elements[0]

    for i in range(1, n):
        square[0][i] = square[0][i-1] + c
        square[i][0] = square[i-1][0] + d

    ## fill the rest of the square
    for i in range(1, n):
        for j in range(1, n):
            square[i][j] = sqaure[i-1][j] + d if square[i-1][j] + d == square[i][j-1] + c else square[i][j-1]

    # check if the constructed square matches the given elements
    index = 0
    for i in range(n):
        for j in range(n):
            if square[i][j] != elements[index]:
                print("NO")
                break
            index += 1
        else:
            continue
        break
    else:
        print("YES")

*/
#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, c, d;
    cin >> n >> c >> d;
    int mn =INT_MAX;

    map<int, int> mp;
    for(int i = 0;i < n*n;i++){
        int a;
        cin >> a;
        mn = min(mn, a);
        mp[a]++;
    }
    int first = mn, row_move;
    for(int i = 0;i < n;i++){
        first = mn + i*c;
        row_move = first;
        if(!mp[row_move]){
            cout<<"NO\n";
            return;
        }
        for(int j = 0;j < n;j++){
            row_move = first + j*d;
            if(!mp[row_move]){
                cout<<"NO\n";
                return;
            }
            mp[row_move]--;
        }
    }
    cout<<"YES\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}