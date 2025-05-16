def happy_number(num):
    slow, fast = num, num
    while True:
        slow = find_sq_sum(slow)
        fast = find_sq_sum(find_sq_sum(fast))
        if slow == fast:
            break
    return slow == 1

def find_sq_sum(num):
    _sum = 0
    while(num > 0):
        digit = num % 10
        _sum += digit * digit
        num //=10
    return _sum

def main():
    print(happy_number(23))
    print(happy_number(12))
main()

