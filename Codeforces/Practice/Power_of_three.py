def is_power_of_three(n: str) -> int:
    # Edge cases
    if not n or n == '0':
        return -1
    if n == '1':
        return 0
        
    # Remove leading zeros
    n = n.lstrip('0')
    if not n:
        return -1
        
    # Quick pattern checks
    if n[-1] not in '1379':
        return -1
    
    # Check divisibility by 3 using digital root
    if sum(int(d) for d in n) % 3 != 0:
        return -1
    
    # For very large numbers, use logarithmic method first
    from math import log10
    
    # Calculate approximate exponent using logarithms
    length = len(n)
    first_digit = int(n[0])
    log10_n = (length - 1) + log10(first_digit)
    log10_3 = log10(3)
    approximate_exp = log10_n / log10_3
    
    # If approximate_exp is far from an integer, not a power of 3
    if abs(approximate_exp - round(approximate_exp)) > 0.0001:
        return -1
    
    # For smaller numbers, verify directly
    if length < 19:  # Changed from 100 to handle numbers up to 10^18 safely
        num = int(n)
        count = 0
        while num > 1:
            if num % 3 != 0:
                return -1
            num //= 3
            count += 1
        return count
    
    # For larger numbers, use string division
    def divide_by_three(s):
        result = []
        carry = 0
        for digit in s:
            current = carry * 10 + int(digit)
            result.append(str(current // 3))
            carry = current % 3
        while len(result) > 1 and result[0] == '0':
            result.pop(0)
        return ''.join(result)
    
    # Verify by division
    current = n
    count = 0
    max_iterations = int(approximate_exp) + 2  # Add buffer for precision
    
    while current != '1':
        if count > max_iterations:
            return -1
        if not all(d in '0123456789' for d in current):
            return -1
        old_len = len(current)
        current = divide_by_three(current)
        if current == '0' or (count > 0 and current == n):
            return -1
        count += 1
        
    return count

# Fast I/O
if __name__ == "__main__":
    # Test cases
    assert is_power_of_three("9") == 2    # 3^2 = 9
    assert is_power_of_three("27") == 3   # 3^3 = 27
    assert is_power_of_three("45") == -1  # Not a power of 3
    assert is_power_of_three("243") == 5  # 3^5 = 243
    assert is_power_of_three("1") == 0    # 3^0 = 1
    print(is_power_of_three(input().strip()))