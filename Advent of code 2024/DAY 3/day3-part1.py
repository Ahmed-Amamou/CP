# i have a long string and I need to extract exactly the parts
# that have a regex like mul(x,y) where x and y are integers (of max 3 digits)
import re

with open('day3-part1.txt') as f:
    text = f.read()
    
pattern = r'mul\((\d{1,3}),(\d{1,3})\)'
matches = re.findall(pattern, text)
sum = 0
with open('day3-part1-out.txt', 'w') as f:
    for match in matches:
        sum+=int(match[0])*int(match[1])
    f.write(str(sum))

# for match in matches:
#     print(match)
