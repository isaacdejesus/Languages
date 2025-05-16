def longest_substring_k_distinct(str, k):
    window_start = 0
    max_length = 0
    char_freq = {}
    for window_end in range(len(str)):
        right_char = str[window_end]
        if right_char not in char_freq:
            char_freq[right_char] = 0
        char_freq[right_char] += 1
        while len(char_freq) > k:
            left_char = str[window_start]
            char_freq[left_char] -= 1
            if char_freq[left_char] == 0:
                del char_freq[left_char]
            window_start += 1
        max_length = max(max_length, window_end - window_start + 1)
    return max_length


def main():
    print("Length of the longest substring: " + str(longest_substring_k_distinct("araaci", 2)))
    print("Length of the longest substring: " + str(longest_substring_k_distinct("araaci", 1)))
    print("Length of the longest substring: " + str(longest_substring_k_distinct("cbbebi", 3)))
main()
