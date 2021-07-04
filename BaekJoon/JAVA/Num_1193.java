package baekjoon;

import java.util.Scanner;
public class Num_1193 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int input=in.nextInt();
		int cnt=0;
		int max = 0;
		
		while( max < input) 
			max += ++cnt;
		
		if(cnt%2 == 0) {
			int up= cnt + input - max;
			int down= 1 + max - input;
			System.out.println(up+"/"+down);
		}
		if(cnt%2 != 0) {
			int up= max - input + 1;
			int down = cnt + input - max;
			System.out.println(up+"/"+down);
		}
		
	}
}