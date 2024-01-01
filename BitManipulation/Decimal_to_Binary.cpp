#include <iostream>
using namespace std;

string decimal_to_binary(int num){
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
        //  num = num / 2;
         num = num >> 1;
    }
    return
}

int main()
{
    string str =  "001011";
    cout<<binary_to_decimal(str)<<"\n";
    cout<<decimal_to_binary(13)<<"\n";
    
    return 0;
}