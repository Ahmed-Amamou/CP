def find_color(x, y):
    # Base cases
    if x < 1 or y < 1 or y > x:
        return -1  # Invalid coordinates
    if x == 1 and y == 1:
        return 1  # First point is always red
    
    # Find which step this point belongs to
    step = 1
    size = 1
    while size < x:
        step += 1
        size = size * 2 - 1
    
    # Start from the full triangle of the current step
    # and recursively find which sub-triangle contains our point
    curr_step = step
    curr_x = x
    curr_y = y
    curr_top_x = 1
    curr_top_y = 1
    result = 1  # Start with red (will flip when we enter blue triangle)
    
    while curr_step > 1:
        prev_size = (1 << (curr_step - 1)) - 1  # Size of previous step's triangle
        
        # Check if point is in the bottom inverted (blue) triangle
        if curr_x > prev_size:
            blue_triangle_top_x = prev_size + 1
            blue_triangle_top_y = prev_size + 1
            
            if (curr_x - blue_triangle_top_x < prev_size and 
                curr_y >= blue_triangle_top_y - (curr_x - blue_triangle_top_x) and 
                curr_y <= blue_triangle_top_y + (curr_x - blue_triangle_top_x)):
                result = 1 - result  # Flip color
                break
        
        # If point is in bottom half, determine which sub-triangle
        if curr_x > prev_size:
            if curr_y <= prev_size:  # Left triangle
                curr_x -= prev_size
            elif curr_y > 2 * prev_size:  # Right triangle
                curr_x -= prev_size
                curr_y -= 2 * prev_size
            
        curr_step -= 1
    
    return result

def solve():
    Q = int(input())
    for _ in range(Q):
        x, y = map(int, input().split())
        print(find_color(x, y))

solve()
