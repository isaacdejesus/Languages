class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> current_line;
        int current_line_length = 0;
        for(const std::string& word: words)
        {
            if(current_line_length + current_line.size() + word.size() <= maxWidth)
            {
                current_line.push_back(word);
                current_line_length += word.size();
            }
            else
            {
                result.push_back(current_line);
                current_line.clear();
                current_line.push_back(word);
                current_line_length = word.size();
            }
        }
        result.push_back(current_line);
        std::vector<std::string> justified_lines;
        for(int i = 0; i < result.size() - 1; i++)
        {
            current_line = result[i];
            int num_words = current_line.size();
            int num_spaces = maxWidth;
            for(const std::string& word: current_line)
                num_spaces -= word.size();
            int space_gaps = std::max(num_words - 1, 1);
            int spaces_per_gap = num_spaces / space_gaps;
            int extra_spaces = num_spaces % space_gaps;
            std::string justified_line = "";
            for(const std::string& word : current_line)
            {
                justified_line += word;
                if(space_gaps > 0)
                {
                    int spaces_to_add = spaces_per_gap + (extra_spaces > 0 ? 1 : 0);
                    justified_line += std::string(spaces_to_add, ' ');
                    extra_spaces -= 1;
                    space_gaps -= 1;
                }
            }
            justified_lines.push_back(justified_line);
        }
        std::string last_line = "";
        for(const std::string& word: result[result.size() - 1])
            last_line += word + " ";
        last_line.pop_back();
        last_line += std::string(maxWidth - last_line.size(), ' ');
        justified_lines.push_back(last_line);
        return justified_lines;
    }
};