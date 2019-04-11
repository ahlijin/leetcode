class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	const int m = nums1.size();
	const int n = nums2.size();
	int total = m+n;
	if(total&0x1)		//奇数
		return find_kth(nums1.begin(), m, nums2.begin(), n, total/2+1);
	else
		return (find_kth(nums1.begin(), m, nums2.begin(), n, total/2)
			+ find_kth(nums1.begin(), m, nums2.begin(), n, total/2+1))/2.0;	
    }
private:
    static int find_kth(std::vector<int>::const_iterator nums1, int m,
		    std::vector<int>::const_iterator nums2, int n, int k){
	    if(m>n) return find_kth(nums2, n, nums1, m, k);		// m < n
	    if(m==0) return *(nums2+k-1);		// median of nums2
	    if(k==1) return min(*nums1, *nums2);

	    int ia = min(k/2, m), ib = k-ia;
	    if(*(nums1+ia-1) < *(nums2+ib-1))
			    return find_kth(nums1+ia, m-ia, nums2, n, k-ia);		// 删除nums1中前ia个数字
	    else if(*(nums1+ia-1) > *(nums2+ib-1))
	    		    return find_kth(nums1, m, nums2+ib, n-ib, k-ib);		// 删除nums2中前ib个数字
	    else
	    		    return nums1[ia-1];
	}
};
