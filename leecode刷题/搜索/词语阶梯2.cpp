#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct QItem{
    string node;   //搜索节点
    int parent_pos; //前驱节点在队列中的位置
    int step;   //  到达当前节点的步数
    QItem(string node,int parent_pos,int step):node(node),parent_pos(parent_pos),step(step){}
};
bool connect(const string &word1,const string &word2){
    int cnt=0;
    for(int i=0;i<word1.length();i++){
        if(word1[i]!=word2[i]){
            cnt++;
        }
    }
    return cnt==1;
}


void BFS_graph(string &beginWord,string &endWord,map<string,vector<string>> &graph,vector<QItem> &Q,vector<int> &end_word_pos){
    map<string,int> visit;
    Q.push_back(QItem(beginWord,-1,1));
    int min_step=0;
    visit[beginWord]=1;
    int front=0;
    while(front!=Q.size()){
        const string &node=Q[front].node;
        int step=Q[front].step;
        if(min_step!=0 && step>min_step){
            break;
        }
        if(node == endWord){
            min_step=step;
            end_word_pos.push_back(front);
        }
        const vector<string> &neighbors = graph[node];
        for(int i=0;i<neighbors.size();i++){
            if(visit.find(neighbors[i])==visit.end()||visit[neighbors[i]]==step+1){
                Q.push_back(QItem(neighbors[i],front,step+1));
                visit[neighbors[i]]=step+1;
            }
        }
        front++;
    }
}
void construct_graph(string &beginWord,vector<string> &wordList,map<string,vector<string>> &graph){
    int has_begin_word=0;
    for(int i=0;i<wordList.size();i++){
        if(wordList[i]==beginWord){
            has_begin_word=1;
        }
        graph[wordList[i]]=vector<string>();
    }
    for(int i=0;i<wordList.size();i++){
        for(int j=i+1;j<wordList.size();j++){
            if(connect(wordList[i],wordList[j])){
                graph[wordList[i]].push_back(wordList[j]);
                graph[wordList[j]].push_back(wordList[i]);
            }
        }
        if(has_begin_word == 0 && connect(beginWord,wordList[i])){
            graph[beginWord].push_back(wordList[i]);
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    map<string,vector<string>> graph;
    construct_graph(beginWord,wordList,graph);
    vector<QItem> Q;
    vector<int> end_word_pos;
    BFS_graph(beginWord,endWord,graph,Q,end_word_pos);
    vector<vector<string>> result;
    for(int i=0;i<end_word_pos.size();i++){
        int pos=end_word_pos[i];
        vector<string> path;
        while(pos!=-1){
            path.push_back(Q[pos].node);
            pos=Q[pos].parent_pos;
        }
        result.push_back(vector<string>());
        for(int j=path.size()-1;j>=0;j--){
            result[i].push_back(path[j]);
        }
    }
    return result;
}
int main(){
    string beginWord="hit";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> result=findLadders(beginWord,"cog",wordList);
    for(auto path:result){
        for(auto s:path){
            cout<<s<<" ";
        }
        cout<<endl;
    }
    return 0;
}