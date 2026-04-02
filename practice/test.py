def perform_queries_2(s, queries):
    """
    Performs character replacements using a prefix sum array for frequency tracking.

    Args:
        s: The input string.
        queries: A list of character pairs, where each pair represents a character replacement
                 in the format ['old_char', 'new_char'].

    Returns:
        The final string after all the queries have been performed.
    """

    n = len(s)
    freq = [0] * 26  # Assuming only lowercase English letters

    for c in s:
        freq[ord(c) - ord('a')] += 1

    for old_char, new_char in queries:
        freq[ord(old_char) - ord('a')] -= 1
        freq[ord(new_char) - ord('a')] += 1

    result = []
    for i in range(n):
        for c in range(26):
            if freq[c] > 0:
                freq[c] -= 1
                result.append(chr(c + ord('a')))
                break

    return ''.join(result)
print(perform_queries_2("atcoder",[['r','a'],['t', 'e'],['d', 'v'],['a', 'r']]))


