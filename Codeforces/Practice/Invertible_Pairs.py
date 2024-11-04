def max_subarray_sum(arr):
    max_ending_here = max_so_far = arr[0]
    for x in arr[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    
    T = int(data[0])
    index = 1
    results = []
    
    for _ in range(T):
        N = int(data[index])
        A = list(map(int, data[index + 1:index + 1 + N]))
        index += 1 + N
        
        # Try flipping each pair once and keep the best result
        current_max = float('-inf')
        best_array = A[:]
        
        # First try without any flips
        current_max = max_subarray_sum(A)
        
        # Try flipping each pair individually and see if it improves the total max subarray sum
        for i in range(0, N, 2):
            # Create a new array with this pair flipped
            temp_array = A[:]
            temp_array[i] = -temp_array[i]
            temp_array[i+1] = -temp_array[i+1]
            
            max_sum = max_subarray_sum(temp_array)
            if max_sum > current_max:
                current_max = max_sum
                best_array = temp_array[:]
        
        # Try flipping pairs in combination
        for i in range(0, N, 2):
            for j in range(i+2, N, 2):
                temp_array = best_array[:]
                temp_array[i] = -temp_array[i]
                temp_array[i+1] = -temp_array[i+1]
                temp_array[j] = -temp_array[j]
                temp_array[j+1] = -temp_array[j+1]
                
                max_sum = max_subarray_sum(temp_array)
                if max_sum > current_max:
                    current_max = max_sum
                    best_array = temp_array[:]
        
        results.append(str(current_max))
    
    sys.stdout.write("\n".join(results) + "\n")

solve()