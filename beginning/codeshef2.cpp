#include<bits/stdc++.h>
using namespace std;

int solve(){
    int m;
    cin >> m;
    vector<int> c(m);
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    stack<int> stacks;
    stack<int> index;
    long long cost = 0;

    for (int i = 0; i < m; ++i) {
        while (stacks.size() > 1 && stacks.top() > c[i]) {
            int c1 = stacks.top();
            stacks.pop();
            if (c1 >= stacks.top()) {
                index.pop();
            } else {
                stacks.push(c1);
                break;
            }
        }
        stacks.push(c[i]);
        index.push(i);
    }

    int last = stacks.top();
    stacks.pop();
    int g = index.top();
    index.pop();

    while (!stacks.empty()) {
        cost += max(last, stacks.top()) * (g - index.top());
        last = stacks.top();
        stacks.pop();
        g = index.top();
        index.pop();
    }
    return cost;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cout<<solve()<<endl;
    }

    return 0;
}
