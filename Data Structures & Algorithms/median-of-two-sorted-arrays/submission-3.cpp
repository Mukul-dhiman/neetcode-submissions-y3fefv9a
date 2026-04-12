class Solution {
    double find(vector<int>& nums1, vector<int>& nums2){
	vector<int>& A = nums1;
	vector<int>& B = nums2;
	int  n= nums1.size();
	int m=nums2.size();
	int total = n+m;
	int half = (n+m)/2;
	
	if(n<m){
		swap(A,B);
        n,m = m,n;
	}
    n = A.size();
	m = B.size();
    if(m==0){
        if(total%2!=0)  return A[total/2];
        return (A[total/2] + A[(total/2)-1])/2.0;
    }
    cout<<"A";
    for(auto el:A) cout<<el<<" ";
    cout<<endl;

    cout<<"B";
    for(auto el:B) cout<<el<<" ";
    cout<<endl;

	int l =-1, r = m;
	while(l<=r){
		int mid = (l+r)/2;
		int a_itr = half - mid -2;
        cout<<l<<" "<<r<<endl;
        cout<<mid<<" "<<a_itr<<endl;
		cout<<"---"<<endl;
		int aleft = a_itr>=0? A[a_itr]: INT_MIN;
		int aright = a_itr+1<n?A[a_itr+1]: INT_MAX;
		int bright = mid+1<m?B[mid+1]:INT_MAX;
		int bleft = mid>=0?B[mid]:INT_MIN;
        cout<<aleft<<" - "<<aright<<" | "<<bleft<<" - "<<bright<<endl;

		if(aleft<=bright && bleft<=aright){
			if(total%2!=0)	return min(aright, bright);
			return (max(aleft,bleft) + min(aright, bright))/2.0;
		}
		else if(aleft>bright){
			l = mid+1;
		}
		else{
			r=mid-1;
		}
	}	
	return -1;
}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        return find(nums1, nums2);
    }
};
