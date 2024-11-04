#include <string>

using namespace std;

struct Solution
{
    string compressedString(string word)
    {
        static size_t limit = 9;
        string result;

        char prev = word[0];
        size_t counter = 1;

        auto size = word.size();
        for (size_t i = 1; i <= size; ++i)
        {
            if (i == size)
            {
                result.push_back(static_cast<char>('0' + counter));
                result.push_back(prev);
                break;
            }
            else if (counter == limit || word[i] != prev)
            {
                result.push_back(static_cast<char>('0' + counter));
                result.push_back(prev);
                counter = 0;
            }

            ++counter;
            prev = word[i];
        }

        return result;
    }
};

int main()
{

}