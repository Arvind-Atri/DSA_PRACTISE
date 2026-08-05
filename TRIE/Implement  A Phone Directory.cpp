class TrieNode
{

public:
    char data;

    TrieNode *children[26];

    bool isTerminal;

    TrieNode(char ch)
    {

        ch = data;

        for (int i = 0; i < 26; i++)
        {

            children[i] = NULL;
        }

        isTerminal = false;
    }
};

class Trie
{

public:
    TrieNode *root;

    Trie()
    {

        root = new TrieNode('\0');
    }

    void insertUtile(TrieNode *root, string word)
    {

        // base case

        if (word.length() == 0)
        {

            root->isTerminal = true;

            return;
        }

        // assumtion ,that  word will be in lowe case

        int index = word[0] - 'a';

        // creating a node

        TrieNode *child;

        // prsent

        if (root->children[index] != NULL)
        {

            child = root->children[index];
        }

        else
        {

            // absent

            child = new TrieNode(word[0]);

            root->children[index] = child;
        }

        // recursive call

        insertUtile(child, word.substr(1));
    }

    void insertWordSring(string word)
    {

        insertUtile(root, word);
    }
    void printsuggestion(TrieNode *curr, vector<string> &temp, string prefix)
    {
        if (curr->isTerminal)
        {
            temp.push_back(prefix);
            // return;

            /* return would terminate the function after first Terminal
             is found, but we want all of them, we as we see in
              cod - code - coding - codding wala example, there
               can be multiple isTerminal = true in a single
                stream / thread, so we want recursion to go all 
                the way to end and not return from the first Terminal
                 Trie that it encounters,
                */
        }
        for (char ch = 'a'; ch <= 'z'; ch++)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next != NULL)
            {
                prefix.push_back(ch);
                printsuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getsuggestion(string str)
    {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        for (int i = 0; i < str.length(); i++)
        {
            char lastch = str[i];

            prefix.push_back(lastch);

            TrieNode *curr = prev->children[lastch - 'a'];
            if (curr == NULL)
            {
                break;
            }
            vector<string> temp;
            printsuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie *t = new Trie();
    for (int i = 0; i < contactList.size(); i++)
    {
        string str = contactList[i];
        t->insertWordSring(str);
    }
    return t->getsuggestion(queryStr);
}
