package baekjoon;

import java.util.Scanner;
public class Num_2562 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int max=0;
		int index=0;
		int[] arr=new int[9];

		for(int i=0;i<9;i++)
			arr[i]=in.nextInt();

		for(int i=0;i<9;i++) {
			if(arr[i]>max) {
				max=arr[i];
				index=i;
			}
		}

		System.out.println(max);
		System.out.println(index+1);
	}
}
