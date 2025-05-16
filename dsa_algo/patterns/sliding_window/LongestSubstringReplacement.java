import java.util.*;
class LongestSubstringReplacement {
    public static int find_length(String str, int k)
    {
        int window_start = 0;
        int max_length = 0;
        int max_repeat_letter_count = 0;
        Map<Character, Integer> letter_freq = new HashMap<>();
        for(int window_end = 0; window_end < str.length(); window_end++)
        {
            char right_char = str.charAt(window_end);
            letter_freq.put(right_char, letter_freq.getOrDefault(right_char, 0) + 1);
            max_repeat_letter_count = Math.max(max_repeat_letter_count, letter_freq.get(right_char));
            if(window_end - window_start + 1 - max_repeat_letter_count > k)
            {
                char left_char = str.charAt(window_start);
                letter_freq.put(left_char, letter_freq.get(left_char) - 1);
                window_start++;
            }
            max_length = Math.max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
    public static void main(String[] args)
    {
        System.out.println(LongestSubstringReplacement.find_length("aabccbb", 2));
        System.out.println(LongestSubstringReplacement.find_length("abbcb", 1));
        System.out.println(LongestSubstringReplacement.find_length("abccde", 1));
    }
}
