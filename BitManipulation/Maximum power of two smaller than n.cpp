#include <iostream>
using namespace std;

int max_power_of2(int n){
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n+1)>>1;
}

int main()
{
    // brian kernighan algorithm
    int x = 23;
    int temp;
    while(x != 0){
        temp = x;
        x = x & (x-1);
    }
    cout<<temp<<"\n";
    
    int y = 23;
    cout<<max_power_of2(y)<<"\n";
    return 0;
}