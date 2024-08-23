#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric> // For std::gcd in C++17

using namespace std;

struct Fraction
{
    Fraction(const std::string& str)
    {
        size_t pos = str.find('/');
        if (pos != std::string::npos)
        {
            numerator = std::stoi(str.substr(0, pos));
            denominator = std::stoi(str.substr(pos + 1));
        }
        else
        {
            numerator = 0;
            denominator = 1;
        }
        reduce();
    }

    Fraction& operator +=(const Fraction& other)
    {
        // a/b + c/d = (a * d + b * c) / (b * d)
        numerator = numerator * other.denominator + denominator * other.numerator;
        denominator = denominator * other.denominator;

        reduce();
        return *this;
    }

    Fraction& operator -=(const Fraction& other)
    {
        // a/b - c/d = (a * d - b * c) / (b * d)
        numerator = numerator * other.denominator - denominator * other.numerator;
        denominator = denominator * other.denominator;

        reduce();
        return *this;
    }

    operator string() const
    {
        return to_string(numerator) + '/' + to_string(denominator);
    }

private:
    void reduce()
    {
        int gcd_val = std::gcd(numerator, denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;

        // Handle negative denominator
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

private:
    int numerator;
    int denominator;
};


struct Solution
{
    string fractionAddition(string expression) 
    {
        auto size = expression.size();
        string::size_type i = 0;

        char pending_operation;
		string current_fraction;

		Fraction running_sum("1/1");

        if (expression[0] == '+')
        {
            pending_operation = '+';
        }
        else
        {
            pending_operation = '-';
            running_sum = Fraction("0/1");
            ++i;
        }

        for (; i != size; ++i)
        {
            char c = expression[i];
            current_fraction.push_back(c);

			if (i == size - 1 || c == '+' || c == '-')
			{
                if(i != size - 1)
                    current_fraction.pop_back();

				switch (pending_operation)
				{
					case '+':
						running_sum += Fraction(current_fraction);
						break;
					case '-':
						running_sum -= Fraction(current_fraction);
						break;
				}

				pending_operation = c;
				current_fraction.erase();
			}
		}
        
        return running_sum;
    }
};

int main()
{
    Solution().fractionAddition("-1/2+1/2");
}