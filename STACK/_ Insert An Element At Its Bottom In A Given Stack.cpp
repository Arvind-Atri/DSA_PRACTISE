#include <bits/stdc++.h>

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        // if stack is empty ,then insert the element
        myStack.push(x);
        return;
    }
    // pop the elements
    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    // re push the element
    myStack.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}
