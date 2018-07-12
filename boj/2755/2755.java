import java.util.*;
class Main{
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		String tmp = scanner.nextLine();
		int n = Integer.parseInt(tmp);

		double sum=0.0;
		int points = 0;
		for(int i=0; i<n; i++){
			tmp = scanner.nextLine();
			int index = tmp.indexOf(' ');
			int index2 = tmp.lastIndexOf(' ');
			String tmp1 = tmp.substring(0, index);
			String tmp2 = tmp.substring(index+1, index2);
			String tmp3 = tmp.substring(index2+1, tmp.length());

			int point = Integer.parseInt(tmp2);
			points+=point;

			double score = 0.0;
			switch(tmp3.charAt(0)){
				case 'A':
					score = 4.0;
					if(tmp3.charAt(1)=='+') score+=0.3;
					else if(tmp3.charAt(1)=='-') score-=0.3;
					break;
				case 'B':
					score = 3.0;
					if(tmp3.charAt(1)=='+') score+=0.3;
					else if(tmp3.charAt(1)=='-') score-=0.3;
					break;
				case 'C':
					score = 2.0;
					if(tmp3.charAt(1)=='+') score+=0.3;
					else if(tmp3.charAt(1)=='-') score-=0.3;
					break;
				case 'D':
					score = 1.0;
					if(tmp3.charAt(1)=='+') score+=0.3;
					else if(tmp3.charAt(1)=='-') score-=0.3;
			}

			sum+=point*score;
		}
		sum/=points;
		System.out.printf("%.2f\n",sum);
	}
}