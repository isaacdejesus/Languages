import java.util.*;
class FruitsIntoBaskets {
    public static int find_length(char[] arr)
    {
        int window_start = 0;
        int max_length = 0;
        Map<Character, Integer> fruit_freq = new HashMap<>();
        for(int window_end = 0; window_end < arr.length; window_end++)
        {
            fruit_freq.put(arr[window_end], fruit_freq.getOrDefault(arr[window_end], 0) + 1);
            while(fruit_freq.size() > 2)
            {
                fruit_freq.put(arr[window_start], fruit_freq.get(arr[window_start]) - 1);
                if(fruit_freq.get(arr[window_start]) == 0)
                    fruit_freq.remove(arr[window_start]);
                window_start++;
            }
            max_length = Math.max(max_length, window_end - window_start + 1);
        }
        return max_length;
    }
    public static void main(String[] args)
    {
        System.out.println("Max number of fruits: " + 
                FruitsIntoBaskets.find_length(new char[] {'A', 'B', 'C', 'A', 'C'}));
        System.out.println("Max number of fruits: " + 
                FruitsIntoBaskets.find_length(new char[] {'A', 'B', 'C', 'B', 'B', 'C'}));
    }
}
