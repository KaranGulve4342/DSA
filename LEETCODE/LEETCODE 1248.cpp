/*
int numberOfSubarrays(vector<int> &a,int k){
    int n = a.size();
    int i = 0;
    int j = 0;
    int count = 0;
    int ans = odd;
    int odd = 0;
    while(j < n){
        if(a[i] % 2 != 0){
            count = 0;
            odd ++;
        }
        while(i<=j and odd == k){
            count++;
            if(a[i++]%2 != 0){
                odd--;
            }
        }
        ans += count;
        j++;
    }
    return ans;
}
*/