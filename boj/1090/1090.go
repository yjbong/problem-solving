package main
import "fmt"
//import "sort"

const INF int = 1111111111
const MAXN int = 50
func Abs(x int) int {
    if x<0 { return -x }
    return x
}
type Point struct {
    y,x int
}
var dest Point
type PointArr [MAXN]Point

func BubbleSort(arr PointArr, N int) PointArr {
    for i:=0; i<N; i++ {
        for j:=0; j<N-1-i; j++ {
            if Abs(dest.x-arr[j].x)+Abs(dest.y-arr[j].y)>Abs(dest.x-arr[j+1].x)+Abs(dest.y-arr[j+1].y){ arr[j], arr[j+1]=arr[j+1], arr[j] }
        }
    }
    return arr
}
var N int
var point [MAXN]Point
var tmp [MAXN]Point
var dist [MAXN+1]int // dist[i]=같은 칸에 체커를 적어도 i개 모으기 위해 필요한 최소 이동 횟수

func main(){
    fmt.Scanf("%d",&N)
    for i:=0; i<N; i++ {
        fmt.Scanf("%d %d",&point[i].x,&point[i].y)
        tmp[i].x=point[i].x
        tmp[i].y=point[i].y
    }
    dist[0]=0
    for i:=1; i<=N; i++ { dist[i]=INF }
    // 선택된(모으기로 한) 점들의 x, y 좌표 상 median으로 이동시키는 것이 거리 합의 최소이다.
    // 즉, 입력에 등장하는 x와 y좌표들만 모이는 위치의 좌표로써 고려하면 된다.
    for i:=0; i<N; i++ {
        for j:=0; j<N; j++ {
            // dest 위치로 체커를 모을 것임
            dest.x=point[i].x
            dest.y=point[j].y

            // 현재 dest(모이는 위치)와 가까운 순서대로 체커의 위치를 sort
            tmp = BubbleSort(tmp, N)

            var curDist int=0
            for k:=0; k<N; k++ {
                curDist=curDist+Abs(dest.x-tmp[k].x)+Abs(dest.y-tmp[k].y)
                // update dist
                if dist[k+1]>curDist { dist[k+1]=curDist }
            }
        }
    }

    // 답 출력
    for i:=1; i<=N; i++ {
        fmt.Printf("%d ",dist[i])
    }
}