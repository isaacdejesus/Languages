def duplicateZeros(arr: list[int]) -> None:
    possible_duplicates = 0
    length_ = len(arr) - 1
    for left in range(length_ + 1):
        if left > length_ - possible_duplicates:
            break
        if arr[left] == 0:
            if left == length_ - possible_duplicates:
                arr[length_] = 0
                length_ -= 1
                break
            possible_duplicates += 1
    last = length_ - possible_duplicates
    for i in range(last, -1 , -1):
        if arr[i] == 0:
            arr[i + possible_duplicates] = 0
            possible_duplicates -= 1
            arr[i + possible_duplicates] = 0
        else:
            arr[i + possible_duplicates] = arr[i]


arr = [1, 0, 2, 3, 0, 4, 5, 0]
duplicateZeros(arr)
print(arr)