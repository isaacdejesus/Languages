class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        length = len(nums)
        for i in range(length):
            if nums[i] != val:
                nums[k] = nums[i]
                k += 1
        return k
