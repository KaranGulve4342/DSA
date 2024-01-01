#include <iostream>
#include<set> // syntax for ordered set
#include<map> // syntax for ordered map
using namespace std;

int main()
{   /*
    set<int> s;
    s.insert(5);
    s.insert(2);
    s.insert(7);
    for(int ele : s){
        cout<<ele<<" ";
    }
    // printing always in ordered ( Ascending ) manner
    return 0;
    */
    /*
    map<int, int> m;
    m[2] = 30;
    m[3] = 10;
    m[1] = 20;
    // printing always in ordered ( Ascending ) manner
    for(auto x : m){
        cout<<x.first<<" ";
    }
    cout<<endl;
    for(auto x : m){
        cout<<x.second<<" ";
    }
    */
    map<string, int> m;
    m["Raghav"] = 30;
    m["Vedant"] = 10;
    m["Pranali"] = 20;
    // printing always in ordered ( Ascending ) manner
    for(auto x : m){
        cout<<x.first<<" ";
    }
    cout<<endl;
    for(auto x : m){
        cout<<x.second<<" ";
    }
}