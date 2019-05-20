import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
public class Main{
	public static void main (String[] args){
		int T,N;
		Scanner in = new Scanner(System.in);
		T = in.nextInt();

		final int UNKNOWN = 0;
		final int NOT_MEMBER = -1;
		final int MEMBER = 1;

		int next[] = new int[100001];
		int type[] = new int[100001];
		int visited[] = new int[100001];

		for(int tc=1; tc<=T; tc++){
			N=in.nextInt();
			for(int i=1; i<=N; i++) next[i] = in.nextInt();

			Arrays.fill(type, UNKNOWN);
			Arrays.fill(visited, 0);

			for(int i=1; i<=N; i++){
				if(type[i]==UNKNOWN){ // 팀에 속하는지 속하지 않는지 아직 알 수 없는 학생에 대해 
					int cur=i;
					visited[cur]=i; // visited 배열은 각 iteration 번호로 마킹한다. (이렇게 하면 마킹했던 것을 지울 필요가 없음)
					while(true){
						if(type[next[cur]]!=UNKNOWN){ // 이미 팀에 속해 있거나, 또는 팀에 속하지 못하는 학생을 지목한 경우
							int end=next[cur];
							type[i]=NOT_MEMBER;
							for(int j=i; next[j]!=end; j=next[j]) type[next[j]]=NOT_MEMBER;
							break;
						}

						if(visited[next[cur]]==i){ // 사이클(팀)이 구성된 경우
							int loopStart=next[cur];
							if(loopStart==i){ // i번 학생부터 사이클이 구성
								type[i]=MEMBER;
								for(int j=i; next[j]!=i; j=next[j]) type[next[j]]=MEMBER;
							}
							else{ // i번 이후에 사이클이 구성
								type[i]=NOT_MEMBER;
								for(int j=i; next[j]!=loopStart; j=next[j]) type[next[j]]=NOT_MEMBER;

								type[loopStart]=MEMBER;
								for(int j=loopStart; next[j]!=loopStart; j=next[j]) type[next[j]]=MEMBER;
							}
							break;
						}

						cur=next[cur];
						visited[cur]=i;
					}
				}
			}

			int ans=0;
			for(int i=1; i<=N; i++) if(type[i]==NOT_MEMBER) ans++;
			System.out.println(ans);
		}					
	}
}