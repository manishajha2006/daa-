#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, e;

    cout << "Enter number of vertices and edges: ";
    cin >> n >> e;

    int adj[100][100] = {0};
    int indegree[100] = {0};

    cout << "Enter edges (u v):\n";
    for(int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        indegree[v]++;
    }

    queue<int> q;

    // Push vertices with indegree 0
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    cout << "Topological Order:\n";

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for(int v = 0; v < n; v++) {
            if(adj[u][v] == 1) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
    }

    return 0;
}
