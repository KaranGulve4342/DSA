// GFG POTD 1 MARCH 2024

//{ Driver Code Starts
//Initial Template for C

#include<stdio.h>
#include<stdbool.h>


// } Driver Code Ends
//User function Template for C

int peakElement(int arr[], int n)
{
    int left = 0, right = n - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        // If mid is greater than its neighbors, it's a peak
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
            return mid;
        // If the right neighbor is greater, peak is on the right side
        else if (arr[mid] < arr[mid + 1])
            left = mid + 1;
        // If the left neighbor is greater, peak is on the left side
        else
            right = mid - 1;
    }
    
    // When left == right, we have found the peak
    return left;
}

//{ Driver Code Starts.

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int a[n], tmp[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d", &a[i]);
			tmp[i] = a[i];
		}
		bool f=0;
		
		int A = peakElement(tmp,n);
		
		if(A<0 && A>=n)
		    printf("0\n");
		else
		{
    		if(n==1 && A==0)
    		    f=1;
    		else if(A==0 && a[0]>=a[1])
    		    f=1;
    		else if(A==n-1 && a[n-1]>=a[n-2])
    		    f=1;
    		else if(a[A]>=a[A+1] && a[A]>= a[A-1])
    		    f=1;
    		else
    		    f=0;
    		printf("%d\n", f);
		}
		
	}

	return 0;
}
// } Driver Code Ends