#include <iostream>
using namespace std;

int main()
{
    // brian kernighan algorithm
    int x = 23;
    int y = x;
    int temp;
    while(x != 0){
        temp = x;
        x = x & (x-1);
    }
    
    
    
    return 0;
}