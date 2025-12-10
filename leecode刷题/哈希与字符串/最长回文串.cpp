#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int longestPalindrome(string s) {
    unordered_map<char,int> hash_map;
    for(auto c:s){
        if(hash_map.find(c)==hash_map.end()){
            hash_map.insert({c,0});
        }
        hash_map[c]++;
    }
    int len=0;
    for(auto item:hash_map){
        if(item.second%2==0){
            len+=item.second;
        }else{
            len+=item.second-1;
        }
    }
    return len+1;
}
int main(){
    string s="abccccddaa";
    cout<<longestPalindrome(s)<<endl;
    return 0;
}