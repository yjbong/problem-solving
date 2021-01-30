import sys
 
N, M = map(int, input().split())
rows=N
cols=N
# rows*cols 크기의 2차원 배열 생성
A = [[0 for _ in range(cols)] for _ in range(rows)]
D = [[0 for _ in range(cols)] for _ in range(rows)]
 
# A 입력
for i in range(rows):
    #A[i] = list(map(int, input().split()))
    A[i] = list(map(int, sys.stdin.readline().rstrip().split()))
 
# DP
D[0][0]=A[0][0]
for j in range(1,cols):
    D[0][j] = D[0][j-1]+A[0][j]
for i in range(1,rows):
    D[i][0] = D[i-1][0]+A[i][0]
for i in range(1, rows):
    for j in range(1, cols):
        D[i][j] = D[i-1][j]+D[i][j-1]-D[i-1][j-1]+A[i][j]
 
# M개의 쿼리를 처리
for i in range(M):
    #x1, y1, x2, y2 = map(int, input().split())
    x1, y1, x2, y2 = map(int, sys.stdin.readline().rstrip().split())
    x1=x1-1; y1=y1-1; x2=x2-1; y2=y2-1
    ans = D[x2][y2]
    if x1>0 and y1>0:
        ans = ans-D[x1-1][y2]-D[x2][y1-1]+D[x1-1][y1-1]
    elif x1>0:
        ans = ans-D[x1-1][y2]
    elif y1>0:
        ans = ans-D[x2][y1-1]
    print(ans)