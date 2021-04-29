package baekjoon;

import java.io.*;
public class Num_3052 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int[] num = new int[10];
		
		for(int i=0;i<10;i++) {
			String x=br.readLine();
			num[i]=Integer.parseInt(x)%42;
		}

		int[] key=new int[10];
		int cnt=0;
		
		for(int i=0;i<10;i++) {
			for(int j=i+1;j<10;j++) {
				if(num[i] == num[j])
					key[i]++;
			}
		}
		
		for(int i=0;i<10;i++) 
			if(key[i] != 0)
				cnt++;

		System.out.print(10-cnt);
	}
}
