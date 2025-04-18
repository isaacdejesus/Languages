def max_sub_arr_of_size_k(k, arr):
    max_sum = 0;
    window_sum = 0;
    for i in range(len(arr) - k + 1):
        window_sum = 0;
        for j in range(i, i + k):
            window_sum += arr[j]
        max_sum = max(max_sum, window_sum)
    return max_sum

def main():
    print("Max sum of a subarray of size k: " + str(max_sub_arr_of_size_k(3, [2, 1, 5, 1, 3, 2])))
    print("Max sum of a subarray of size k: " + str(max_sub_arr_of_size_k(2, [2, 3, 4, 1, 5])))

main()
