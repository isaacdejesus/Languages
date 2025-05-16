def find_substring(str, pattern):
    window_start, matched, substring_start = 0, 0, 0
    min_length = len(str) + 1
    char_freq = {}
    for chr in pattern:
        if chr not in char_freq:
            char_freq[chr] = 0
        char_freq[chr] += 1
    for window_end in range(len(str)):
        right_char = str[window_end]
        if right_char in char_freq:
            char_freq[right_char] -= 1
            if char_freq[right_char] >= 0:
                matched += 1
                while matched == len(pattern):
                    if min_length > window_end - window_start + 1:
                        min_length = window_end - window_start + 1
                        substring_start = window_start
                    left_char = str[window_start]
                    window_start += 1
                    if left_char in char_freq:
                        if char_freq[left_char] == 0:
                            matched -= 1
                        char_freq[left_char] += 1
    if min_length > len(str):
        return ""
    return str[substring_start: substring_start + min_length]

def main():
    print(find_substring("aabdec", "abc"))
    print(find_substring("abdabca", "abc"))
    print(find_substring("adcad", "abc"))

main()

