// Leetcode 443.cpp

/*
int compress(vector<char>& arr){
    string s = "";
    int n = arr.size();
    int i = 0;
    int j = 0;
    while(j<n){
        if(arr[j] == arr[i]) j++;
        else{
            s+=arr[i];
            int len = j-i;
            if(len != 1){
                s += to_string(len);
            }
            i = j;
        }
    }
    s+=arr[i];
    int len = j-i;
    if(len != 1){
        s += to_string(len);
    }
    while(arr.size() > 0){
        arr.pop_back;
    }
    for(int i = 0;i < s.length();i++){
        arr.push_back(s[i]);
    }
    return s.length();
}
*/