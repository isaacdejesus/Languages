def sorted_sq1(arr):
    return sorted(x*x for x in arr)
def sorted_sq2(nums: list[int]) -> list[int]:
    arr_length = len(nums)
    result = [0] * arr_length 
    left = 0
    right = arr_length - 1
    for i in range(arr_length - 1, -1, -1):
        if abs(nums[left]) < abs(nums[right]):
            sq = nums[right]
            right -= 1
        else:
            sq = nums[left]
            left += 1
        result[i] = sq * sq
    return result

print(sorted_sq1([-4, -1, 0, 3, 10]))
print(sorted_sq2([-4, -1, 0, 3, 10]))
