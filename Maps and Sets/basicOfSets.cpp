#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(5);
    cout<<s.size()<<endl;
    s.erase(4);
    // for each loop
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    // for(auto ele : s){
    //     cout<<ele<<" ";
    // }
    // cout<<endl;

    // s.find() searches In set and if not found s.end() which is iterator next to the last value in set
    int target = 30;
    if(s.find(target) !=s.end()){
        // target exists
        cout<<"exists"<<endl;
    }
    else cout<<"does not exists"<<endl;
}