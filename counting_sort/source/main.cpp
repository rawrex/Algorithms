#include <iostream>
#include <vector>
#include "../../utils/source/random.h"
#include "../../utils/source/print.h"



int main()
{
	auto input = randomIntVector(10, 0, 3);
	print(input);
}