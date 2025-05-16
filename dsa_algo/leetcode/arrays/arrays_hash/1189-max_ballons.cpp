int maxNumberOfBalloons(string text) {
    std::unordered_map<char, int> input_hash;
    std::unordered_map<char, int> donor_hash;
    std::string input_string = "balloon";
    for(int i = 0; i < input_string.size(); i++)
        input_hash[input_string[i]]++;
    for(int i = 0; i < text.size(); i++)
        donor_hash[text[i]]++;
    int result = text.size();
    for(auto [key, value]: input_hash)
        result = std::min(result, donor_hash[key] / value);

    return result;
    }