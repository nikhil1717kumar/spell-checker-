#include<bits/stdc++.h>
using namespace std; 
#define underlineOn "\033[4m"
#define underlineOff "\033[0m"
struct Trienode{
    bool iscount=false;
    Trienode* children[26]={NULL};
};
class Trie{
    Trienode* root;
    public:
    Trie(){
    root=new Trienode();
    }
    void insertWord(string word){
        Trienode* currNode=root;
        for(char c:word){
            if(currNode->children[c-'a']==NULL){
                currNode->children[c-'a']=new Trienode();
            }
            currNode=currNode->children[c-'a'];
        }
        currNode->iscount=true;
    }
    bool searchWord(string word){
        Trienode* currNode=root;
        for(char c:word){
            if(currNode->children[c-'a']!=NULL){
                currNode=currNode->children[c-'a'];
            }else{
                return false;
            }
        }
        return currNode->iscount;
    }
    bool deleteWord(string word){
        Trienode* currNode=root;
        for(char c:word){
            if(currNode->children[c-'a']!=NULL){
            currNode=currNode->children[c-'a'];
            }
            else{
            return false;
            }
            currNode->iscount=false;
            return true;
        }
    }
    bool updateWord(string oldWord,string newWord){
        bool ret=deleteWord(oldWord);
        if(ret){
            this->insertWord(newWord);
        }
        return ret;
    }
 
};

int main(){
   
    Trie oTrie;

    vector<string> words = { "cat", "car", "cart", "ball", "bat", "bats"};
    for(string word: words)
        oTrie.insertWord(word);


    string s = "";
    while(true){
        char c = getchar(); 
        if(c == '\n'){ // break on enter
            oTrie.searchWord(s) ? cout << s : cout << underlineOn << s << underlineOff;
            cout << c;
            break;
        }
        if(c == ' '){ 
            oTrie.searchWord(s) ? cout << s : cout << underlineOn << s << underlineOff;
            s = "";
            cout << c;
        }
        else{
            s = s + char(c);
        }
    }    

    cout << endl << endl;
    return 0;
}