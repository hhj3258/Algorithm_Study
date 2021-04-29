package baekjoon;

import java.util.Scanner;
public class Num_5543 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int[] a=new int[5];

		for(int i=0;i<a.length;i++) 
			a[i]=in.nextInt();
		
		int min=2000;
		int min2=2000;
		for(int i=0;i<a.length;i++) {
			if(i<=2) {
				if(a[i]<min)
					min=a[i];
			}
			else{
				if(a[i]<min2)
					min2=a[i];
			}
		}
		int result = min+min2-50;
		System.out.print(result);
	}
}
