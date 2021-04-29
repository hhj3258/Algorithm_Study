package baekjoon;

import java.util.Scanner;
public class Num_2446 {

	public static void main(String[] args) throws Exception {
		Scanner in=new Scanner(System.in);
		
		int num =in.nextInt();
		int q=2*num-1;
		int cnt=0;
		for(int i=q;i>=num;i--) {

			for(int k=0;k<cnt;k++) 
				System.out.print(" ");
			for(int j=i-cnt;j>0;j--) 
				System.out.print("*");
			
			cnt++;
			System.out.println();
		}

		cnt--;
		for(int i=num+1;i<=q;i++) {
			cnt--;
			
			for(int k=0;k<cnt;k++) 
				System.out.print(" ");
			for(int j=i-cnt;j>0;j--) 
				System.out.print("*");
			
			if(cnt != 0)
				System.out.println();
		}

	}
}