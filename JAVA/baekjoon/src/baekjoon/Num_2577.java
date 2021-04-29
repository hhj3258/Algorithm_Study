package baekjoon;

import java.util.Scanner;

public class Num_2577 {

	public static void main(String[] args) throws Exception {
		Scanner in=new Scanner(System.in);

		int[] cnt=new int[10];
		int multi=1;
		
		for(int i=0;i<3;i++) 
			multi *= in.nextInt();

		String x=multi +"";
		String[] multi2=x.split("");
		
		int[] a=new int[multi2.length];

		for(int i=0;i<multi2.length;i++) {
			
			a[i]=Integer.parseInt(multi2[i]);

			for(int j=0;j<10;j++) {
				if(a[i] == j) cnt[j]++;
			}
		}
		
		for(int i=0;i<10;i++) {
			System.out.println(cnt[i]);
			
		}
		
		in.close();
	}

}
