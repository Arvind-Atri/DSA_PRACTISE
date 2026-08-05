// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    queue<int> rev(queue<int> q)
    {
        stack<int> s;

        while (!q.empty())
        {
            int val = q.front();
            q.pop();
            s.push(val);
        }

        while (!s.empty())
        {
            int val = s.top();
            s.pop();
            q.push(val);
        }
        return q;
    }
};

// function Template for C++

// Function to reverse the queue.
class Solution
{
private:
    void solve(queue<int> &q)
    {
        if (q.empty())
        {
            return;
        }
        int element = q.front();
        q.pop();
        solve(q);
        q.push(element);
    }

public:
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }
};