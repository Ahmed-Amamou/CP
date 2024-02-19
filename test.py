n,m = map(int, input().split())
numbers = [int(m) for m in input().split()]
sorted_numbers = sorted(numbers)
min_diff = sorted_numbers[n-1] - sorted_numbers[0]
for i in range(m-n):
    diff = sorted_numbers[i + n] - sorted_numbers[i]
    if diff < min_diff:
        min_diff = diff
print(min_diff)
