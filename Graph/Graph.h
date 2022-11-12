//
// Created by vivek on 11-11-2022.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H


class Graph {
public:
    static void BFS(int adj_mat[][7], int startVx, int n);

    static void DFS(int adj_mat[][7], int startVx, int n);
};


#endif //GRAPH_GRAPH_H
