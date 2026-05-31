#include <unordered_map>


class Node{
    public:
        std::unordered_map<char, Node*> hashMap;
        char c{};
        bool isCompleteWord{false};
        

        Node() = default;
        Node(char c, bool isCompleteWord): c(c), isCompleteWord(isCompleteWord){};
        
};



class PrefixTree {
public:

    Node *root;

    PrefixTree(): root(new Node()) {};
    
    void insert(string word) {
        Node *curr = root;
        for (size_t i{0}; i < word.size(); ++i){
            char ch = word[i];
            if(!curr->hashMap.count(ch)){
    
                
                curr->hashMap[ch] = new Node(ch, false);
            
            } 

            curr = curr->hashMap[ch];
        }
        curr->isCompleteWord = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for (char ch : word) {
            if (!curr->hashMap.count(ch)) return false;
            curr = curr->hashMap[ch];
        }
        return curr->isCompleteWord;
        
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for (char ch : prefix) {
            if (!curr->hashMap.count(ch)) return false;
            curr = curr->hashMap[ch];
        }
        return true;
    }
};


