/**
 * Encodes a URL to a shortened URL.
 */
 const encode_hash = new Map<string, string>();
 const decode_hash = new Map<string, string>();
 const base_string: string =  "http://tinyurl.com/";
function encode(longUrl: string): string {
    if(!encode_hash.has(longUrl))
    {
        const path: number = encode_hash.size + 1;
        const short_url = base_string + path.toString();
        encode_hash.set(longUrl, short_url);
        decode_hash.set(short_url, longUrl);
    }
    return encode_hash.get(longUrl);
};

/**
 * Decodes a shortened URL to its original URL.
 */
function decode(shortUrl: string): string {
    return decode_hash.get(shortUrl);
};

/**
 * Your functions will be called as such:
 * decode(encode(strs));
 */
