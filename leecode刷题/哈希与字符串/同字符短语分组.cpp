#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> result;
    unordered_map<string,vector<string>> hash_map;
    for(auto str:strs){
        string s=str;
        sort(s.begin(),s.end());
        if(hash_map.find(s)==hash_map.end()){
            hash_map.insert({s,vector<string>()});
        }
        hash_map[s].push_back(str);
    }
    for(auto vec:hash_map){
        result.push_back(vec.second);
    }
    return result;
}
int main(){
    vector<string> s={"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result;
    result=groupAnagrams(s);
    for(auto strs:result){
        for(auto s:strs){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}