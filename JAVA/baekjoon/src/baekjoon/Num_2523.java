package baekjoon;

import java.util.Scanner;
public class Num_2523 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		
		int num = in.nextInt();
		for(int i=1;i<=num;i++) {
			for(int j=0;j<i;j++) {
				System.out.print("*");
			}
			System.out.println();
		}
		
		for(int i=num-1;i>=1;i--) {
			for(int j=i;j>0;j--) {
				System.out.print("*");
			}
			if(i != 1)
				System.out.println();
		}
		
	}

}
