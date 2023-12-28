

english_letters = "abcdefghijklmnopqrstuvwxyz"
s1 = input().lower()
s2 = input().lower()
p=0
for i in range(len(s1)):
    if english_letters.index(s1[i]) == english_letters.index(s2[i])  :
        p+=1
        continue
    elif english_letters.index(s1[i]) < english_letters.index(s2[i]):
        print(-1)
        break
    else:
        print(1)
        break
if p==len(s1) and s1==s2:
    print(0)