#include <stdio.h>

// Function to calculate the square root using a simple iterative method
int mySqrt(int n)
{
    if (n <= 1) return n;
    int x = n;
    int y = (x + n / x) / 2;
    while (x > y)
    {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

// Function to calculate sum of all proper divisors
int getSum(int n)
{
    int sum = 0;  // 1 is a proper divisor

    // Loop up to square root of n (using mySqrt instead of sqrt)
    for (int i = 1; i <= mySqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, take only one of them
            if (n / i == i)
                sum = sum + i;
            else  // Otherwise take both
            {
                sum = sum + i;
                sum = sum + (n / i);
            }
        }
    }

    // Calculate sum of all proper divisors only
    return sum - n;
}

// Function to print the Aliquot Sequence for an input n.
void printAliquot(int n)
{
    // Print the first term
    printf("%d ", n);

    int visited[10000] = {0}; // Array to store visited terms
    visited[n] = 1;

    while (n > 0)
    {
        n = getSum(n);

        // If the next term repeats (i.e., we reach a cycle), stop
        if (visited[n] != 0)
        {
            printf("\nRepeats with %d\n", n);
            break;
        }

        // Print next term
        printf("%d ", n);

        // Mark the new term as visited
        visited[n] = 1;
    }
}

int main()
{
    int n;

    // Prompt the user to enter a number
    printf("Enter a number to calculate the Aliquot sequence: ");
    scanf("%d", &n);  // Read the number from the user

    // Call the function to print the aliquot sequence for the number
    printAliquot(n);

    return 0;
}
