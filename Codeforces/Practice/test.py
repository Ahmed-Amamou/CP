num_intervals = int(input())
intervals = [tuple(map(int, input().split())) for _ in range(num_intervals)]

intervals.sort()

solution_found = False
best_start1, best_start2 = None, None

for i in range(1, num_intervals):

    start1_min = max(start for start, end in intervals[:i])
    start1_max = min(end for start, end in intervals[:i])

    start2_min = max(start for start, end in intervals[i:])
    start2_max = min(end for start, end in intervals[i:])

    if start1_min <= start1_max and start2_min <= start2_max and start1_max < start2_min:
        if not solution_found or (start1_min < best_start1 or (start1_min == best_start1 and start2_min < best_start2)):
            best_start1, best_start2 = start1_min, start2_min
            solution_found = True

if solution_found:
    print(best_start1, best_start2)
else:
    print(-1)
# Read space-separated integers into a list
# numbers = list(map(int, input().split()))
# print(numbers)