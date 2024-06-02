// CODEFORCES 800 RATED

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str = "";
    str += "I hate";
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            str += " that I love";
        } else {
            str += " that I hate";
        }
    }
    str += " it";
    cout<<str<<endl;
    return 0;
}