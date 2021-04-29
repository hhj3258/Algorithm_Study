package baekjoon;

import java.util.Scanner;
public class Num_10817 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a=new int[3];
		int max=0;
		int min=100;
		int[] num=new int[2];
		for(int i=0;i<a.length;i++) {
			a[i]=in.nextInt();
			if(a[i]>max) {
				num[1]=i;
				max=a[i];
			}
			if(a[i]<min) {
				num[0]=i;
				min=a[i];
			}
		}
		int result=0;
		for(int i=0;i<a.length;i++) {
			if(i != num[1] && i != num[0]) {
				result = a[i];
			}
		}
		System.out.print(result);
	}
}
