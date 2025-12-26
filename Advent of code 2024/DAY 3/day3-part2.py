import re 
with open('day3-part1.txt') as f:
    text = f.read()
    text = "do()" + text + "don't()"
    #split the text into substrings that start with 'do()' and end with 'don't()' 
    pattern = r"do\(\).*?don\'t\(\)"
    matches = re.findall(pattern, text,re.DOTALL)
    sum = 0
    for match in matches:
        mulPattern = r'mul\((\d{1,3}),(\d{1,3})\)'
        mulMatches = re.findall(mulPattern,match)
        for mulMatch in mulMatches:
            sum+=(int)(mulMatch[0])*(int)(mulMatch[1])
    
    print(sum)
