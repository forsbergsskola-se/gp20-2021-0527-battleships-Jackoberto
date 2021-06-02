#include "RandomTesting.h"

#include <cstdlib>
#include <ctime>
#include <iostream>


void RandomTesting::test(int times_to_run)
{
    srand(time(0));
    int occurrences[20];
    memset(occurrences, 0, sizeof(occurrences));
    int num;
    for (int i = 0; i < times_to_run; i++)
    {
        num = rand() % 20;
        occurrences[num]++;
    }
    float percent;
    for (int i = 0; i < 20; i++)
    {
        percent = ((float) occurrences[i] / times_to_run) * 100;
        std::cout << "Percent of " << i + 1 << " is " << percent << "%" << std::endl;
    }
}
