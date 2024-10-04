class Trie {
private:
    struct Node {
        Node* links[26];
        bool end = false;
        void put(char c, Node* node){
            links[c-'a'] = node;
        }
        Node* get(char c){
            return links[c-'a'];
        }
        bool contains(char c){
            return links[c-'a'] != nullptr;
        }
    };
    Node* root;
    
public:
    Trie(){
        root = new Node();
    }

    void insert(string &s){
        Node* cur = root;
        for(int i=0; i<s.size(); i++){
            if(!cur->contains(s[i])){
                cur->put(s[i], new Node());
            }
            cur = cur->get(s[i]);
        }
        cur->end = true;
    }

    bool search(string &s){
        Node* cur = root;
        for(int i=0; i<s.size(); i++){
            if(!cur->contains(s[i])){
                return false;
            }
            cur = cur->get(s[i]);
        }
        return cur->end;
    }
};
