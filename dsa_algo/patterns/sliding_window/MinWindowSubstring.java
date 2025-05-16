import java.util.*;
class MinWindowSubstring {
    public static String find_substring(String str, String pattern)
    {
        int window_start = 0;
        int matched = 0;
        int min_length = str.length() + 1;
        int substr_start = 0;
        Map<Character, Integer> char_freq = new HashMap<>();
        for(char chr : pattern.toCharArray())
            char_freq.put(chr, char_freq.getOrDefault(chr, 0) + 1);
        for(int window_end = 0; window_end < str.length(); window_end++)
        {
            char right_char = str.charAt(window_end);
            if(char_freq.containsKey(right_char))
            {
                char_freq.put(right_char, char_freq.get(right_char) - 1);
                if(char_freq.get(right_char) >= 0)
                    matched++;
            }
            while(matched == pattern.length())
            {
                if(min_length > window_end - window_start + 1)
                {
                    min_length = window_end - window_start + 1;
                    substr_start = window_start;
                }
                char left_char = str.charAt(window_start++);
                if(char_freq.containsKey(left_char))
                {
                    if(char_freq.get(left_char) == 0)
                        matched--;
                    char_freq.put(left_char, char_freq.get(left_char) + 1);
                }
            }
        }
        return min_length > str.length() ? "" : str.substring(substr_start, substr_start + min_length);
    }
    public static void main(String[] args)
    {
        System.out.println(MinWindowSubstring.find_substring("aabdec", "abc"));
        System.out.println(MinWindowSubstring.find_substring("abdabca", "abc"));
        System.out.println(MinWindowSubstring.find_substring("adcad", "abc"));
    }
}
