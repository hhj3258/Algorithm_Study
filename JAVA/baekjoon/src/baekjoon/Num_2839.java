package baekjoon;

import java.util.Scanner;
public class Num_2839 {
	public static void main(String args[]) {
		Scanner in=new Scanner(System.in);
		
		int n=in.nextInt();
		int e=n%10;
		int a[]= {0,2,4,1,3,0,2,4,1,3};
		int cnt=-1;
		
		for(int i=0;i<10;i++) {
			if(e == i) {
				int five=n-3*a[i];
				if(five%5 == 0 && five > -1) {
					five /= 5;
					cnt=five+a[i];
				}
			}
		}
		
		System.out.println(cnt);
	}
}