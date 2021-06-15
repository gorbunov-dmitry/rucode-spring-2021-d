def generate_partition(n):
    size = n + 1
    matrix = [[0] * size for _ in range(size)]
    matrix[0][0] = 1
    for i in range(size):
        for j in reversed(range(size)):
            if i < j:
                matrix[i][j] = 0
            elif i == j:
                matrix[i][j] = 1
            else:
                matrix[i][j] = matrix[i - j][j] + matrix[i][j + 1]
    return matrix


n, p = map(int, input().split())

matrix = generate_partition(n)

if p >= matrix[n][0]:
    print('N/A')
    quit()

result = []
last = 0
sum = 0

index = n

for _ in range(n):
    for d in range(1, n + 1):

        if d < last:
            continue

        if sum + d == n:
            sum += d
            result += [d]
            last = d
            break

        foo = matrix[index - d][d]

        if p < foo:
            sum += d
            result += [d]
            last = d
            index -= d
            break

        if p >= foo:
            p = max(p - foo, 0)

    if sum == n:
        break

print(len(result))
print(*result)
