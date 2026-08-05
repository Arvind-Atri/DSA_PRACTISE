class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    char val;
    bool isWord = false;
    int check;

    TrieNode() {}

    TrieNode(char v) { this->val = v; }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word, int idx)
    {
        TrieNode *temp = root;

        for (char ch : word)
        {
            if (temp->children.find(ch) == temp->children.end())
            {
                temp->children[ch] = new TrieNode(ch);
            }

            temp = temp->children[ch];
        }
        if (!temp->isWord)
        {
            temp->isWord = true;
            temp->check = idx;
        }
    }

    int isPrefix(string pre)
    {
        TrieNode *temp = root;

        for (auto ch : pre)
        {
            if (temp->children.find(ch) == temp->children.end())
            {
                return -1;
            }

            temp = temp->children[ch];
        }

        queue<TrieNode *> depth;
        depth.push(temp);

        int max = INT_MAX;

        while (!depth.empty())
        {
            TrieNode *curr = depth.front();
            depth.pop();

            for (auto ch : curr->children)
            {
                depth.push(ch.second);

                if (ch.second->isWord && ch.second->check < max)
                {
                    max = ch.second->check;
                }
            }
        }

        return max;
    }
};

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        Trie *search = new Trie();

        istringstream ss(sentence);
        string word("");
        int count = 1;

        while (ss >> word)
        {
            if (word == searchWord)
                return count;

            search->insert(word, count);
            count++;
        }

        return search->isPrefix(searchWord);
    }
};