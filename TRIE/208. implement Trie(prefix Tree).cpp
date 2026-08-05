

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }

};


class Trie {
    TrieNode*root;
public:
    Trie() {
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode*root,string word)
    {
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }

        int index=word[0]-'a';
        TrieNode*child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        return insertUtil(child,word.substr(1));
    }
    void insert(string word) {
        insertUtil(root,word);
    }
    
      bool searchWord(TrieNode*root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        // recursive call
        return searchWord(child,word.substr(1));
    }

    bool search(string word) {
        return searchWord(root,word);
    }
    
    bool searchPrefix(TrieNode*root,string word){
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        // recursive call
        return searchPrefix(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return searchPrefix(root,prefix);
    }
};







// Modification









struct TrieNode{
    TrieNode* child[26];
    bool isEnd;
};

TrieNode* getNode(){
    TrieNode* newnode = new TrieNode();
    newnode->isEnd = false;
    for(int i=0;i<26;i++){
        newnode->child[i] = nullptr;
    }
    return newnode;
}
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        TrieNode* crawler = root;
        for(auto ch:word){
            int idx = ch-'a';
            if(crawler->child[idx] == nullptr){
                TrieNode* newnode = getNode();
                crawler->child[idx] = newnode;
            }
            crawler = crawler->child[idx];
        }

        crawler->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* crawler = root;
        for(auto ch:word){
            int idx = ch-'a';
            if(crawler->child[idx] == nullptr){
                return false;
            }
            crawler = crawler->child[idx];
        }

        if(crawler && crawler->isEnd == true) return true;

        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* crawler = root;
        for(auto ch:prefix){
            int idx = ch-'a';
            if(crawler->child[idx] == nullptr){
                return false;
            }
            crawler = crawler->child[idx];
        }
        return true;
    }
};

