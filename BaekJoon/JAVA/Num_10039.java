package baekjoon;

import java.util.Scanner;
public class Num_10039 {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int[] a=new int[5];
		int sum=0;
		for(int i=0;i<a.length;i++) {
			a[i]=sc.nextInt();
			if(a[i] < 40) a[i]=40;
			sum += a[i];
		}
		int avg = sum/5;
		System.out.print(avg);
	}
}
