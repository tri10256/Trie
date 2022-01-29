
struct Node{
    Node* links[26];
    
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch, Node *node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
};


int countDistinctSubstrings(string &s)
{
     Node *root = new Node();
     int count = 0;
    
     for(int i = 0;i<s.size();i++){
         Node *node = root;
         for(int j = i;j<s.size();j++){
             if(!node->contains(s[j])){
                 count++;
                 node->put(s[j],new Node());
             }
             node = node->get(s[j]);
         }
     }
    return count+1; 
}
