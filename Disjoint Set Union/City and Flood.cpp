// HackerEarth => https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int size[N];
int parent[N];

int find(int v){
    if(v == parent[v]) return v;
    return parent[v] = find(parent[v]);
}
void make(int v){
    parent[v] = v;
    ::size[v] = 1; // Specify the array size using ::size
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        if(::size[a] > ::size[b]){ // Specify the array size using ::size
            parent[b] = a;
            ::size[a] += ::size[b]; // Specify the array size using ::size
        }
        else{
            parent[a] = b;
            ::size[b] += ::size[a]; // Specify the array size using ::size
        }
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        make(i);
    }

    while(k--){
        int u, v;
        cin >> u >> v;
        Union(u, v);
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(find(i) == i){
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}
