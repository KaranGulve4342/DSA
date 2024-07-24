// CODESHEF CONTEST 

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> freq;

vector<int> solve1(const map<int, int>& umap) {
    for (auto it : umap) {
        freq.push_back(it.second);
    }
    return freq;
}

int solve2(const vector<int>& freq) {
    int sum = 0;
    int ans = 0;
    int n = freq.size();
    for (int i = 1; i <= n; ++i) {
        sum += freq[i - 1];

        int value = (sum / i) * i;

        ans = max(ans, value);
    }

    return ans;
}

int solve() {
    int N;
    cin >> N;

    map<int, int> umap;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for(auto a : arr){
        umap[a]++;
    }
    freq.clear();
    solve1(umap);

    sort(freq.begin(), freq.end(), greater<int>());

    int ans = solve2(freq);

    return ans;
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        cout<<solve()<<endl;
    }
    return 0;
}