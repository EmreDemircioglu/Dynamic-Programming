//
// Created by Emre Demircioğlu on 27.12.2018.
//

#ifndef PROJECT5_GRAPH_H
#define PROJECT5_GRAPH_H

using namespace std;
#include <list>
#include<stdio.h>
#include<string.h>
#include <queue>
#include <iostream>
#define alphabet 26
class Graph {
public:
    vector<int> *adjacencyVector;
    int size;
    int* inDegree;
    explicit Graph(int k);
    ~Graph();
    void rk(const char word[],const char text[], int q);
    void addEdge(int a, int b);
    vector<int> ts();
    long long solve();
};


#endif //PROJECT5_GRAPH_H
