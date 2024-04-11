#include <iostream>
#include <vector>
using namespace std;

string can_be_eighth_power(int N, vector<int>& array) {
    int count_of_twos = 0;
    for (int i = 0; i < N; i++) {
        if (array[i] == 2) {
            count_of_twos++;
        }
    }
    
    if (count_of_twos % 8 == 0) {
        return "YES";
    } else {
        return "NO";
    }
}

vector<string> process_test_cases(int T, vector<pair<int, vector<int>>>& test_cases) {
    vector<string> results;
    for (int i = 0; i < T; i++) {
        int N = test_cases[i].first;
        vector<int> array = test_cases[i].second;
        string result = can_be_eighth_power(N, array);
        results.push_back(result);
    }
    return results;
}

int main() {
    int T;
    cin >> T;
    vector<pair<int, vector<int>>> test_cases;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> array(N);
        for (int j = 0; j < N; j++) {
            cin >> array[j];
        }
        test_cases.push_back({N, array});
    }
    
    vector<string> results = process_test_cases(T, test_cases);
    
    for (string result : results) {
        cout << result << endl;
    }
    
    return 0;
}
