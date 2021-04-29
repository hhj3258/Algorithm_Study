package baekjoon;

import java.io.*;

public class Num_2908 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String num[]=br.readLine().split(" ");
		
		String reverse1="";
		String reverse2="";
		
		for(int i=0;i<3;i++) {
			reverse1 += num[0].charAt(2-i);
			reverse2 += num[1].charAt(2-i);
		}
		
		int x = Integer.parseInt(reverse1);
		int y = Integer.parseInt(reverse2);
		
		if(x > y)
			System.out.println(x);
		else
			System.out.println(y);
	}

}
