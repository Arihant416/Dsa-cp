def maxDotProduct(A, B, N):
    A.sort()
    B.sort()
    sum = 0
    for i in range(N):
        sum += (A[i]*B[i])
    return sum


N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
print(maxDotProduct(A, B, N))
