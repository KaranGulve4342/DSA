// LEETOCDE 1343

/*
int numOfSubarrays(vector<int>& arr,int k,int threshold){
    int n = arr.size();
    int maxIdx = 0;
    int sum = 0;

    for(int i = 0;i < k;i++){
        sum += arr[i];
    }
    int count = 0;
    int i = 1;
    int j = k;
    if(sum/k >= threshold){
        count++;
    }
    while(j < n){
        sum = sum + arr[j] - arr[i - 1];
        if(sum/k >= threshold){
            count++;
            maxIdx = i;
        }
        i++;
        j++;
    }
    return count;
}
*/