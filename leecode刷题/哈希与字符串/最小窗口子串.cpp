#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
string minWindow(string s, string t) {
    if(s.size()<t.size())
            return "";
    unordered_map<char,int> char_map;
    int len=t.size();
    for(auto c:t){
        if(char_map.find(c)==char_map.end()){
            char_map.insert({c,0});
        }
        char_map[c]++;
    }
    int start=-1;
    int state=0;
    string result="";
    for(int i=0;i<s.size();i++){
        if(char_map.find(s[i])!=char_map.end()){
            if(start==-1)
                start=i;
            char_map[s[i]]--;
            if(char_map[s[i]]>=0){
                len--;
                if(len==0){
                    result=s.substr(start,i-start+1);
                    state=1;
                }
            }
            if(state==1&&char_map[s[start]]<0){
                char_map[s[start]]++;
                start++;
                while(1){
                    if(char_map.find(s[start])==char_map.end())
                        start++;
                    else{
                        if(char_map[s[start]]==0)
                            break;
                        else{
                            char_map[s[start]]++;
                            start++;
                        }
                    }
                }
                string temp=s.substr(start,i-start+1);
                if(temp.size()<result.size())
                    result=temp;
            }
        }
    }
    return result;
}
int main(){
    string s = "bba", t = "ab";
    cout<<minWindow(s,t);
    return 0;
}