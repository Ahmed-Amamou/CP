def max_operations(t, cases):
    results = []
    for l, r in cases:
        # Calculate the number of operations
        max_ops = (r - l + 1) // 3
        results.append(max_ops)
    return results

# Reading input
t = int(input())
cases = [tuple(map(int, input().split())) for _ in range(t)]

# Calculating and printing results
results = max_operations(t, cases)
for result in results:
    print(result)
