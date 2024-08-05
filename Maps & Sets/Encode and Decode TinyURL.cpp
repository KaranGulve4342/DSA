// LEETCODE 535

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, string> umap;

    int randomNumberGenerator(){
        return rand() % 10;
    }

    char randomSmallAlphaGenerator(){
        int n = rand() % 26;
        return n + 'a';
    }

    char randomBigAlphaGenerator(){
        int n = rand() % 26;
        return n + 'A';
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string temp = "";

        for(int i = 0;i < 6;i++){
            int choice = rand() % 3;

            if(choice == 0){
                temp += to_string(randomNumberGenerator());
            }
            else if(choice == 1){
                temp += randomSmallAlphaGenerator();
            }
            else{
                temp += randomBigAlphaGenerator();
            }
        }

        string ans = "http://deveekly.com/";
        ans += temp;

        return umap[longUrl] = ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // int n = shortUrl.length();

        // string str = shortUrl.substr(n-6);

        for(auto x : umap){
            if(x.second == shortUrl){
                return x.first;
            }
        }

        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));