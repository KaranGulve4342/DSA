/*class Solution {
public:
    void merge(vector<int>& nums1, vector<int>& nums2, vector<int>& ans){
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < nums1.size() && j < nums2.size()){
            
            if(nums1[i] < nums2[j]){
                ans[k++] = nums1[i++];
            }
            else ans[k++] = nums2[j++];
        }
        
        while(j < nums2.size()){
            ans[k++] = nums2[j++];
        }
        
        
        while(i < nums1.size()){
            ans[k++] = nums1[i++];
        }
        

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int total_size = nums1.size() + nums2.size();
        vector<int> ans(total_size);

        merge(nums1,nums2,ans);
        
        int start = 0;
        int end = ans.size() - 1;

        int mid = total_size/2;

        if(total_size%2!=0){
            return ans[mid];
        }
        else return (ans[mid] + ans[mid-1])/2.0;

        return 0;
    }
};*/