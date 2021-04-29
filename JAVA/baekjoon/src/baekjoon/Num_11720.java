package baekjoon;

import java.io.*;

public class Num_11720 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int a=Integer.parseInt(br.readLine());
		String arr[]=new String[a];
		
		arr=br.readLine().split("");
		
		int sum=0;
		for(int i=0;i<a;i++)
			sum +=Integer.parseInt(arr[i]);
		
		System.out.println(sum);
	}

}
