def max_consecutive_ones(nums: list[int]) -> int:
    max_count = 0
    current_count = 0
    for num in nums:
        if(num == 0):
            max_count = max(max_count, current_count)
            current_count = 0
        else:
            current_count+= 1
    return max(max_count, current_count)

arr = [1, 0, 1, 1, 0, 1]
print(max_consecutive_ones(arr))
