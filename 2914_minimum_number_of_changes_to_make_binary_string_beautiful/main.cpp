#include <string>

using namespace std;

struct Solution 
{
    int minChanges(string s) 
    {
        return process(split(s));
    }

private:
    using halves = std::pair<std::string_view, std::string_view>;

    int process(const halves& L_R)
    {
        const auto& [L, R] = L_R;
        auto L_size = L.size();
        auto R_size = R.size();

        if (L_size == 1 && R_size == 1)
            return (L.back() == R.back()) ? 0 : 1;
        else
            return process(split(L)) + process(split(R));
    }

    halves split(std::string_view str)
    {
        auto middle = str.size() / 2;
        return { str.substr(0, middle), str.substr(middle) };
    }
};

int main()
{
    Solution().minChanges("010010");
}