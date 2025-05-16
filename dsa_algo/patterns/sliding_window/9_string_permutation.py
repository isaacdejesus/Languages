def find_permutation(str, pattern):
    window_start, matched = 0, 0
    char_freq = {}
    for chr in pattern:
        if chr not in char_freq:
            char_freq[chr] = 0;
        char_freq[chr] += 1
    for window_end in range(len(str)):
        right_char = str[window_end]
        if right_char in char_freq:
            char_freq[right_char] -= 1
            if char_freq[right_char] == 0:
                matched += 1
        if matched == len(char_freq):
            return True
        if window_end >= len(pattern) -1:
            left_char = str[window_start]
            window_start += 1
            if left_char in char_freq:
                if char_freq[left_char] == 0:
                    matched -= 1
                char_freq[left_char] += 1
    return False

def main():
    print('Permutation exists: ' + str(find_permutation("oidbcaf", "abc")));
    print('Permutation exists: ' + str(find_permutation("odicf", "dc")));
    print('Permutation exists: ' + str(find_permutation("bcdxabcdy", "bcdyabcdx")));
    print('Permutation exists: ' + str(find_permutation("aaacb", "abc")));


main()
