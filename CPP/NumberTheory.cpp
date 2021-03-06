/*



*/

/*  GCD */
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; } //no need to check whether a>b or not. (see prop 4, obvio right?)

Properties:
1. gcd(a, b) = gcd(a, a-b)
2. If m is a non-negative integer, then gcd(m·a, m·b) = m·gcd(a, b)
3. If m is any integer, then gcd(a + m·b, b) = gcd(a, b)
4. gcd(a, b) = gcd(b, a)
5. gcd(a, gcd(b, c)) = gcd(gcd(a, b), c) //IMP
6. If a is a non-zero integer, then gcd(a,0)=a

Problems:
https://www.codechef.com/problems/AMSGAME1
