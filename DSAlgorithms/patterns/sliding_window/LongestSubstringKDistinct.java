import java.util.*;
class LongestSubstringKDistinct {
    public static int find_length(String str, int k)
    {
        if(str == null || str.length() == 0 || str.length() < k)
            throw new IllegalArgumentException();
        int window_start = 0;
        int max_length = 0;
        Map<Character, Integer> char_freq_map = new HashMap<>();
        for(int window_end = 0; window_end < str.length(); window_end++)
        {
            char right_char = str.charAt(window_end);
            char_freq_map.put(right_char, char_freq_map.getOrDefault(right_char, 0) + 1);
            while(char_freq_map.size() > k)
            {
                char left_char = str.charAt(window_start);
                char_freq_map.put(left_char, char_freq_map.get(left_char) - 1);
                if(char_freq_map.get(left_char) == 0)
                    char_freq_map.remove(left_char);
                window_start++;
            }
            max_length = Math.max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
    public static void main(String[] args)
    {
        System.out.println("Length of longest substring: " + LongestSubstringKDistinct.find_length("araaci", 2));
        System.out.println("Length of longest substring: " + LongestSubstringKDistinct.find_length("araaci", 1));
        System.out.println("Length of longest substring: " + LongestSubstringKDistinct.find_length("cbbebi", 3));
    }
}
