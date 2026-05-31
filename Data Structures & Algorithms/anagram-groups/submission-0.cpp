class Solution {
public:

std::string getFreqSignature(const std::string &str)
    {

        std::string s(26, '0');

        for (const char &c : str)
        {
            int idx = c - 'a';

            int freq = s[idx] - '0';

            freq++;

            s[idx] = freq + '0';
        }

        return s;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const std::string &s : strs)
        {
            std::string signatureStr = getFreqSignature(s);

            if (map.count(signatureStr))
            {
                map[signatureStr].push_back(s);
            }
            else
            {
                map[signatureStr] = std::vector<std::string>{s};
            }
        }

        std::vector<std::vector<std::string>> result;

        for (const auto &[key, value] : map)
        {
            result.push_back(value);
        }

        return result;
    }
};
