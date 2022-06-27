#include <iostream>
#include <unordered_map>

auto getLongestSubstringNDistinctChars(std::string str, int n)
{
    auto substr_begin = 0; 
    auto substr_end = 0;

    std::unordered_map<char, unsigned int> win_chars;

    auto win_low = 0;
    auto win_high = 0;

    for (; win_high < str.length(); win_high++)
    {
        auto cur_char = str[win_high];
        if (win_chars.find(cur_char) == win_chars.end())
            win_chars[cur_char] = 1;
        else
            win_chars[cur_char]++;

        //Sliding window contains too many non-distinct chars? Update! 
        while (win_chars.size() > n)
        {
            auto win_low_char = str[win_low];
            if (--win_chars[win_low_char] == 0)
                win_chars.erase(win_low_char);
            win_low++;
        }

        //Update longest substring indexes if needed
        if (win_high - win_low > substr_end - substr_begin)
        {
            substr_begin = win_low;
            substr_end = win_high;
        }
    }

    return str.substr(substr_begin, substr_end - substr_begin + 1);
}

int main()
{

    std::string str = "abcbdbadbbbb";

    std::cout << "Longest substring: " << getLongestSubstringNDistinctChars(str, 3);

}