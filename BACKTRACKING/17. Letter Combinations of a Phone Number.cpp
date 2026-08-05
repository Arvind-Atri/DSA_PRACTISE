class Solution
{
private:
    void solve(string digits, int index, vector<string> &ans, string output, string mapping[])
    {
        if (index >= digits.length())
        {
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string value = mapping[digit];

        for (int i = 0; i < value.length(); i++)
        {
            output.push_back(value[i]);
            solve(digits, index + 1, ans, output, mapping);
            output.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        int index = 0;
        vector<string> ans;
        if (digits.length() == 0)
        {
            return ans;
        }
        string output;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, index, ans, output, mapping);
        return ans;
    }
};