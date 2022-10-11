f = open('27A.txt')
n = int(f.readline())
a = []
for i in range(n):
    x = int(f.readline())
    a.append(x)
k = 0
for i in range(n):
    for j in range(i+1, n):
        if (a[i]+a[j])==2000:
            k+=1
print(k)
