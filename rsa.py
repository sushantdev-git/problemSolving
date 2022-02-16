p = 11
q = 17

e = 11

n = (p-1)*(q-1)
print(n)

def find_private_key():
    for i in range(1, n):
        print(i, (11*i)%n)
        if((11*i)%n == 1): return i
    
    return -1

print(find_private_key())