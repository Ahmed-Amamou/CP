# Function to calculate the minimum cost to make the string t good

for test in range(t):
    s = input()
    cost = 0
    n = len(s)
    i = 0
    
    while i < n:
        count = 1
        
        # Count the number of adjacent characters that are the same
        while i < n - 1 and s[i] == s[i + 1]:
            count += 1
            i += 1
        
        # If count is greater than 1, add the excess count to the cost
        if count > 1:
            cost += count - 1
        
        i += 1
    
    print(cost)


# Calculate and print minimum total cost for each test case
