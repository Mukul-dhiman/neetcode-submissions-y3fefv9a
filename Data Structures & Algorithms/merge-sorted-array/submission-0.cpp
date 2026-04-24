class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i>=0;i--){
            nums1[i+n]=nums1[i];
        }
        int i=n,j=0,k=0;
        // for(int p=0;p<m+n;p++){
        //     cout<<nums1[p]<<" ";
        // }
        while(i<m+n and j<n){
            if(nums1[i]<=nums2[j]){
                nums1[k]=nums1[i];
                i++;k++;
            }
            else{
                nums1[k]=nums2[j];
                j++;k++;
            }
        }
        while(j<n){
            nums1[k]=nums2[j];
            j++;k++;
        }
        while(i<m+n){
            nums1[k]=nums1[i];
            i++;k++;
        }
    }
};