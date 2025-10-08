class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        insert_loc = 1
        length = len(nums)
        for i in range(1, length):
            if nums[i] != nums[i - 1]:
                nums[insert_loc] = nums[i]
                insert_loc += 1
        return insert_loc