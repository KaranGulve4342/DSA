#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& arr){
    int n = arr.size();

    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());
    vector<int> freq;
    int frequency = 1;

    

    for(int i = 1;i < n;i++){
        if(sorted[i] == (sorted[i - 1])){
            frequency++;   
        }
        else{
            freq.push_back(frequency);
            frequency = 1;
        }
    }
    freq.push_back(frequency);


    sort(freq.begin(),freq.end());   
    for(int i = 0;i < freq.size();i++){
        if(freq[i] = freq[i + 1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int>arr = {1,2,2,3,3,3};
    if(checkEqualFrequency(arr)){
        cout<<"Frequencies are equal"<<endl;
    }
    else{
        cout<<"Frequencies are not equal"<<endl;
    }

    return 0;
}