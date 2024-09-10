#include <string>

using namespace std;

struct Solution 
{
    int generateKey(int num1, int num2, int num3)
    {
        string key;

        int k = 0;
        for (int i = 1000; i; i /= 10)
        {
            int digit1 = num1 / i;
            int digit2 = num2 / i;
            int digit3 = num3 / i;

            num1 %= i;
            num2 %= i;
            num3 %= i;

            if (!digit1 || !digit2 || !digit3)
                continue;
            k += i * min(min(digit1, digit2), min(digit2, digit3));
        }

        return k;
    }
};

int main()
{

}