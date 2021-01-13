package main
import "fmt"

const MOD int64 = 1000000007
var N,M,L int
var W string
var A [300]string
var Now int
var C [2][300][300]int64 // C[Now][i][j] = 현재 단계(사용한 W의 길이)에서 (i,j)로 이동하는 방법의 수
var D [300][300]int64 // D[i][j] = C[0][0]~C[i][j] 영역의 합

func main(){
    fmt.Scanf("%d %d %d\n",&N,&M,&L)
    fmt.Scanf("%s",&W)
    for i:=0; i<N; i++ {
        fmt.Scanf("%s",&A[i])
    }
    
    // 일단 첫 글자(W[0])가 일치하는 곳을 1로 세팅
    Now=0
    for i:=0; i<N; i++ {
        for j:=0; j<M; j++ {
            if A[i][j]==W[0] {
                C[Now][i][j]=1
            } else {
                C[Now][i][j]=0
            }
        }
    }

    for k:=1; k<len(W); k++ { // W[1~len(W)-1]에 대해서...

        // 현재 상태의 C 배열에 대한 이차원 합 계산
        D[0][0]=C[Now][0][0]
        for i:=1; i<N; i++ {
            D[i][0]=(D[i-1][0]+C[Now][i][0])%MOD
        }
        for j:=1; j<M; j++ {
            D[0][j]=(D[0][j-1]+C[Now][0][j])%MOD
        }
        for i:=1; i<N; i++ {
            for j:=1; j<M; j++ {
                D[i][j]=(D[i-1][j]+D[i][j-1]-D[i-1][j-1]+MOD+C[Now][i][j])%MOD
            }
        }
        
        // for debug
        if false{
            fmt.Printf("After W[%d]:\n", k-1)
            for i:=0; i<N; i++ {
                for j:=0; j<M; j++ {
                    fmt.Printf("%d ",C[Now][i][j])
                }
                fmt.Printf("\n")
            }
        }
        
        // 현재 문자(W[k])를 반영하여 C 배열 업데이트
        Now=1-Now
        for i:=0; i<N; i++ {
            for j:=0; j<M; j++ {
                // TODO
                C[Now][i][j]=0
                if A[i][j]==W[k] {
                    if i>=2 && j>=2 {
                        C[Now][i][j]=(C[Now][i][j]+D[i-2][j-2]-C[1-Now][i-2][j-2]+MOD)%MOD
                    }
                    if i>=2 && j+2<M {
                        C[Now][i][j]=(C[Now][i][j]+D[i-2][M-1]-D[i-2][j+1]+MOD-C[1-Now][i-2][j+2]+MOD)%MOD
                    }
                    if i+2<N && j>=2 {
                        C[Now][i][j]=(C[Now][i][j]+D[N-1][j-2]-D[i+1][j-2]+MOD-C[1-Now][i+2][j-2]+MOD)%MOD
                    }
                    if i+2<N && j+2<M {
                        C[Now][i][j]=(C[Now][i][j]+D[N-1][M-1]-D[i+1][M-1]+MOD-D[N-1][j+1]+MOD+D[i+1][j+1]-C[1-Now][i+2][j+2]+MOD)%MOD
                    }
                }
            }
        }
    }

    // for debug
    if false {
        fmt.Printf("After W[%d]:\n", L-1)
        for i:=0; i<N; i++ {
            for j:=0; j<M; j++ {
                fmt.Printf("%d ",C[Now][i][j])
            }
            fmt.Printf("\n")
        }
    }

    // 답 계산
    var Ans int64
    Ans=0
    for i:=0; i<N; i++ {
        for j:=0; j<M; j++ {
            Ans=(Ans+C[Now][i][j])%MOD
        }
    }
    fmt.Println(Ans)
}