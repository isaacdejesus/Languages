//given arr of nums, return count of numbers with even digits
class evenDigits {
    //extract digits from each number to determine if even
    public static boolean has_even_digits_2(int num)
    {
        int digit_count = 0;
        while(num != 0)
        {
            digit_count++;
            num/=10;
        }
        return (digit_count & 1) == 0;
    }
    //extract digits from each number to determine if even
    public static boolean has_even_digits_1(int num)
    {
        int digit_count = 0;
        while(num != 0)
        {
            digit_count++;
            num = num / 10;
        }
            if(digit_count % 2 == 0)
                return true;
            else return false;
    }
    public static int f1(int[] nums)
    {
        int even_digit_count = 0;
        for(int num: nums) 
        {
            if(has_even_digits_1(num))
                even_digit_count++;
        }
        return even_digit_count;
    }
    //convert numbers to string and calc length to determine if even
    public static int f2(int[] nums)
    {
        int even_digit_count = 0;
        for(int num: nums)
        {
            int length = String.valueOf(num).length();
            if(length % 2 == 0)
                even_digit_count++;
        }
        return even_digit_count;
    }
    //use log10 to compute length of number then determine if even
    public static int f3(int[] nums)
    {
        int even_digit_count = 0;
        for(int num: nums)
        {
            int digit_count = (int) Math.floor(Math.log10(num)) + 1;
            if(digit_count % 2 == 0)
                even_digit_count++;
        }
        return even_digit_count;
    }
    public static void main(String[] args)
    {
        int[] arr1 = {12, 345, 2, 6, 7896};
        int[] arr2 = {555, 901, 482, 1771};
        System.out.println(evenDigits.f1(arr1));
        System.out.println(evenDigits.f1(arr2));
        System.out.println(evenDigits.f2(arr1));
        System.out.println(evenDigits.f2(arr2));
        System.out.println(evenDigits.f3(arr1));
        System.out.println(evenDigits.f3(arr2));
    }
}
