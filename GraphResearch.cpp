#include <iostream>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

const int SIZE = 6;

int graph[SIZE][SIZE] =
{
    {0, 2, 4, 0, 0, 0},
    {2, 0, 1, 7, 0, 0},
    {4, 1, 0, 3, 5, 0},
    {0, 7, 3, 0, 2, 6},
    {0, 0, 5, 2, 0, 4},
    {0, 0, 0, 6, 4, 0}
};

bool visited[SIZE];

void DFS(int vertex)
{
    visited[vertex] = true;

    cout << vertex << " ";

    for (int i = 0; i < SIZE; i++)
    {
        if (graph[vertex][i] != 0 && !visited[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    bool visitedBFS[SIZE] = { false };

    queue<int> q;

    visitedBFS[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int i = 0; i < SIZE; i++)
        {
            if (graph[current][i] != 0 && !visitedBFS[i])
            {
                visitedBFS[i] = true;
                q.push(i);
            }
        }
    }
}

void Dijkstra(int start)
{
    int distance[SIZE];
    bool visitedDijkstra[SIZE];

    for (int i = 0; i < SIZE; i++)
    {
        distance[i] = INT_MAX;
        visitedDijkstra[i] = false;
    }

    distance[start] = 0;

    for (int count = 0; count < SIZE - 1; count++)
    {
        int min = INT_MAX;
        int u = -1;

        for (int i = 0; i < SIZE; i++)
        {
            if (!visitedDijkstra[i] && distance[i] < min)
            {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visitedDijkstra[u] = true;

        for (int v = 0; v < SIZE; v++)
        {
            if (graph[u][v] != 0 &&
                !visitedDijkstra[v] &&
                distance[u] != INT_MAX &&
                distance[u] + graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
            }
        }
    }

    cout << endl;
    cout << "Shortest distances from vertex " << start << ":" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << "Vertex " << i << " : ";

        if (distance[i] == INT_MAX)
            cout << "INF";
        else
            cout << distance[i];

        cout << endl;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "==============================" << endl;
        cout << "      GRAPH RESEARCH" << endl;
        cout << "==============================" << endl;

        cout << "1. Show adjacency matrix" << endl;
        cout << "2. Depth First Search (DFS)" << endl;
        cout << "3. Breadth First Search (BFS)" << endl;
        cout << "4. Dijkstra Algorithm" << endl;
        cout << "5. Exit" << endl;

        cout << endl;
        cout << "Choose option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << endl;
            cout << "Adjacency Matrix:" << endl;

            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    cout << graph[i][j] << " ";
                }

                cout << endl;
            }

            break;

        case 2:

            for (int i = 0; i < SIZE; i++)
            {
                visited[i] = false;
            }

            cout << endl;
            cout << "DFS traversal:" << endl;

            DFS(0);

            cout << endl;

            break;

        case 3:

            cout << endl;
            cout << "BFS traversal:" << endl;

            BFS(0);

            cout << endl;

            break;

        case 4:

            Dijkstra(0);

            cout << endl;

            break;

        case 5:

            cout << endl;
            cout << "Program finished." << endl;

            break;

        default:

            cout << endl;
            cout << "Wrong choice!" << endl;
        }

        cout << endl;

    } while (choice != 5);

    return 0;
}