import math
def triplet_sum_close_target(arr, target_sum):
    arr.sort()
    smallest_dif = math.inf
    for i in range(len(arr) - 2):
        left = i + 1
        right = len(arr) - 1
        while(left < right):
            target_dif = target_sum - arr[i] - arr[left] - arr[right]
            if target_dif == 0:
                return target_sum - target_dif
            if abs(target_dif) < abs(smallest_dif) or (abs(target_dif) == abs(smallest_dif) and target_dif > smallest_dif):
                smallest_dif = target_dif
            if target_dif > 0:
                left +=1
            else:
                right -=1
    return  target_sum - smallest_dif
def main():
    print(triplet_sum_close_target([-2, 0, 1, 2], 2))
    print(triplet_sum_close_target([-3, -1, 1, 2], 1))
    print(triplet_sum_close_target([1, 0, 1, 1], 100))

main()
