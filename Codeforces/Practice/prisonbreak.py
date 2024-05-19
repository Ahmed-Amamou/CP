def zombie_infection(string):
    result = []
    for char in string:
        if char == 'Z':
            if result and result[-1] == 'H':
                result.append('A')
            else:
                result.append('Z')
        elif char == 'H':
            result.append('H')
            if result and result[-2] == 'Z':
                result[-2] = 'A'
        elif char == 'K':
            result.append('K')
            if result and result[-2] == 'Z':
                result.pop(-2)
        else:
            if result and result[-1] == 'Z':
                result.append('Z')
            else:
                result.append(char)
    return ''.join(result)

# Example usage
input_string = 'AZZHWMZKZAZ'
output_string = zombie_infection(input_string)
print(f"Input: {input_string}")
print(f"Output: {output_string}")
