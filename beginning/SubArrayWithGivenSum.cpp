/*
vector<int> subarraySum(vector<int> arr, int n, long long s) {
    int left = 0;
    int right = 0;
    vector<int> result;
    long long sum = 0;

    while (right < n && left <= right) {
        sum += arr[right];

        while (sum > s && left <= right) {
            sum -= arr[left];
            left++;
        }

        if (sum == s) {
            result.push_back(left + 1);  // Adjust for 1-based indexing
            result.push_back(right + 1); // Adjust for 1-based indexing
            return result;
        }

        right++;
    }

    result.clear(); // Clear any previously added indices.
    result.push_back(-1); // If no subarray found
    return result;
}
*/