import math
def has_even_digits(num: int) -> bool:
    digit_count = 0
    while num:
        digit_count +=1
        num = num //10
    return digit_count & 1 == 0
def f1(nums: list[int]):
    even_digits_count = 0
    for num in nums:
        if has_even_digits(num):
            even_digits_count += 1
    return even_digits_count

def f2(nums: list[int]):
    even_digits_count = 0
    for num in nums:
        current_number_length = len(str(num))
        if current_number_length % 2 == 0:
            even_digits_count += 1
    return even_digits_count

def f3(nums: list[int]):
    even_digits_count = 0
    for i in nums:
        current_digit_length = int(math.floor(math.log10(i))) + 1
        if current_digit_length % 2 == 0:
            even_digits_count+= 1
    return even_digits_count
arr = [12, 345, 2, 6, 7869]
print(f3(arr))
print(f2(arr))
print(f1(arr))
