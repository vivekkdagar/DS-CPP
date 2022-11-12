//
// Created by vivek on 11-11-2022.
//

#include <iostream>
#include <queue>
#include "Graph.h"

void Graph::BFS(int (*adj_mat)[7], int startVx,
                int n) {         // startVx is the vertex from which we're to start the traversal, n is the (number of total vertices) + 1 or total number of rows in matrix (including index 0).
    std::queue<int> q;
    std::cout << startVx << " ";
    int i = startVx;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    visited[i] = 1;
    q.emplace(i);
    while (!q.empty()) {
        i = q.front();
        q.pop();
        for (int j = 1; j < n; j++)
            if (adj_mat[i][j] == 1 && visited[j] == 0) {
                std::cout << j << " ";
                q.emplace(j);
                visited[j] = 1;
            }
    }
}

void Graph::DFS(int (*adj_mat)[7], int startVx, int n) {
    static int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    if (visited[startVx] == 0) {
        std::cout << startVx << " ";
        visited[startVx] = 1;
        for (int j = 1; j < n; j++) {
            if (visited[j] == 0 && adj_mat[startVx][j] == 1)
                DFS(adj_mat, j, n);
        }
    }
}
