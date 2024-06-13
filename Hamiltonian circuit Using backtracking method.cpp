#include <stdio.h>
#include <stdbool.h>

#define V 5 // Number of vertices

bool isSafe(int graph[V][V], int path[], int pos) {
    if (graph[path[pos - 1]][path[pos]] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == path[pos])
            return false;

    return true;
}

bool hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(graph, path, pos)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1; // backtrack
        }
    }

    return false;
}

void printSolution(int path[]) {
    printf("Hamiltonian cycle exists: ");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

void hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;
    if (!hamiltonianCycleUtil(graph, path, 1)) {
        printf("Hamiltonian cycle does not exist\n");
        return;
    }

    printSolution(path);
}

int main() {
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}
