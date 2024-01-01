#include<iostream>
using namespace std;

int binary_to_decimal(string &binary){
    int n = binary.size();
    int result = 0;
    for(int i = n - 1;i >= 0;i--){
        char ch = binary[i];
        int num = ch - '0';
        result = result + num*(1 << (n - i - 1));
    }
    return result;
}

string decimal_To_Binary(int num){
    string result = "";
    while(num > 0){
        if(num%2 == 0){
            // even
            result = "0" + result;
        }
        else{
            // odd
            result = "1" + result;
        }
        num = num/2;
    }
    return result;
}

int count_set_bits(int n){
    return __builtin_popcount(n);
}

int count_set_bits_2(int n){
    int count = 0;
    while(n > 0){
        count++;
        n = (n & (n-1));
    }
    return count;
}

int main(){
    string str = "001011";
    // cout<<binary_to_decimal(str)<<"\n";
    // cout<<decimal_To_Binary(13)<<"\n";

    cout<<count_set_bits_2(15);
    return 0;
}