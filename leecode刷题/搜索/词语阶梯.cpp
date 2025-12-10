#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
bool connect(const string &word1,const string &word2){
    int cnt=0;
    for(int i=0;i<word1.length();i++){
        if(word1[i]!=word2[i]){
            cnt++;
        }
    }
    return cnt==1;
}
void connect_graph(string &beginWord,vector<string>& wordList,map<string,vector<string>> &graph){
    wordList.push_back(beginWord);
    for(int i=0;i<wordList.size();i++){
        graph[wordList[i]]=vector<string>();
    }
    for(int i=0;i<wordList.size();i++){
        for(int j=i+1;j<wordList.size();j++){
            if(connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
    }
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    map<string,vector<string>> graph;
    connect_graph(beginWord,wordList,graph);
    map<string,bool> visit;
    for(int i=0;i<wordList.size();i++){
        visit[wordList[i]]=false;
    }
    queue<pair<string,int>> Q;
    Q.push({beginWord,1});
    visit[beginWord]=true;
    while(!Q.empty()){
        string word=Q.front().first;
        int seq=Q.front().second;
        Q.pop();
        if(word==endWord)
            return seq;
        for(int i=0;i<graph[word].size();i++){
            if(visit[graph[word][i]])
                continue;
            Q.push({graph[word][i],seq+1});
            visit[graph[word][i]]=true;
        }
    }
    return 0;
}
int main(){
    string beginWord="hit";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord,"cog",wordList)<<endl;
    return 0;
}