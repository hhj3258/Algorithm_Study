package baekjoon;

import java.util.Scanner;
public class Num_10996 {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int num=in.nextInt();
		for(int i=0;i<num*2;i++) {
			if(i%2 == 0) {
				for(int j=0;j<num;j++) {
					if(j%2 == 0) System.out.print("*");
					if(j%2 == 0 && j<num-2) System.out.print(" ");
				}
			}
			else {
				for(int j=0;j<num;j++) {
					if(j%2 != 0) System.out.print("*");
					if(j%2 == 0 && j<num-1) System.out.print(" ");
				}
			}
			if(i<num*2-1 && num != 1) System.out.println();
		}
	}
}