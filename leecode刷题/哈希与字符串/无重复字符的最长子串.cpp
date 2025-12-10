#include<iostream>
#include<unordered_map>
using namespace std;
int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> hash_map;
    int start=0;
    int result=0;
    int i=0;
    for(i;i<s.size();i++){
        if(hash_map.find(s[i])==hash_map.end()){
            hash_map[s[i]]=i;
        }else{
            if(result<i-start)
                result=i-start;
            if(start<=hash_map[s[i]])
                start=hash_map[s[i]]+1;
            hash_map[s[i]]=i;
        }
    }
    if(result<i-start)
        result=i-start;
    return result;
}
int main()
{
    string s="abba";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}