// Leetcode 328

/*
int hcf(int a,int b){
    if(a == 0) return b;
    else return hcf(b%a, a);
}
bool isBeautiful(int a,int b){
    while(a >= 10){
        a = a/10;
    }
    b = b%10;
    if(hcf(a,b) == 1) return true;
    else return false;
}
int countBeautifulPairs(vector<int>& arr){
    int n = arr.size();
    int count = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            if(isBeautiful(arr[i],arr[j])) count++;
        }
    }
    return count;
}
*/