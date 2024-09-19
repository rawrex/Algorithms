#include <vector>
#include <string>
#include <unordered_map>
#include <exception>

using namespace std;

struct Solution 
{
    vector<int> diffWaysToCompute(string expression) 
    {
        return dfs(expression);
    }

private:
    vector<int> dfs(const string& expression)
    {
		vector<int> current_result;

        if (m_memory.contains(expression))
            return m_memory.at(expression);

        if (isNumber(expression))
            return { std::stoi(expression) };

        string left_part;
        for (string::size_type i = 0; i != expression.size(); ++i)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                auto L_subexpression = expression.substr(0, i);
                auto R_subexpression = expression.substr(i+1);

				auto L_result = dfs(L_subexpression);
				auto R_result = dfs(R_subexpression);

				for (int left : L_result)
				{
					for (int right : R_result)
						current_result.emplace_back(eval(c, left, right));
				}
            }
        }

        return m_memory[expression] = current_result;
    }

    bool isNumber(const string& str) const noexcept
    {
        bool is_number = true;

        for (char c : str)
            if (!std::isdigit(c)) is_number = false;

        return is_number;
    }

    int eval(char op, int lhs, int rhs) const noexcept
    {
        switch (op)
        {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        default:
            throw("Wrong operator");
        }
    }

    unordered_map<string, vector<int>> m_memory;
};

int main()
{

}