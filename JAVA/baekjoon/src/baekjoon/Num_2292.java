package baekjoon;

import java.util.Scanner;
public class Num_2292 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int six=6;
		int tmp=0;
		int max=1;
		int push=in.nextInt();
		int hexa[] = null;
		int result=0;
		for(int i=0;i<push;i++) {
			max += tmp;
			tmp += six;
			if(push <= max) {
				result=i+1;
				break;
			}
		}
		
		System.out.println(result);
		in.close();
	}

}
