#include <iostream>
using namespace std;

#define V 100
#define INF 99999

int main() {
    int n;

    cout << "Enter number of vertices: ";
    cin >> n;

    int graph[V][V];

    cout << "Enter adjacency matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 0)
                graph[i][j] = INF; // no edge
        }
    }

    int selected[V] = {0};
    selected[0] = 1;

    int no_edge = 0;
    int total_cost = 0;

    cout << "Edges in MST:\n";

    while(no_edge < n - 1) {
        int min = INF;
        int x = 0, y = 0;

        for(int i = 0; i < n; i++) {
            if(selected[i]) {
                for(int j = 0; j < n; j++) {
                    if(!selected[j] && graph[i][j]) {
                        if(min > graph[i][j]) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        cout << x << " - " << y << " : " << graph[x][y] << endl;

        total_cost += graph[x][y];
        selected[y] = 1;
        no_edge++;
    }

    cout << "Total cost = " << total_cost;

    return 0;
}
