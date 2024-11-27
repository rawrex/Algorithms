#include <queue>
#include <vector>
#include <numeric>

using namespace std;

struct Solution 
{
	vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) 
	{
		vector<int> result;
		vector<int> distances(n);
		vector<vector<int>> graph(n);

		iota(distances.begin(), distances.end(), 0);

		for (int i = 0; i < n - 1; ++i)
			graph[i].push_back(i + 1);

		for (const auto& query : queries) 
		{
			auto u = query[0];
			auto v = query[1];

			// add the new edge to the adjacency list
			graph[u].push_back(v);

			// if the current shortest can be improved via u,
			// update, and propagete this using bfs
			if (distances[u] + 1 < distances[v]) 
			{
				distances[v] = distances[u] + 1;
				bfs(graph, v, distances);
			}

			result.push_back(distances[n - 1]);
		}

		return result;
	}

private:
	// ensures that any dowhstream node is reachable from v (start)
	// this is necessary because adding a new edge can impact not just v but also nodes reachable from v
	void bfs(const vector<vector<int>>& graph, int start, vector<int>& dist) 
	{
		queue<int> q{ {start} };

		while (!q.empty()) 
		{
			const int u = q.front();
			q.pop();

			for (int v : graph[u]) 
			{
				if (dist[u] + 1 < dist[v]) 
				{
					dist[v] = dist[u] + 1;
					q.push(v);
				}
			}
		}
	}
};

int main()
{

}