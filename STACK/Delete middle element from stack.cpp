#include <bits/stdc++.h>

void solve(stack<int> &inputStack, int count, int size)
{
    // base Condition
    if (count == size / 2)
    {
        inputStack.pop();
        return;
    }
    // element is fetched for future insertion
    int num = inputStack.top();
    inputStack.pop();
    // Recursive Call
    solve(inputStack, count + 1, size);
    // element is pushed back into stack
    inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, count, N);
}