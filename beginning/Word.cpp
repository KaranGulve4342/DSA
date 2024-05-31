// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    int up = 0;
    int lo = 0;

    // Count the number of uppercase and lowercase letters
    for(auto ch : str){
        if(isupper(ch)){
            up++;
        }
        else{
            lo++;
        }
    }

    // Convert the word to uppercase if there are more uppercase letters, otherwise to lowercase
    if(up > lo){
        for(int i = 0; i < str.length(); i++){
            str[i] = toupper(str[i]);
        }
    }
    else{
        for(int i = 0; i < str.length(); i++){
            str[i] = tolower(str[i]);
        }
    }

    cout << str << endl;
    return 0;
}
