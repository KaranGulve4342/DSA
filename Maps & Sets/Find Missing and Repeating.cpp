// GFG 
/*
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
    
        unordered_map<int, int> hash;// hash array
    
        //update the hash array:
        for (int i = 0; i < n; i++) {
            hash[a[i]]++;
        }
    
        //Find the repeating and missing number:
        int repeating = -1;
        int missing = -1;
        
        for (int i = 1; i <= n; i++) {
            if (hash[i] == 2){
                repeating = i;
            }
            else if (hash[i] == 0){
                missing = i;
            }
            if (repeating != -1 && missing != -1){
                break;   
            }
        }
        return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
*/

// OPTIMAL APPROACH USING MATH 
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> a, int n) {
        
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2*n + 1)) / 6;
    
        // Calculate S and S2:
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += a[i];
            S2 += ((long long)a[i] * (long long)a[i]);
        }
    
        //S-Sn = X-Y:
        long long val1 = S - SN;
    
        // S2-S2n = X^2-Y^2:
        long long val2 = S2 - S2N;
    
        //Find X+Y = (X^2-Y^2)/(X-Y):
        val2 = val2 / val1;
    
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
    
        return {(int)x, (int)y};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*

// ANOTHER OPTIMAL APPROACH USING XOR
// TIME COMPLEXITY: O(N)
// SPACE COMPLEXITY: O(1)

#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a) {
    int n = a.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((a[i] & number) != 0) {
            one = one ^ a[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ a[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}

*/