// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s;

        for (int i = 0; i < n; i++)
        {
            s.push(i);
        }

        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (M[a][b] == 1)
            {
                s.push(b);
            }
            else
            {
                s.push(a);
            }
        }

        // Potential candidate is found
        int candidate = s.top();

        // int rowCheck=false;
        // int zeroCount=0;

        for (int i = 0; i < n; i++)
        {
            if (M[candidate][i] != 0)
            {
                return -1;
            }
        }
        // if(zeroCount!=n){
        //     return -1;
        // }

        // int colCheck=false;
        for (int i = 0; i < n; i++)
        {
            if (i == candidate)
            {
                continue;
            }

            if (M[i][candidate] != 1)
            {
                return -1;
            }
        }

        return candidate;
    }
};