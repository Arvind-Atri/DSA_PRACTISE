class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        int m = s.size();
        int n = spaces.size();

        int first = 0;
        int second = 0;
        string ans;
        while (first < m)
        {
            while (second < n and spaces[second] == first)
            {
                ans.push_back(' ');
                second++;
            }
            ans.push_back(s[first]);
            first++;
        }
        return ans;
    }
};