#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;
int lengthOfLongestSubstring(string s) {
    if(s.size()<=1) return s.size();
    int max_length=0;
    int char_map[128]={0};
    int i=0,j=1;
    char_map[s[i]]++;
    for(j;j<s.size();j++){
        if(char_map[s[j]]==0){
            char_map[s[j]]++;
        }else{
            max_length = (j-i)>max_length?j-i:max_length;
            while(char_map[s[j]]>0){
                char_map[s[i]]--;
                i++;
            }
            char_map[s[j]]++;
        }
    }
    max_length = (j-i)>max_length?j-i:max_length;
    return max_length;
}
bool is_windows_ok(int s_map[],int t_map[],vector<int> vec_t){
    for(int i=0;i<vec_t.size();i++){
        if(s_map[vec_t[i]]<t_map[vec_t[i]])
            return false;
    }
    return true;
}
string minWindow(string s, string t) {
    if(s.size()<t.size()) return "";
    string result;
    int t_map[128]={0};
    int s_map[128]={0};
    vector<int> vec_t;
    for(int i=0;i<t.size();i++){
        t_map[t[i]]++;
    }
    for(int i=0;i<128;i++)
    {
        if(t_map[i]>0)
            vec_t.push_back(i);
    }
    int len = t.size();
    int begin=0;
    for(int i;i<s.size();i++){
        s_map[s[i]]++;
        while(begin<i){
            int begin_ch = s[begin];
            if(t_map[begin_ch]==0){
                begin++;
            }else if(s_map[begin_ch]>t_map[begin_ch]){
                s_map[begin_ch]--;
                begin++;
            }else{
                break;
            }
        }
        if(is_windows_ok(s_map,t_map,vec_t)){
            int new_window_len = i-begin+1;
            if(result==""||new_window_len<result.size()){
                result = s.substr(begin,new_window_len);
            }
        }
    }
    return result;
}
int main()
{
    string s="ADOBECODEBANC";
    cout<<minWindow(s,"ABC");
    return 0;

}