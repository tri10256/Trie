
struct Node{
    Node *links[26];
    int countEndwith = 0;
    int countStartwith = 0;
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    void countStart(){
        countStartwith++;
    }
    void countEnd(){
        countEndwith++;
    }
    int getEndwith(){
        return countEndwith;
    }
    int getStartwith(){
        return countStartwith;
    }
    void decStartwith(){
        countStartwith--;
    }
    void decEndwith(){
        countEndwith--;
    }
};

class Trie{
     
    Node *root;
    public:

    Trie(){
        root  = new Node();
    }

    void insert(string &word){
        Node *node = root;
        for(int  i = 0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)){
                node ->put(ch,new Node()); 
            }
            node ->countStart();
            node = node->get(ch);
        }
        node ->countStart();
        node->countEnd();
    }

    int countWordsEqualTo(string &word){
        Node *node = root;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getEndwith();
    }

    int countWordsStartingWith(string &word){
       Node *node = root;
        for(int i = 0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)){
                return 0;
            }
            node = node->get(ch);
        }
        return node->getStartwith();
    }

    void erase(string &word){
        Node *node = root;
        for(int i =0;i<word.size();i++){
            char ch = word[i];
            if(!node->contains(ch)){
                return;
            }
            node->decStartwith();
            node = node->get(ch);
        }
        node->decStartwith();
        node -> decEndwith();
    }
};
