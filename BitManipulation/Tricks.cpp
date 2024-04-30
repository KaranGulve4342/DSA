// Bit Manipulation Tricks

// checking if the number is even or odd
// if the number is even, the last bit will be 0
// if the number is odd, the last bit will be 1
// so, if we do n&1, we will get 0 if the number is even and 1 if the number is odd
// if the number is n
// n&1 will be 0 if n is even
// n&1 will be 1 if n is odd

// checking if the number is a power of 2
// if the number is a power of 2, it will have only 1 bit set
// so, if we do n&(n-1), we will get 0 if the number is a power of 2
// if the number is n
// n&(n-1) will be 0 if n is a power of 2
// n&(n-1) will not be 0 if n is not a power of 2

// checking if the ith bit is set
// if we do n&(1<<i), we will get 1 if the ith bit is set
// if the number is n
// n&(1<<i) will be 0 if the ith bit is not set
// n&(1<<i) will be 1 if the ith bit is set

// Toggling the ith bit
// if we do n^(1<<i), the ith bit will be toggled
// if the number is n
// n^(1<<i) will toggle the ith bit

// setting the ith bit
// if we do n|(1<<i), the ith bit will be set
// if the number is n
// n|(1<<i) will set the ith bit

// unsetting the ith bit
// if we do n&~(1<<i), the ith bit will be unset
// if the number is n
// n&~(1<<i) will unset the ith bit

// Multiply or Divide a Number by 2^k
// if we do n<<k, we will get n*2^k
// if we do n>>k, we will get n/2^k

// Finding our x%2^k
// if we do x&(2^k-1), we will get x%2^k

// Swapping two numbers
// if we do 
// a=a^b, 
// b=a^b, 
// a=a^b, a and b will be swapped

// Finding the number of set bits
// if we do
// while(n){
//     n=n&(n-1);
//     count++;
// }
// count will be the number of set bits in n

// One shot function to find Number of set bits
// if we want to find the number of set bits in n

// if n is INT
// we can do __builtin_popcount(n)

// if n is LONG LONG
// we can do __builtin_popcountll(n)


// One shot function to find the position of the rightmost set bit
// if we want to find the position of the rightmost set bit in n
// we can do __builtin_ctz(n)

// int countTrailingZeroes(int n) {
//     return __builtin_ctz(n);
// }

// One shot function to find the position of the leftmost set bit
// if we want to find the position of the leftmost set bit in n
// we can do 31-__builtin_clz(n)

// int countLeadingZeroes(int n) {
//     return 31-__builtin_clz(n);
// }

// One shot function to find the parity of a number
// if we want to find the parity of n
// we can do __builtin_parity(n)

// One shot function to find the position of the rightmost set bit
// if we want to find the position of the rightmost set bit in n
// we can do __builtin_ffs(n)

// One shot function to find the position of the leftmost set bit
// if we want to find the position of the leftmost set bit in n
// we can do __builtin_clz(n)

// One shot function to find the position of the rightmost unset bit
// if we want to find the position of the rightmost unset bit in n
// we can do __builtin_ffs(~n)

// One shot function to find the position of the leftmost unset bit
// if we want to find the position of the leftmost unset bit in n
// we can do __builtin_clz(~n)

