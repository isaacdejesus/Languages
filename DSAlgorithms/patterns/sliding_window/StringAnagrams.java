import java.util.*;
class StringAnagrams 
{
    public static List<Integer> find_string_anagrams(String str, String pattern)
    {
        int window_start = 0;
        int matched = 0;
        Map<Character, Integer> char_freq = new HashMap<>();
        for(char chr : pattern.toCharArray())
            char_freq.put(chr, char_freq.getOrDefault(chr, 0) + 1);
        List<Integer> result_indices = new ArrayList<Integer>();
        for(int window_end = 0; window_end < str.length(); window_end++)
        {
            char right_char = str.charAt(window_end);
            if(char_freq.containsKey(right_char))
            {
                char_freq.put(right_char, char_freq.get(right_char) - 1);
                if(char_freq.get(right_char) == 0)
                    matched++;
            }
            if(matched == char_freq.size())
                result_indices.add(window_start);
            if(window_end >= pattern.length() - 1)
            {
                char left_char = str.charAt(window_start++);
                if(char_freq.containsKey(left_char))
                {
                    if(char_freq.get(left_char) == 0)
                        matched--;
                    char_freq.put(left_char, char_freq.get(left_char) + 1);
                }
            }
        }
        return result_indices;
    }
    public static void main(String[] args)
    {
        System.out.println(StringAnagrams.find_string_anagrams("ppqp", "pq"));
        System.out.println(StringAnagrams.find_string_anagrams("abbcabc", "abc"));
    }
}
