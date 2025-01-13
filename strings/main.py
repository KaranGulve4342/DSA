def minimum_cost_to_make_distinct(T, test_cases):
    results = []

    for t in range(T):
        N = test_cases[t][0]
        S = test_cases[t][1]

        occurences = {}
        for i, val in enumerate(A):
            if val not in occurences:
                occurrencres[val] = [i, i]
            else:
                occurences[val][1] = i

        intervals = []
        for val, (start, end) in occurences.items():
            intervals.append((start, end))

        if not intervals:
            results.append(0)
            continue

        intervals.sort()
        merged_intervals = []
        current_start, current_end = intervals[0]

        for start, end in intervals[1:]:
            if start <= current_end:
                current_end = max(current_end, end)
            else:
                merged_intervals.append((current_start, current_end))
                current_start, current_end = start, end
        merged_intervals.append((current_start, current_end))

        cost = 0
        for start, end in merged_intervals:
            distinct_elements = len(set(A[start:end+1]))
            cost += distinct_elements
        
        results.append(cost)
    
    return results

import sys
input = sys.stdin.read
data = input().split()

T = int(data[0])

test_cases = []
index = 1

for _ in range(T):
    N = int(data[index])
    A = list(map(int, data[index + 1:index + 1 + N]))
    test_cases.append((N, A))
    index += N + 1

results = minimum_cost_to_make_distinct(T, test_cases)
sys.stdout.write('\n'.join(map(str, results)) + '\n')