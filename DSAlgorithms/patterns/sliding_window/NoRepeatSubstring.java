import java.util.*;
class NoRepeatSubstring {
    public static int find_length(String str)
    {
        int window_start = 0;
        int max_length = 0;
        Map<Character, Integer> char_index_map = new HashMap<>();
        for(int window_end = 0; window_end < str.length(); window_end++)
        {
            char right_char = str.charAt(window_end);
            if(char_index_map.containsKey(right_char))
                window_start = Math.max(window_start, char_index_map.get(right_char) + 1);
            char_index_map.put(right_char, window_end);
            max_length = Math.max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
    public static void main(String[] args)
    {
        System.out.println("Length of longest substring: " + NoRepeatSubstring.find_length("aabccbb"));
        System.out.println("Length of longest substring: " + NoRepeatSubstring.find_length("abbbb"));
        System.out.println("Length of longest substring: " + NoRepeatSubstring.find_length("abccde"));
    }
}

