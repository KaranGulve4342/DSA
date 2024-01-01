#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int> s; // stores unique element
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(3);
    s.erase(2); // erase

    int target = 4;
    // s.find() => it searches in the set and if it is not found then it returns the last element.
    if(s.find(target) != s.end()){
        // target exists
        cout<<"Exists"<<endl;
    }
    else{
        cout<<"does not exists"<<endl;
    }

    cout<<s.size()<<endl; // size

    // for each loop
    for(int ele : s){
        cout<<ele<<" ";
    }
}