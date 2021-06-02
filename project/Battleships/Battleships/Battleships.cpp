#include "Fibonacci.h"
#include "RandomTesting.h"

int main(int argc, char* argv[])
{
    auto randomTesting = RandomTesting();
    cout << "How many times do you wanna run" << endl;
    int val;
    cin >> val;
    randomTesting.test(val);
    return 0;
}
