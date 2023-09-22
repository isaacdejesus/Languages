class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int insert_loc = m + n - 1;
       while(m > 0 and n > 0) 
       {
           if(nums1[m - 1] > nums2[n - 1])
           {
               nums1[insert_loc] = nums1[m - 1];
               m--;
           }
           else
           {
               nums1[insert_loc] = nums2[n - 1];
               n--;
           }
           insert_loc--;
       }
       while(n > 0)
       {
           nums1[insert_loc] = nums2[n - 1];
           n--;
           insert_loc--;
       }
    }
};