#include <iostream>
#include <vector>

/**
 * Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

Example 1:

Input: strs = [ "flower", flo
                "flow",
                "flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 
Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
*/

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string word = strs[0];
        std::string common_prefix = "";
        bool flag = true;

        for (size_t i = 1; i < strs.size(); i++)
        {
            std::string word_2 = strs[i];

            for (size_t j = 0; j < word_2.length(); j++)
            {
                if ((word[j] == word_2[j]) && i < 2)
                    common_prefix.push_back(word[j]);    
                else{
                    common_prefix.pop_back();
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        return common_prefix;
    }
};


int main()
{
    std::vector<std::string> vec = {"flower","flow","flight"};
    std::vector<std::string> vec2 = {"d","racecar","car"};

    Solution s = Solution();
    std::cout << s.longestCommonPrefix(vec2);
    return 0;
}
