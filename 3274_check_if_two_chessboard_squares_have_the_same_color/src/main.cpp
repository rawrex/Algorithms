#include <string>

using namespace std;

struct Solution 
{
    bool checkTwoChessboards(string coordinate1, string coordinate2)
    {
        bool even_ch1 = !((coordinate1[0] - 'a' - 1) % 2);
        bool even_ch2 = !((coordinate2[0] - 'a' - 1) % 2);
        bool even_num1 = !(coordinate1[1] % 2);
        bool even_num2 = !(coordinate2[1] % 2);

        return even_ch1 == even_ch2 ? even_num1 == even_num2 : even_num1 != even_num2;
    }
};

int main()
{

}