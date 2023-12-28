# Function to check if the target sum can be achieved
def check_subset_sum(queries):
    bitmask = set()
    bitmask.add(0)

    prefix_sum = 0
    for t, v in queries:
        if t == 1:
            prefix_sum += 2 ** v
            new_elements = set()
            for element in bitmask:
                new_elements.add(element + 2 ** v)
            bitmask.update(new_elements)
        else:
            possible = False
            for element in bitmask.copy():
                if (element + v) <= prefix_sum and (element + v) in bitmask:
                    possible = True
                    break
            if possible:
                print("YES")
            else:
                print("NO")

# Reading input
m = int(input())
queries = []
for _ in range(m):
    ti, vi = map(int, input().split())
    queries.append((ti, vi))

# Process queries
check_subset_sum(queries)
