package baekjoon;

import java.util.*;
public class Num_4344 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		
		int n=in.nextInt();
		int avg[] = new int[n];
		double result[]=new double[n];

		for(int i=0;i<n;i++) {
			int n2=in.nextInt();
			int[] x=new int[n2];
			int sum=0;
			for(int j=0;j<n2;j++) {
				x[j]=in.nextInt();
				sum +=x[j];
			}
			
			avg[i]=sum/n2;
			int cnt=0;
			
			for(int j=0;j<n2;j++) 
				if(avg[i]<x[j]) 
					cnt++;

			result[i]=(cnt*1.0)/n2*100;
		}

		for(int i=0;i<n;i++) {
			System.out.printf("%.3f",result[i]);
			System.out.println("%");
		}
	}
}
