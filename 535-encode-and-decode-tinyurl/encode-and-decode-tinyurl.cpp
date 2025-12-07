class Solution {
public:
    char c;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        c=longUrl.back();
        longUrl.pop_back();
        return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.push_back(c);
        return shortUrl;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));