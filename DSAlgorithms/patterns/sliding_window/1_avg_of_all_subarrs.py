def find_avgs_of_subarrs(k, arr):
    result = []
    window_sum, window_start = 0.0, 0
    for window_end in range(len(arr)):
        window_sum += arr[window_end]
        if window_end >= k - 1:
            result.append(window_sum / k)
            window_sum -= arr[window_start]
            window_start += 1
    return result

def main():
    result = find_avgs_of_subarrs(5, [1, 3, 2, 6, -1, 4, 1, 8, 2])
    print("Avg of subarrays of size k: " + str(result))

main()
