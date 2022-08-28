def bot_score(n):
    return int((n+4)/5)

for t in range(int(input())):
    n = int(input())
    print(f'Case #{t+1}: {bot_score(n)}')
