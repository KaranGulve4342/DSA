// CODEFORCES 1000 RATED

#include <cstdio>
#include <map>

int main() {
    long t; 
    scanf("%ld", &t);

    while(t--) {
        long n; 
        scanf("%ld", &n);

        std::map<long, long> a, b;
        long prev = -1, cur = 0;

        // Reading the first sequence and updating map 'a'
        for(long p = 0; p < n; ++p) {
            long x; 
            scanf("%ld", &x);
            if(x != prev) {
                if(prev > 0 && (a.count(prev) == 0 || a[prev] < cur)) {
                    a[prev] = cur;
                }
                cur = 0;
            }
            ++cur; 
            prev = x;
        }
        if(a.count(prev) == 0 || a[prev] < cur) {
            a[prev] = cur;
        }

        prev = -1; cur = 0;

        // Reading the second sequence and updating map 'b'
        for(long p = 0; p < n; ++p) {
            long x; 
            scanf("%ld", &x);
            if(x != prev) {
                if(prev > 0 && (b.count(prev) == 0 || b[prev] < cur)) {
                    b[prev] = cur;
                }
                cur = 0;
            }
            ++cur; 
            prev = x;
        }
        if(b.count(prev) == 0 || b[prev] < cur) {
            b[prev] = cur;
        }

        long mx = 0;

        // Find the maximum value by combining maps 'a' and 'b'
        for(const auto& entry : a) {
            long key = entry.first;
            long val = entry.second;
            if(key > 0 && b.count(key)) {
                val += b[key];
            }
            if(val > mx) {
                mx = val;
            }
        }
        
        for(const auto& entry : b) {
            long key = entry.first;
            long val = entry.second;
            if(key > 0 && a.count(key)) {
                val += a[key];
            }
            if(val > mx) {
                mx = val;
            }
        }

        printf("%ld\n", mx);
    }

    return 0;
}
