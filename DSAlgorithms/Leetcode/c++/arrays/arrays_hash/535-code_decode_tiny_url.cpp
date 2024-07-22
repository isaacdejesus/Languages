class Solution {
private:
    std::unordered_map<std::string, std::string> encode_map;
    std::unordered_map<std::string, std::string> decode_map;
    std::string base = "http://tinyurl.com/";
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(!encode_map.count(longUrl))
        {
            std::string shortUrl = base + std::to_string(encode_map.size() + 1);
            encode_map[longUrl] = shortUrl;
            decode_map[shortUrl] = longUrl;
        }
        return encode_map[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       return decode_map[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));