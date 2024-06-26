class BackspaceCompare {
    public static boolean compare(String str_1, String str_2)
    {
        int index_1 = str_1.length() - 1, index_2 = str_2.length() - 1;
        while(index_1 >= 0 || index_2 >= 0)
        {
            int i_1 = get_next_valid_char_index(str_1, index_1);
            int i_2 = get_next_valid_char_index(str_2, index_2);
            if(i_1 < 0 && i_2 < 0)
                return true;
            if(i_1 < 0 || i_2 < 0)
                return false;
            if(str_1.charAt(i_1) != str_2.charAt(i_2))
                return false;
            index_1 = i_1 - 1;
            index_2 = i_2 - 1;

        }
        return true;
    }
    private static int get_next_valid_char_index(String str, int index)
    {
        int backspace_count = 0;
        while(index >= 0)
        {
            if(str.charAt(index) == '#')
                backspace_count++;
            else if(backspace_count > 0)
                backspace_count--;
            else 
                break;
            index --;
        }
        return index;
    }
    public static void main(String[] args)
    {
        System.out.println(BackspaceCompare.compare("xy#z", "xzz#"));
        System.out.println(BackspaceCompare.compare("xy#z", "xyz#"));
        System.out.println(BackspaceCompare.compare("xp#", "xyz##"));
        System.out.println(BackspaceCompare.compare("xywrrmp", "xywrrmu#p"));
    }
}
