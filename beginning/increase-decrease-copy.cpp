//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####


//####   Subscribe To ---------------Type 7 Shady--------------- On Youtube   ####




#include <bits/stdc++.h>
using namespace std;

long long int karan(){
    int n;
    cin>>n;

    long long int min_operations = 0;
    long long int ok = 0;
    long long int temp = 1000000000000000;

    vector<long long int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    vector<long long int> brr(n+1);
    for(int i = 0;i <= n;i++){
        cin >> brr[i];
    }
    long long int back_element = brr.back();
    
    for(int i=0;i < n;i++){
        min_operations += abs(arr[i]-brr[i]);

        if(temp > abs(arr[i]-back_element)){
            temp = abs(arr[i]-back_element);
        }

        if(temp > abs(brr[i]-back_element)){
            temp = abs(brr[i]-back_element);
        }

        if(back_element<=max(arr[i],brr[i]) && back_element>=min(arr[i],brr[i])){
            ok = 1;
        }
    }

    if(ok == 1){
        min_operations += 1;
        return min_operations;
    }
    else{
        min_operations += temp;
        min_operations += 1;
        return min_operations;
    }
}



int main() {
 int T;
 cin >> T;

 while(T--){
        cout<<karan()<<endl;
    }

 return 0;
}

