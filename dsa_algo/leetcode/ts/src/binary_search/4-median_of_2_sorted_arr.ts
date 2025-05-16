const findMedianSortedArrays  = (nums1: number[], nums2: number[]): number =>{
    let m = nums1.length;
    let n = nums2.length;
    if(m > n)
        return findMedianSortedArrays(nums2, nums1);
    let total = m + n;
    let low = 0;
    let high = m;
    let result = 0;
    while(low <= high)
    {
        let i = Math.floor(low + (high - low) / 2);
        let j = Math.floor((total + 1) / 2 - i);
        let left1 = (i > 0) ? nums1[i - 1] : -Infinity;
        let right1 = (i < m) ? nums1[i] : Infinity;
        let left2 = (j > 0) ? nums2[j - 1] : -Infinity;
        let right2 = (j < n) ? nums2[j] : Infinity;
        if(left1 <= right2 && left2 <= right1)
        {
            if(total % 2 === 0)
            {
                result = ((Math.max(left1, left2) + Math.min(right1, right2))  / 2);
                console.log(Math.max(left1, left2))
                console.log(Math.min(right1, right2))

            }
            else
                result = Math.max(left1, left2);
            break;
        }
        else if(left1 > right2)
            high = i - 1;
        else
            low = i + 1;
    } 
    return result;
};