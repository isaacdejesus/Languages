import java.util.*;
class WordConcat {
    public static List<Integer> find_word_concat(String str, String[] words)
    {
        Map<String, Integer> word_freq = new HashMap<>();
        for(String word : words)
            word_freq.put(word, word_freq.getOrDefault(word, 0) + 1);
        List<Integer> result_indices = new ArrayList<Integer>();
        int words_count = words.length;
        int word_length = words[0].length();
        for(int i = 0; i <= str.length() - words_count * word_length; i++)
        {
            Map<String, Integer> words_seen = new HashMap<>();
            for(int j = 0; j < words_count; j++)
            {
                int next_word_index = i + j * word_length;
                String word = str.substring(next_word_index, next_word_index + word_length);
                if(!word_freq.containsKey(word))
                    break;
                words_seen.put(word, words_seen.getOrDefault(word, 0) + 1);
                if(words_seen.get(word) > word_freq.getOrDefault(word, 0))
                    break;
                if(j + 1 == words_count)
                    result_indices.add(i);
            }
        }
        return result_indices;
    }
    public static void main(String[] args)
    {
        List<Integer> result = WordConcat.find_word_concat("catfoxcat", new String[]{"cat", "fox"});
        System.out.println(result);
        result = WordConcat.find_word_concat("catcatfoxfox", new String[]{"cat", "fox"});
        System.out.println(result);
    }
}
