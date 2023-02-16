
def missingWords(s, t):
    s = s.strip().split()
    t = t.strip().split()
    return [word for word in s if word not in t]

s = input()
t = input()
l = missingWords(s, t)
for word in l:
    print(word)