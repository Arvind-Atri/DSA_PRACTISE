

// T.C=O(M*N)
// S.C =O(1) if ans not considered

string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    for (int i = 0; i < arr[0].length(); i++)
    {
        char ch = arr[0][i];

        bool match = true;

        for (int j = 1; j < n; j++)
        {
            // not match

            if (arr[j].size() < i || ch != arr[j][i])
            {
                match = false;
                break;
            }
        }

        if (!match)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

// Approach 2 using Trie
// T.C=O(M*N)
// S.C =O(M*N) if ans not considered
class TrieNode
{
public:
    char data;
    bool isTerminal;
    int childCount;
    TrieNode *children[26];

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie(char ch)
    {
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    void lcp(string str, string &ans)
    {
        TrieNode *curr = root;
        for (int i = 0; i < str.length(); i++)
        {
            char ch = str[i];

            if (curr->childCount == 1)
            {
                ans.push_back(ch);
                int index = ch - 'a';
                curr = curr->children[index];
            }
            else
            {
                break;
            }

            if (curr->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');

    // insert all strings into trie;

    for (int i = 0; i < n; i++)
    {
        t->insertWord(arr[i]);
    }
    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);

    return ans;
}
