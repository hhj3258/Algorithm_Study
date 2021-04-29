package baekjoon;

import java.util.Scanner;
public class Num_1110 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);

		int t = in.nextInt();		//2 6
		int tmp=t;

		int x=t/10;				//a
		int y=t%10;				//b
		
		int cnt=0;
		int a=0;
		int b=0;
		int c=0;
		
		while(true) {
			if(cnt==0) {
				a=x;
				b=y;
				c=a+b;
			}
			a=b;
			b=c%10;
			c=a+b;
			
			int result=a*10+b;
			
			cnt++;
			if(result==tmp)
				break;
		}

		System.out.println(cnt);
	}
}
