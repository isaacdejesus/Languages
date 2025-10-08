class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        p1 = m - 1
        p2 = n - 1
        for insert_loc in range(n + m - 1, -1, -1):
            if p2 < 0:
                break
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[insert_loc] = nums1[p1]
                p1 -= 1
            else:
                nums1[insert_loc] = nums2[p2]
                p2 -= 1
