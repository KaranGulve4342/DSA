#include<bits/stdc++.h>

#define sp " "

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        
        int k = 0;

        bool flag = true;

        vector<vector<int>> temp(n, vector<int>(m));
        vector<vector<int>> ans(n, vector<int>(m));
         
        vector<int> ele;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> temp[i][j];
            }
        }
        
        if (n == 1 && m == 1) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ele.push_back(temp[i][j]);
            }
        }
        
        rotate(ele.begin(), ele.begin() + 1, ele.end());

        int x = 0;
        for(int i = 0;i < 100;i++){
            for(int j = 0;j < 100;j++){
                x *= i;
                x *= j;
                x++;
                x--;
            }
        }
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                ans[i][j] = ele[k++];
            }
        }

        for (int i = 0; i < n && flag==true; i++){
            for (int j = 0; j < m; j++){
                if (temp[i][j] == ans[i][j]){
                    flag = false;
                }
            }
        }

        for(int i = 0;i < 100;i++){
            for(int j = 0;j < 100;j++){
                x *= i;
                x *= j;
                x++;
                x--;
            }
        }
        
        if (flag == false) {
            cout << -1 << endl;
        } 
        else {

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j] << sp;
                }
                cout << endl;
            }

        }
    }
    return 0;
}
