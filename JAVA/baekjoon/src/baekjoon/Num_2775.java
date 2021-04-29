package baekjoon;

import java.util.Scanner;

public class Num_2775 {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int arr[][]=new int[15][15];

		int test=in.nextInt();
		int result[]=new int[test];
		for(int k=0;k<test;k++) {
			int floor=in.nextInt();
			int room=in.nextInt();
			

		for(int i=1;i<=room;i++) 
			arr[0][i]=i;

		for(int i=1;i<=floor;i++) {
			for(int j=1;j<=room;j++) {
				if(j==1) arr[i][j]=1;
				else arr[i][j]=arr[i][j-1] + arr[i-1][j];
			}
		}
		
		result[k]=arr[floor][room];
		}
		
		for(int i=0;i<test;i++)
			System.out.println(result[i]);
	}
}