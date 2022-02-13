alist = [2,9]
def plusone (digits):
    for i in range(len(digits) -1 , -1, -1):
        if((digits[i]) <9):
            digits[i] = digits[i] + 1
            print("adding 1")
            return digits
        digits[i] = 0
        print("making it a zero")
    digits.insert(0,1)
    return digits


print(plusone(alist))
