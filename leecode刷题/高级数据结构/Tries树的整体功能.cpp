#include<iostream>
#include<vector>
#define TRIE_MAX_CHAR_NUM 26
using namespace std;

struct TrieNode{
    TrieNode *child[TRIE_MAX_CHAR_NUM];
    bool is_end;
    TrieNode():is_end(false){
        for(int i=0;i<TRIE_MAX_CHAR_NUM;i++){
            child[i]=0;
        }

    }
};
class TrieTree{
public:
    TrieTree(){
    }
    ~TrieTree(){
        for(int i=0;i<_node_vec.size();i++){
            delete _node_vec[i];
        }
    }
    
    void insert(const char *word){
        TrieNode *ptr = &_root;
        while(*word){
            int pos=*word-'a';
            if(!ptr->child[pos]){
                ptr->child[pos]=new_node();
            }
            ptr = ptr->child[pos];
            word++;
        }
        ptr->is_end=true;
    }
    bool search(const char *word){
        TrieNode *ptr = &_root;
        while(*word){
            int pos=*word-'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr=ptr->child[pos];
            word++;
        }
        return ptr->is_end;
    }
    bool startWith(const char *prefix){
        TrieNode *ptr=&_root;
        while(*prefix){
            int pos=*prefix-'a';
            if(!ptr->child[pos]){
                return false;
            }
            ptr=ptr->child[pos];
            prefix++;
        }
        return true;
    }
    TrieNode *root(){
        return &_root;
    }

private:
    TrieNode *new_node(){
        TrieNode *node=new TrieNode();
        _node_vec.push_back(node);
        return node;
    }
    vector<TrieNode*> _node_vec;
    TrieNode _root;
};