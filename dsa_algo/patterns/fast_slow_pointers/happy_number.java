class happy_number {
    public static boolean find(int num)
    {
        int slow = num;
        int fast = num;
        do{
            slow = find_sq_sum(slow);
            fast = find_sq_sum(find_sq_sum(fast));
        }
        while(slow != fast);
        return slow == 1;
    }
    private static int find_sq_sum(int num)
    {
        int sum = 0;
        int digit;
        while(num > 0)
        {
            digit = num % 10;
            sum += digit * digit;
            num /= 10;
        }
        return sum;
    }
    public static void main(String[] args)
    {
        System.out.println(happy_number.find(23));
        System.out.println(happy_number.find(12));
    }
}
