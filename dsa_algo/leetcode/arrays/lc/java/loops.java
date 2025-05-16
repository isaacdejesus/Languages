class loops {
    public static void main(String[] args)
    {
        int[] sq_numbers = new int[10];
        for(int i = 0; i < 10; i++)
        {
            int sq = (i + 1) * (i + 1);
            sq_numbers[i] = sq;
        }
        for(int i = 0; i < 10; i++)
            System.out.println(sq_numbers[i]);
        for(int sq: sq_numbers)
            System.out.println(sq);

    }
}
