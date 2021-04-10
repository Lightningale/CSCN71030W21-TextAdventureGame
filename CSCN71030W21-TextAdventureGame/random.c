#include <time.h>
#include <stdlib.h>
#include <stdio.h>

//rng function
void RNG(const int Min, const int Max, const int  outputnum) //takes min value, max value, and amount of numbers to output
{
    int RNG = 0;
    for (int x = 0; x < outputnum; x++)
    {
        RNG = rand() % (Max - Min) + Min;
        printf("%d ", RNG);
    }
    printf("\n");
}

void main()
{
    srand(time(NULL));
    RandomNumberGenerator(1, 500, 1);
}
