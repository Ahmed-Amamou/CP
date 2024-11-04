MOD = 998244353

def count_valid_ways(N, A, B):
    # Step 1: Determine the set of numbers that are free to place (neither in A nor B)
    all_numbers = set(range(1, 2 * N + 1))
    set_A = set(A)
    set_B = set(B)
    free_numbers = sorted(all_numbers - set_A - set_B)

    # Step 2: Ensure the numbers in A and B are in increasing order for row/column constraints
    A.sort()
    B.sort()

    # Step 3: Count valid placements for free numbers to respect the constraints
    # Count all permutations of placing free numbers while maintaining order in rows and columns
    # Use modular combinatorics to handle placements
    
    # Initialize dp table
    dp = [[0] * (N + 1) for _ in range(N + 1)]
    dp[0][0] = 1

    for i in range(len(free_numbers)):
        next_dp = [[0] * (N + 1) for _ in range(N + 1)]
        for j in range(N + 1):
            for k in range(N + 1):
                if dp[j][k] == 0:
                    continue
                # Place in first row if j < N
                if j < N:
                    next_dp[j + 1][k] = (next_dp[j + 1][k] + dp[j][k]) % MOD
                # Place in second row if k < N
                if k < N:
                    next_dp[j][k + 1] = (next_dp[j][k + 1] + dp[j][k]) % MOD
        dp = next_dp

    # Step 4: Calculate the final result with constraints from A and B
    valid_ways = dp[N - len(A)][N - len(B)]

    return valid_ways

# Input parsing
N = int(input().strip())
X, *A = map(int, input().strip().split())
Y, *B = map(int, input().strip().split())

# Output the result
print(count_valid_ways(N, A, B))
