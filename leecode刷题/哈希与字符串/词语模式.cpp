#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<unordered_map>
using namespace std;
bool wordPattern(string pattern, string s) {
    unordered_map<string,char> hash_map;
    char used[128]={0};
    vector<string> words;
    istringstream input(s);
    string temp;
    while(input>>temp){
        words.push_back(temp);
    }
    if(words.size()!=pattern.size())
    {
        return false;
    }
    for(int i=0;i<pattern.size();i++){
        if(hash_map.find(words[i])==hash_map.end()){
            if(used[pattern[i]]==1)
                return false;
            hash_map[words[i]]=pattern[i];
        }else{
            if(hash_map[words[i]]!=pattern[i])
            {
                return false;
            }
        }
        used[pattern[i]]=1;
    }
    return true;
}
int main(){
    string pattern="abba";
    string s="dog cat cat dog";
    cout<<wordPattern(pattern,s)<<endl;
    return 0;
}