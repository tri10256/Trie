
//////n ni nin ninj ninja ninga
//////output = ninja


#include<bits/stdc++.h>
using namespace std;


struct Node{
  Node *links[26];
  bool flag = false;  
  
    bool contains(char ch){
        return links[ch-'a'] != NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setNode(){
        flag = true;
    }
    bool isSet(){
        return flag;
    }
};

class Trie {
    
    public:
    Node *root;
    Trie(){
        root = new Node();
    }
    
    void insert(string &s){
          Node *node = root;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(!node->contains(ch)){
              node->put(ch,new Node());
            }
            node = node->get(ch);   
        }
       node->setNode();
    }
    
    bool check(string &s){
        Node *node = root;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(!node->contains(ch)){
				
                return false;
            }
            node = node->get(ch);
            if(!node->isSet())
                return false;
        }

		return true;   
    }
    
    
};


string completeString(int n, vector<string> &a){
     Trie trie;
     
    for(int i = 0;i<n;i++){
        trie.insert(a[i]);
    }
    string ans = "";
    for(int i = 0;i<n;i++){
        string temp = a[i];
		
        if(trie.check(temp)){
            if(temp.size()>ans.size()){
                ans = temp;
            }else if(temp.size() == ans.size()){
               ans = temp<ans?temp:ans;
            }
       }
    }
    
    if(ans.size()==0)
	return "None";

    return ans;
}
