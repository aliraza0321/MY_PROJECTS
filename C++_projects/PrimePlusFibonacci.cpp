#include<iostream>
using namespace std;

int main()
{
    const int n = 6;
    int a[n] = { 1,2,3,5,7,13};
    int final[100];
    bool isPrime = true;
    bool flag = true;
    int pri[n], fib[100], fibA[n], nonpri[n];
    int fact;
    int n1 = 0, n2 = 1;
    int next;
    fib[0] = 0, fib[1] = 1;
    next = n1 + n2;
    int swapCount = 0;  // Variable to count swaps

    // create fib series  stored in fib array
    for (int i = 2; i < 100; i++) {
        fib[i] = next;
        n1 = n2;
        n2 = next;
        next = n1 + n2;
    }
        
    int k = 0, j = 0;
    for (int i = 0; i < n; i++)
	 {
        fact = 2;
        while (fact < a[i])
		 {
            if (a[i] % fact == 0) 
			{        //find prime numbers
                isPrime = false;
                break;
            }
			 else 
			{
                isPrime = true;
            }
            fact++;
        }
        if (isPrime)
		 {
            pri[k] = a[i];
            k++;
        }
		 else
		  {
            nonpri[j] = a[i];      //store non prime 
            j++;
        }
    }

    // Remove non-primes that are also Fibonacci numbers
    for (int i = 0; i < k; i++) {
        for (int l = 0; l < j; l++) {
            for (int m = 0; m < 100; m++) {
                if (nonpri[l] == fib[m]) {
                    // Swap non-prime element with the last non-prime
                    int temp = nonpri[l];
                    nonpri[l] = nonpri[j - 1];
                    nonpri[j - 1] = temp;
                    j--;  // Reduce non-prime count
                    swapCount++;  // Increment swap count
                    break;
                }
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 100; j++) {
            if (a[i] == fib[j]) {
                fibA[count] = a[i];
                count++;
                break;
            }
        }
    }

    // store all arrays into final array
    int limit = 0;
    for (int i = 0; i < count; i++) {
        final[limit] = fibA[i];
        limit++;
    }

    for (int i = 0; i < j; i++) {
        final[limit] = nonpri[i];
        limit++;
    }

    for (int i = 0; i < k; i++) {
        final[limit] = pri[i];
        limit++;
    }

    // Remove duplicates using swap
    for (int i = 0; i < limit; i++) {
        for (int j = i + 1; j < limit; j++) {
            if (final[i] == final[j]) {
                int temp = final[j];
                final[j] = final[limit - 1];
                final[limit - 1] = temp;
                limit--;  // Reduce size of final array
                swapCount++;  // Increment swap count
                j--;  // Re-check the current index after swapping
            }
        }
    }

    cout<<"Fibonacci numbers on the left side ,prime numbers on right side and nonPrime-nonfib in middle\n";
    for (int i = 0; i < limit; i++) {
        cout << final[i] << " ";
    }

    // Output the number of swaps
    cout << "\nNumber of swaps: " << swapCount << endl;

    return 0;
}
