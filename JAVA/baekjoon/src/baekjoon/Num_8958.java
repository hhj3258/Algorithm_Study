package baekjoon;

import java.io.*;
public class Num_8958 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int n=Integer.parseInt(br.readLine());
		
		String[] x = null;
		int sum[]=new int[n];
		int cnt=0;

		for(int i=0;i<n;i++) {
			x=br.readLine().split("");
			
			for(int j=0;j<x.length;j++) {
				if(x[j].equals("O")) 
					cnt++;
				else
					cnt=0;
				
				sum[i] +=cnt;
			}
			cnt=0;	
		}

		for(int i=0;i<sum.length;i++) 
			System.out.println(sum[i]);

	}
}