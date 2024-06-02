// CODEFORCES 800 RATED

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    unordered_set<int> colors = {s1, s2, s3, s4};
    
    int additional_horseshoes_needed = 4 - colors.size();

    cout << additional_horseshoes_needed << endl;

    return 0;
}
