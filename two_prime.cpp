#include <iostream>
using namespace std;

bool isPrime(int n)
{
 //   cout << n << endl;
    for(int i = 2; i <= n / 2; ++i)
    {
        if(n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int find_primes(unsigned int n)
{
    int small = 0;
    int big = 0;
    int start = 0;
    
    start = n - 3;
    
    while(!(isPrime(n - start) && isPrime(start)))
    {
        start -= 2;
    }
    int part = n - start;
    cout << part << " " << start << endl;
}

int main()
{
    int test_cases = 0;
    
    cin >> test_cases;
    unsigned int args[test_cases];
    
    for(int i = 0; i < test_cases; i++)
    {
        cin >> args[i];
    }
    
    for(int i = 0; i < test_cases; i++)
    {
        find_primes(args[i]);
    }
    
}



