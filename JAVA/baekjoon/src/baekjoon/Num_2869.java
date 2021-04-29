package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Num_2869 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

		String arr[]=br.readLine().split(" ");
		int a=Integer.parseInt(arr[0]);
		int b=Integer.parseInt(arr[1]);
		int v=Integer.parseInt(arr[2]);
		
		int d=0;
		if((v-b)%(a-b) == 0)
			d=(v-b)/(a-b);
		else
			d=(v-b)/(a-b)+1;
		System.out.print(d);
	}
}
