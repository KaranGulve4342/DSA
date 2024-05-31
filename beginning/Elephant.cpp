// // CODEFORCES 800 RATED

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n;
//     cin>>n;

//     int steps = n % 5 == 0 ? n / 5 :(n / 5) + 1;
//     cout<<steps;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[] = {5, 4, 3, 2, 1};

    int steps = 0;

    for(int i = 0;i < 5;i++){
        steps += n/a[i];
        n = n%a[i];
    }

    cout << steps << endl;
    return 0;
}