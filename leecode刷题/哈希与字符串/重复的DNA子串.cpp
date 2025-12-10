#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<string,int> word_map;
    int end=s.length()-10;
    for(int i=0;i<end;i++){
        string word=s.substr(i,10);
        if(word_map.find(word)==word_map.end()){
            word_map.insert({word,0});
        }
        word_map[word]++;
    }
    vector<string> result;
    for(auto m:word_map){
        if(m.second>=2)
            result.push_back(m.first);
    }
    return result;
}
int main(){
    
    return 0;
}