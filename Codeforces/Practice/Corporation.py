import sys

class Node:
    def __init__(self):
        self.salary_sum = 0
        self.happiness_sum = 0
        self.count = 0
        self.lazy_set = None
        self.lazy_add = 0
        self.prev_value = 0  # Track previous value for happiness calculation

class SegmentTree:
    def __init__(self, n):
        self.n = n
        self.tree = [Node() for _ in range(4 * n)]
    
    def build(self, arr, node, start, end):
        self.tree[node].count = end - start + 1
        if start == end:
            self.tree[node].salary_sum = arr[start]
            self.tree[node].prev_value = arr[start]
            return
            
        mid = (start + end) // 2
        self.build(arr, 2 * node + 1, start, mid)
        self.build(arr, 2 * node + 2, mid + 1, end)
        self.tree[node].salary_sum = (self.tree[2 * node + 1].salary_sum + 
                                    self.tree[2 * node + 2].salary_sum)
        self.tree[node].prev_value = self.tree[2 * node + 1].prev_value  # For leaf nodes only
    
    def push_down(self, node, start, end):
        if start == end:
            return
            
        mid = (start + end) // 2
        left_count = mid - start + 1
        right_count = end - mid
        
        # Handle set operation
        if self.tree[node].lazy_set is not None:
            new_val = self.tree[node].lazy_set
            
            # Update children's salaries
            self.tree[2 * node + 1].salary_sum = new_val * left_count
            self.tree[2 * node + 2].salary_sum = new_val * right_count
            
            # Update happiness based on value change
            for child in [2 * node + 1, 2 * node + 2]:
                old_val = self.tree[child].prev_value
                if new_val > old_val:
                    self.tree[child].happiness_sum = self.tree[child].count
                elif new_val < old_val:
                    self.tree[child].happiness_sum = -self.tree[child].count
                self.tree[child].prev_value = new_val
            
            # Propagate lazy values
            self.tree[2 * node + 1].lazy_set = new_val
            self.tree[2 * node + 2].lazy_set = new_val
            self.tree[2 * node + 1].lazy_add = 0
            self.tree[2 * node + 2].lazy_add = 0
            
            self.tree[node].lazy_set = None
        
        # Handle add operation
        if self.tree[node].lazy_add != 0:
            delta = self.tree[node].lazy_add
            
            # Update children's salaries
            self.tree[2 * node + 1].salary_sum += delta * left_count
            self.tree[2 * node + 2].salary_sum += delta * right_count
            
            # Update happiness based on delta
            for child in [2 * node + 1, 2 * node + 2]:
                if delta > 0:
                    self.tree[child].happiness_sum = self.tree[child].count
                elif delta < 0:
                    self.tree[child].happiness_sum = -self.tree[child].count
                self.tree[child].prev_value += delta
            
            # Propagate lazy values
            self.tree[2 * node + 1].lazy_add += delta
            self.tree[2 * node + 2].lazy_add += delta
            
            self.tree[node].lazy_add = 0

    def update_range_set(self, node, start, end, l, r, val):
        if start > r or end < l:
            return
            
        if start >= l and end <= r:
            old_val = self.tree[node].prev_value
            self.tree[node].salary_sum = val * (end - start + 1)
            if val > old_val:
                self.tree[node].happiness_sum = end - start + 1
            elif val < old_val:
                self.tree[node].happiness_sum = -(end - start + 1)
            self.tree[node].prev_value = val
            self.tree[node].lazy_set = val
            self.tree[node].lazy_add = 0
            return
            
        self.push_down(node, start, end)
        mid = (start + end) // 2
        self.update_range_set(2 * node + 1, start, mid, l, r, val)
        self.update_range_set(2 * node + 2, mid + 1, end, l, r, val)
        self.tree[node].salary_sum = (self.tree[2 * node + 1].salary_sum + 
                                    self.tree[2 * node + 2].salary_sum)
        self.tree[node].happiness_sum = (self.tree[2 * node + 1].happiness_sum + 
                                       self.tree[2 * node + 2].happiness_sum)

    def update_range_add(self, node, start, end, l, r, val):
        if start > r or end < l:
            return
            
        if start >= l and end <= r:
            self.tree[node].salary_sum += val * (end - start + 1)
            if val > 0:
                self.tree[node].happiness_sum = end - start + 1
            elif val < 0:
                self.tree[node].happiness_sum = -(end - start + 1)
            self.tree[node].prev_value += val
            self.tree[node].lazy_add += val
            return
            
        self.push_down(node, start, end)
        mid = (start + end) // 2
        self.update_range_add(2 * node + 1, start, mid, l, r, val)
        self.update_range_add(2 * node + 2, mid + 1, end, l, r, val)
        self.tree[node].salary_sum = (self.tree[2 * node + 1].salary_sum + 
                                    self.tree[2 * node + 2].salary_sum)
        self.tree[node].happiness_sum = (self.tree[2 * node + 1].happiness_sum + 
                                       self.tree[2 * node + 2].happiness_sum)

    def query_range(self, node, start, end, l, r, query_type):
        if start > r or end < l:
            return 0
            
        if start >= l and end <= r:
            return (self.tree[node].salary_sum if query_type == 2 
                   else self.tree[node].happiness_sum)
            
        self.push_down(node, start, end)
        mid = (start + end) // 2
        return (self.query_range(2 * node + 1, start, mid, l, r, query_type) +
                self.query_range(2 * node + 2, mid + 1, end, l, r, query_type))

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def format_fraction(num, den):
    if den < 0:
        num, den = -num, -den
    g = gcd(abs(num), abs(den))
    return f"{num//g}/{den//g}"

def solve(N, Q, initial_salaries, queries):
    tree = SegmentTree(N)
    tree.build(initial_salaries, 0, 0, N-1)
    
    result = []
    for query in queries:
        query_type = query[0]
        l, r = query[1] - 1, query[2] - 1
        
        if query_type == 0:
            tree.update_range_set(0, 0, N-1, l, r, query[3])
        elif query_type == 1:
            tree.update_range_add(0, 0, N-1, l, r, query[3])
        else:
            sum_val = tree.query_range(0, 0, N-1, l, r, query_type)
            count = r - l + 1
            result.append(format_fraction(sum_val, count))
    
    return result

# Fast input processing
input = sys.stdin.readline
N, Q = map(int, input().split())
initial_salaries = list(map(int, input().split()))
queries = [list(map(int, input().split())) for _ in range(Q)]

result = solve(N, Q, initial_salaries, queries)
print("\n".join(result))