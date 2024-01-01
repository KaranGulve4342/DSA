#include <iostream>
#include<unordered_map>
using namespace std;

int main()
{
    // pair<string, char> p;
    // p.first = "raghav";
    // p.second = 'A';
    // cout<<p.first<<" "<<p.second<<endl;
    
    unordered_map<string,int> m;
    pair<string, int> p1;
    p1.first = "raghav";
    p1.second = 76;
    m.insert(p1);

    // pair<string, int> p2;
    // p2.first = "shiro";
    // p2.second = 07;
    // pair<string, int> p3;
    // p3.first = "jodh";
    // p3.second = 45;
    // m.insert(p2);
    // m.insert(p3);

    m["om"] = 28;
    m["adi"] = 67;
    
    for(pair<string, int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size();
    cout<<endl;
    m.erase("adi");

    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size();

    return 0;
}