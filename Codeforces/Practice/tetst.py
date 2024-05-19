text = "hello"
shifts = []
x= 3
shifts = []
for i in range(min(x, len(text))):
    # Shift the text by slicing from i (start of substring) to the end and
    # concatenating it with the beginning up to i (exclusive)
    shifts.append(text[i:] + text[:i])
  
    
print(shifts)