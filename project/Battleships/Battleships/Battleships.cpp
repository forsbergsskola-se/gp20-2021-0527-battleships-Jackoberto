#include "BattleShipGame.h"
#include "Fibonacci.h"
#include "RandomTesting.h"

int main(int argc, char* argv[])
{
    // Fibonacci::test(20);
    // RandomTesting::testVariableNum();
    auto battle_ships = BattleShipGame();
    battle_ships.run();
    return 0;
}

/*
// In this solution the array that gets allocated in the add method get deallocated and therefore could be overwritten later
float* add(float* a, float* b)
{
    float results[3];
    results[0] = a[0] + b[0];
    results[1] = a[1] + b[1];
    results[2] = a[2] + b[2];
    return results;
}

// In this solution the problem with allocation in another method gets solved
// Only passing pointers though does allow someone to pass in an array that isn't of the right size
// void add(float* a, float* b, float* out)
// {
//     out[0] = a[0] + b[0];
//     out[1] = a[1] + b[1];
//     out[2] = a[2] + b[2];
// }

// This solution seems to be just a different way to write V2 and doesn't help with type safety but rather just good for documentation
// There's also an issue that the elements of a and b could be changed unintentionally which isn't desirable in this case
void add(float a[3], float b[3], float out[3])
{
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}

// Out shouldn't be const right?
// In this case we know a and b will be not be changed and it's also documented
void add(const float a[3], const float b[3], float out[3])
{
    out[0] = a[0] + b[0];
    out[1] = a[1] + b[1];
    out[2] = a[2] + b[2];
}

// As dividend is a value and not a pointer it will be allocated (and therefore have a new address) again for this method therefore we don't need to mark it const although it would probably not hurt for documentation purposes
void divide(const float vector[3], float dividend, float result[3])
{
    result[0] = vector[0] / dividend;
    result[1] = vector[1] / dividend;
    result[2] = vector[2] / dividend;
}

int main()
{
    // 1
    // float v1[3] = {1,1,1};
    // float v2[3] = {2,2,2};
    // float v3[3] = {3,3,3};
    // float v4[2] = {1,2};
    // float* sum1 = add(v1, v2);
    // float* sum2 = add(v2, v3);
    // float* sum3 = add(v3, v1);
    // cout << sum1[0] << ", " << sum1[1] << ", " << sum1[2] << endl;
    // cout << sum2[0] << ", " << sum2[1] << ", " << sum2[2] << endl;
    // cout << sum3[0] << ", " << sum3[1] << ", " << sum3[2] << endl;
  
    // 2 & 3 
    // float v1[3] = {1,1,1};
    // float v2[3] = {2,2,2};
    // float v3[3] = {3,3,3};
    // float v4[2] = {1,2};
    // float sum1[3] = {0, 0, 0};
    // float sum2[3] = {0, 0, 0};
    // float sum3[3] = {0, 0, 0};
    // add(v1, v2, sum1);
    // add(v2, v3, sum2);
    // add(v3, v1, sum3);
    // cout << sum1[0] << ", " << sum1[1] << ", " << sum1[2] << endl;
    // cout << sum2[0] << ", " << sum2[1] << ", " << sum2[2] << endl;
    // cout << sum3[0] << ", " << sum3[1] << ", " << sum3[2] << endl;

    // 4
    // const float v1[3] = {1,1,1};
    // const float v2[3] = {2,2,2};
    // const float v3[3] = {3,3,3};
    // const float v4[2] = {1,2};
    // float sum1[3] = {0, 0, 0};
    // float sum2[3] = {0, 0, 0};
    // float sum3[3] = {0, 0, 0};
    // add(v1, v2, sum1);
    // add(v2, v3, sum2);
    // add(v3, v1, sum3);
    // cout << sum1[0] << ", " << sum1[1] << ", " << sum1[2] << endl;
    // cout << sum2[0] << ", " << sum2[1] << ", " << sum2[2] << endl;
    // cout << sum3[0] << ", " << sum3[1] << ", " << sum3[2] << endl;

    // 5 Division
    const float v1[3] = {1,1,1};
    const float v2[3] = {2,2,2};
    const float v3[3] = {3,3,3};
    const float v4[2] = {1,2};
    float quotient1[3] = {0, 0, 0};
    float quotient2[3] = {0, 0, 0};
    float quotient3[3] = {0, 0, 0};
    divide(v1, 2, quotient1);
    divide(v2, 2, quotient2);
    divide(v3, 2, quotient3);
    cout << quotient1[0] << ", " << quotient1[1] << ", " << quotient1[2] << endl;
    cout << quotient2[0] << ", " << quotient2[1] << ", " << quotient2[2] << endl;
    cout << quotient3[0] << ", " << quotient3[1] << ", " << quotient3[2] << endl;
}*/