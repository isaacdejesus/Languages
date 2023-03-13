class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       merge_sort(nums, 0, nums.size() - 1) ;
       return nums;
    }
    void merge_sort(std::vector<int> &vec, int start, int end)
    {
        if(start < end)
        {
            int mid = (start + end) /2;
            merge_sort(vec, start, mid);
            merge_sort(vec, mid + 1, end);
            merge(vec, start, mid, end);
        }
    }
    void merge(std::vector<int>&vec, int start, int mid, int end)
    {
        std::vector<int> temp;
        temp.reserve(end - start + 1);
        int i = start, j = mid + 1, k = 0;
        while(i <= mid && j <= end)
        {
            if(vec[i] <= vec[j])
                temp[k++] = vec[i++];
            else 
                temp[k++] = vec[j++];
        }
        while(i <= mid)
        {
            temp[k] = vec[i];
            k++;
            i++;
        }
        while(j <= end)
        {
            temp[k] = vec[j];
            k++;
            j++;
        }
        for(i = start; i <= end; i++)
            vec[i] = temp[i - start];

    }
};