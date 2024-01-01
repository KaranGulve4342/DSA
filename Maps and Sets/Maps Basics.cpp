#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    /*
    pair<string,char> p;
    p.first = "VIIT";
    p.second = 'A';

    cout<<p.first<<" "<<p.second;
    */

    unordered_map<string,int> m;
    pair<string,int>p1;
    p1.first = "VIIT";
    p1.second = 22;
    // pair<string,int>p2;
    // p2.first = "VIT";
    // p2.second = 23;
    // pair<string,int>p3;
    // p3.first = "IIT";
    // p3.second = 20;
    m.insert(p1);
    // m.insert(p2);
    // m.insert(p3);
    m["Harsh"] = 15;
    m["lokesh"] = 55;

    // for(pair<string,int> p:m){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size();
    cout<<endl;
    m.erase("Harsh");
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size();



   
}