def search_quad(arr, target):
    arr.sort()
    quadruplets = []
    for i in range(0, len(arr) -3):
        if i > 0 and arr[i] == arr[i - 1]:
            continue
        for j in range(i + 1, len(arr) - 2):
            if j > i + 1 and arr[j] == arr[j - 1]:
                continue
            search_pairs(arr, target, i, j, quadruplets)
    return quadruplets

def search_pairs(arr, target_sum, first, second, quadruplets):
    left = second + 1
    right = len(arr) - 1
    while(left < right):
        sum = arr[first] + arr[second] + arr[left] + arr[right]
        if sum == target_sum:
            quadruplets.append([arr[first], arr[second], arr[left], arr[right]])
            left += 1
            right -= 1
            while(left < right and arr[left] == arr[left -1]):
                left += 1
            while(left < right and arr[right] == arr[right + 1]):
                right -= 1
        elif sum < target_sum:
            left += 1
        else:
            right -= 1
def main():
    print(search_quad([4, 1, 2, -1, 1, -3], 1))
    print(search_quad([2, 0, -1, 1, -2, 2], 2))
main()
