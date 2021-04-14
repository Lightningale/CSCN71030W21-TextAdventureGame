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

void main() //testing RNG function, this is how it should be called in main game
{
    srand(time(NULL)); // rng is seeded with the internal clock of the system, gives the best pseduo random number
    RNG(1, 500, 1); //call rng with (min value, max value, number of numbers to generate
}