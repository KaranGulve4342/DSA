// GFG
/*
class Solution{
public:
    // function to return the minimum cost of connecting the ropes

    long long minCost(long long arr[], long long n){
        // create a min heap

        priority_queue<long long, vector<long long>, greater<long long> >pq;
        long long cost = 0;

        for(int i = 0;i < n;i++){
            pq.push(arr[i]);
        }

        while(pq.size() > 1){
            long long a = pq.top();
            pq.pop();

            long long b = pq.top();
            pq.pop();

            long long sum = a + b;
            cost += sum

            pq.push(sum);
        }
        return cost;
    }
}
*/