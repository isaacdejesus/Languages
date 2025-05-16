#include<bits/stdc++.h>
class backspace_compare {
    public:
        static bool compare(const std::string &str_1, const std::string &str_2)
        {
            int index_1 = str_1.length() - 1;
            int index_2 = str_2.length() - 1;
            while(index_1 >= 0 || index_2 >= 0)
            {
                int i_1 = get_next_valid_char_index(str_1, index_1);
                int i_2 = get_next_valid_char_index(str_2, index_2);
                if(i_1 < 0 && i_2 < 0)
                    return true;
                if(i_1 < 0 || i_2 < 0)
                    return false;
                if(str_1[i_1] != str_2[i_2])
                    return false;
               index_1 = i_1 - 1; 
               index_2 = i_2 - 1; 
            }
            return true;
        }
    private:
        static int get_next_valid_char_index(const std::string &str, int index)
        {
            int backspace_count = 0;
            while(index >= 0)
            {
                if(str[index] == '#')
                    backspace_count++;
                else if(backspace_count > 0)
                    backspace_count--;
                else
                    break;
                index--;
            }
            return index;
        }
};

int main(int argc, char *argv[])
{
    std::cout<<backspace_compare::compare("xy#z", "xzz#");
    std::cout<<backspace_compare::compare("xy#z", "xyz#");
    std::cout<<backspace_compare::compare("xp#", "xyz##");
    std::cout<<backspace_compare::compare("xywrrmp", "xywrrmu#p");

}
