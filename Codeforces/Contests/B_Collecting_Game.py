from itertools import accumulate
import bisect


t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    sorted_l = sorted(l)

    # Preprocess the sorted list
    cum_sum = [0] + list(accumulate(sorted_l))

    res = []
    for i, num in enumerate(l):
        # Binary search for the minimum element
        left, right = 0, n - 1
        while left <= right:
            mid = (left + right) // 2
            if sorted_l[mid] >= num:
                right = mid - 1
            else:
                left = mid + 1

        # Calculate the maximum number of removable elements
        count = 0
        score = num
        while score >= num:
            count += 1
            # Check if score exceeds the cumulative sum to avoid IndexError
            if score > cum_sum[-1]:
                break
            # Use bisect_left to find the element to remove
            left = bisect_left(cum_sum, score)
            score -= sorted_l[left]

        res.append(count)

    print(*res)
