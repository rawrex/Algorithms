#include <limits>

class Solution 
{
public:
    int maximumValue(vector<string>& strs) 
    {
        return iter(strs);
    }
private:
    int iter(const vector<string>& input) noexcept
    {
        int max = std::numeric_limits<int>::min();

        for(const auto& str : input)
            // max = std::max(max, naiveValue(str));
            max = std::max(max, value(str));

        return max;
    }

    int naiveValue(const string& str)
    {
        auto size = str.size();
        try
        {
            auto value = std::stoi(str, &m_processed);
            if(m_processed == size)
                return value;
            else
                return static_cast<int>(size);
        }
        catch(const std::invalid_argument& error)
        {
            return static_cast<int>(size);
        }
    }

    int value(const string& input_str)
    {
        const char* str = input_str.c_str();

        int value = 0;
        while(*str) 
        {
            if(std::isdigit(*str))
                value = value * 10 + (*str++ - '0');
            else
                return input_str.size(); 
        }

        return value;
    }

    std::size_t m_processed = 0;
};
