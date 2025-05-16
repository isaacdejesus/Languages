def backspace_compare(str1, str2):
    index_1 = len(str1) - 1
    index_2 = len(str2) - 1
    while(index_1 >= 0 or index_2 >= 0):
        i_1 = get_next_valid_char_index(str1, index_1)
        i_2 = get_next_valid_char_index(str2, index_2)
        if i_1 < 0 and i_2 < 0:
            return True
        if i_1 < 0 or i_2 < 0:
            return False
        if str1[i_1] != str2[i_2]:
            return False
        index_1 = i_1 - 1
        index_2 = i_2 - 1
    return True

def get_next_valid_char_index(str, index):
    backspace_count = 0
    while(index >= 0):
        if str[index] == '#':
            backspace_count += 1
        elif backspace_count > 0:
            backspace_count -= 1
        else:
            break
        index -= 1 
    return index

def main():
    print(backspace_compare("xy#z", "xzz#"))
    print(backspace_compare("xy#z", "xyz#"))
    print(backspace_compare("xp#", "xyz##"))
    print(backspace_compare("xywrrmp", "xywrrmu#p"))


main()
