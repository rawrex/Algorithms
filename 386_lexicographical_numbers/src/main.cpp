#include <set>
#include <vector>
#include <string>

using namespace std;

struct Solution 
{
    vector<int> lexicalOrder(int n) 
    {
        return naive(n);
    }

private:
    vector<int> naive(int n)
    {
        string a_str;
        string b_str;

        auto sorter = [&a_str, &b_str](int a, int b) 
        { 
            a_str = std::to_string(a);
            b_str = std::to_string(b);

            return a_str < b_str;
        };

        set<int, decltype(sorter)> sorted(sorter);

        for (int i = 1; i <= n; ++i)
            sorted.emplace(i);

        return { std::cbegin(sorted), std::cend(sorted) };
    }
};

int main()
{

}