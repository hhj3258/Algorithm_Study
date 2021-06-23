package baekjoon;

import java.util.Scanner;
public class Num_1011 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		
		int test=in.nextInt();
		long result[]=new long[test];
		for(int j=0;j<test;j++) {
			
			int x=in.nextInt();
			int y=in.nextInt();
			long distance=y-x;
			long max=0, cnt=0;
			for(int i=1;max<distance;i++) {
				max += (i+1)/2;
				cnt=i;
			}
			result[j]=cnt;
		}
		
		for(int i=0;i<test;i++)
			System.out.println(result[i]);
	}
}