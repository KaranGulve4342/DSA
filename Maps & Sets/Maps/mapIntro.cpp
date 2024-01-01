#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    // creation
    unordered_map<string, int> umap;

    // insertion
    // 1
    pair<string, int>p = make_pair("babbar",3);
    umap.insert(p);

    // 2
    pair<string,int> pair2("love",2);
    umap.insert(pair2);

    // 3
    umap["mera"] = 1;

    // updation
    umap["mera"] = 9;

    // search
    cout<<umap["mera"]<<endl;
    cout<<umap.at("babbar")<<endl;

    // cout<<umap.at("unknownKey")<<endl; // error : 'out of range'
    cout<<umap["unknownKey"]<<endl; // display '0'

    cout<<umap["unknownKey"]<<endl; // display '0'
    cout<<umap.at("unknownKey")<<endl; // display '0'

    // size
    cout<<umap.size()<<endl;

    // to check presence
    cout<<umap.count("bro")<<endl; // returns 0 if not present
    cout<<umap.count("love")<<endl; // return 1 in presence

    // erase
    umap.erase("love");
    cout<<umap.size()<<endl;

    // traversing through the map
    for(auto i : umap){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    // iterator
    unordered_map<string,int> :: iterator it = umap.begin();
    while(it != umap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    cout<<endl;

    return 0;
}