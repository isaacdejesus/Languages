def find_avgs_of_subarrs(k, arr):
    result =[]
    for i in range(len(arr) - k + 1):
        _sum = 0.0
        for j in range(i, i + k):
            _sum += arr[j]
        result.append(_sum/k)
    return result

def main():
    result = find_avgs_of_subarrs(5, [1, 3, 4, 6, -1, 4, 1, 8, 2])
    print("avgs of subarrays of size K: " + str(result))

main()
