public class duplicateZeros {
    public static void duplicate_zeros(int[] arr){
        int possible_duplicates = 0;
        int length_ = arr.length - 1;
        for(int l = 0; l <= length_ - possible_duplicates; l++)
        {
            if(arr[l] == 0)
            {
                if(l == length_ - possible_duplicates)
                {
                    arr[length_] = 0;
                    length_ -= 1;
                    break;
                }
                possible_duplicates++;
            }
        }
        int last = length_ - possible_duplicates;
        for(int i = last; i >= 0; i--)
        {
            if(arr[i] == 0)
            {
                arr[i + possible_duplicates] = 0;
                possible_duplicates--;
                arr[i + possible_duplicates] = 0;
            }
            else
            {
                arr[i + possible_duplicates] = arr[i];
            }
        }
    }
}