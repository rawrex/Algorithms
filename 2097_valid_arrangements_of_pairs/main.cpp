#include <stack>
#include <vector>
#include <ranges>
#include <unordered_map>

using namespace std;

struct Solution 
{
	using graph_t = unordered_map<int, stack<int>>;
	using map_t = unordered_map<int, int>;
	using pairs_t = vector<vector<int>>;

	pairs_t validArrangement(pairs_t& pairs)
	{
		graph_t graph;
		map_t out_degrees;
		map_t in_degrees;

		graph.reserve(pairs.size());
		out_degrees.reserve(pairs.size());
		in_degrees.reserve(pairs.size());

		for (const auto& pair : pairs) 
		{
			const int start = pair[0];
			const int end = pair[1];

			graph[start].push(end);

			++out_degrees[start];
			++in_degrees[end];
		}

		auto start = getStartNode(graph, out_degrees, in_degrees, pairs);
		pairs.clear();
		euler(graph, start, pairs);
		reverse(std::begin(pairs), std::end(pairs));

		return pairs;
	}

private:
	int getStartNode(const graph_t& graph, map_t& out_degrees, map_t& in_degrees, const pairs_t& pairs) const noexcept
	{
		for (const auto& [u, _] : graph)
			if (out_degrees[u] - in_degrees[u] == 1)
				return u;

		// Arbitrarily choose a node
		return pairs[0][0];  
	}

	void euler(graph_t& graph, int u, pairs_t& result) 
	{ 
		auto& stack = graph[u];

		while (!stack.empty()) 
		{
			const int v = stack.top();
			stack.pop();

			euler(graph, v, result);
			result.push_back({ u, v });
		}
	}
};

int main()
{

}