/*
int numOfSubarrays(vector<int>& a,int k, int th){
    int n = a.size();
    int sum = 0;
    int avg = 0;
    int count = 0;

    for(int i = 0;i < k;i++){
        sum += a[i];
    }
    avg = sum/k;
    if(avg >= th){
        count++;
    }
    int i = k;
    while(i < n){
        sum = sum - a[i-k] + a[i];
        avg = sum/k;
        if(avg > th){
            count++;
        }
        i++;

    }
    return count;

    
}
*/