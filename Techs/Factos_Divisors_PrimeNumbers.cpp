/*



*/



/* Calculating Divisors(Factors) */
//To get them for a number 'n', you need to check till sqrt(n).

for(int i=2; i<sqrt(n); ++i)
if(n%i) {
cout<<i<<" is a factor of n";
cout<<n/i<<" is a factor of n";
}


/* Problem 1: find factors p,q of n such that pq = n and |p-q| is minimized.(https://discuss.codechef.com/questions/1123/resq-editorial) */ 
//We need to brute force through all the factors but note that |p-q| attains minima near p~q~sqrt(n)
//So instead of upcounting, start downcounting from sqrt(n) so it breaks outta loop faster ;)
 for(i=(int)sqrt(n); i>1; i--)
        {
            if(n%i==0)//i is a factor
            {
                otherDiv = n/i;//otherDiv >= sqrt(n) >= i
                ans = otherDiv - i;//so ans is +ve always
                break;
            }
        }
//Alternative solution
/* This approach uses the Sieve of Eratosthenes algorithm for finding prime numbers. Using this, we find all the primes till sqrt(N) once and store them in an array. 
Now, for every given N, we find all its prime factors and store them in an array. This can be done by looping over the prime numbers that we generated earlier and checking if each of it is a factor of N. We check for only those numbers which are not greater than sqrt(N). If any of those prime numbers is a factor, we calculate the degree of that factor. By degree of a factor we mean the number of times the factor divides the number. For example, 24 = 23.31. Here 2 (the prime factor) has a degree of 3 and 3(the next prime factor) has a degree of 1.

Next we try to generate all the divisors of N using the above information that we gathered. Initially our divisors array will have 1 in it (1 is a divisor of every number ). We can do this by going through each prime factor x, and multiply each element in the existing divisors array by xi where 0<=i<=degree[x]. For example, let N = 84. 84 can be written as 22.31.71

So we finally have the array of the entire divisors. Note that we do not have these divisors in the sorted order. So we will have to check for every divisor d, and check for the minimum difference of |d – N/d|.

This approach is asymptotically better than the previous approach. Let's look at the complexity of this solution. Generating the primes using the sieve has O(sqrt(N) * log log N) complexity. And on an average, getting all the prime factors and generating the divisors of a number will take O(sqrt(N)/log(N)) time. So the overall complexity is O(sqrt(N) * log log N + T * sqrt(N) / log(N)) .
*/
https://gist.github.com/iitjee/1c018afc5b6c59e647ea3c460457b749
