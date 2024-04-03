package baekjoon;

import java.util.Scanner;
public class Num_2884 {
	public static void main(String[] args) {
		Scanner i=new Scanner(System.in);
		int H=i.nextInt();
		int M=i.nextInt();
		M-=45;
		if(M < 0) {
			H--;
			M+=60;
			if(H < 0) H = 23;
		}
		System.out.print(H+" "+M);
	}
}