def make_squares(arr):
    n = len(arr)
    squares = [0 for x in range(n)]
    highest_sq_index = n - 1
    left, right = 0, n - 1
    while left <= right:
        left_sq = arr[left] * arr[left]
        right_sq = arr[right] * arr[right]
        if left_sq > right_sq:
            squares[highest_sq_index] = left_sq
            left +=1
        else:
            squares[highest_sq_index] = right_sq
            right -= 1
        highest_sq_index -= 1
    return squares

def main():
    print("Squares: " + str(make_squares([-2, -1, 0, 2, 3])))
    print("Squares: " + str(make_squares([-3, -1, 0, 1, 2])))


main()
