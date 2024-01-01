// Leetcode - 1402

int maxSatisfaction(vector<int>& statisfaction){
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    // [-1,-8, 0, 5 -7]
    int suf[n];
    suf[n-1] = satisfaction[n-1];
    for(int i = n-2;i >= 0;i--){
        suf[i] = suf[i+1] + satisfaction[i];
    }
    // find the pivot idx
    int idx = -1;
    for(int i = 0;i < n;i++){
        if(suf[i] >= 0){
            idx = i;
            break;
        }
    }
    if(idx == -1) return 0;
    // max sum of like time coefficient
    int x = 1;
    int max = 0;
    for(int i = idx;i < n;i++){
        maxSum += (satisfaction[i]*x);
        x++;
    }
    return maxSum;
}