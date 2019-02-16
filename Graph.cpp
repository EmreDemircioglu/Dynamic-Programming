//
// Created by Emre Demircioğlu on 27.12.2018.
//

#include "Graph.h"

Graph::Graph(int k) {
    this->size=k+1;
    this->adjacencyVector=new vector<int>[k+1];
    this->inDegree= new int[k+1];
    for (int i = 0; i < k + 1; ++i) {
        inDegree[i]=0;
    }
}
void Graph::rk(const char *word, const char *text, int q) {
    int wordLength = strlen(word);
    int textLength = strlen(text);
    int i,j;
    long long wordHash = 0;
    long long textHash = 0;
    long long h = 1;
    if(wordLength>textLength){
        return;
    }
    for ( i = 0; i < wordLength-1; i++) {
        h = (h * alphabet) % q;
    }
    for ( i = 0; i < wordLength; i++) {
        wordHash = (alphabet*wordHash + word[i])%q;
        textHash = (alphabet*textHash + text[i])%q;
    }
    for ( i = 0; i <= textLength - wordLength; i++) {
        if ( wordHash == textHash ) {
            for ( j = 0; j < wordLength; j++) {
                if (text[i+j] != word[j]) {
                    break;
                }
            }
            if (j == wordLength) {
                addEdge(i, i + wordLength);
            }
        }
        if ( i < textLength-wordLength ) {
            textHash = (alphabet*(textHash - text[i]*h) + text[i+wordLength])%q;
            if (textHash < 0)
                textHash = (textHash + q);
        }
    }
}
Graph::~Graph() {
    delete[] adjacencyVector;
    delete[] inDegree;
}
void Graph::addEdge(int a, int b){
    adjacencyVector[a].push_back(b);
    this->inDegree[b]++;
}
vector<int> Graph::ts(){
    queue<int> q;
    for (int i = 0; i < this->size; i++) {
        if (!this->inDegree[i]) {
            q.push(i);
        }
    }
    vector<int> temp;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        temp.push_back(u);
        for (int i : adjacencyVector[u]) {
            this->inDegree[i]--;
            if (!this->inDegree[i])
                q.push(i);
        }
    }
    return temp;
}
long long Graph::solve() {
    vector<int> temp = ts();
    long long result[this->size];
    for (int k = 0; k < this->size; ++k) {
        result[k]=0;
    }
    result[this->size-1] = 1;
    for (int i = temp.size() - 1; i >= 0; i--) {
        for (int j = 0; j < adjacencyVector[temp[i]].size(); j++) {
            result[temp[i]] += (result[adjacencyVector[temp[i]][j]]%1000000007);
            result[temp[i]]%=1000000007;
            if(result[temp[i]]<0){
                result[temp[i]]+=1000000007;
            }
        }
    }
    return result[0];
}