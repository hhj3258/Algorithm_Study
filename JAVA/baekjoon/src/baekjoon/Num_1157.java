package baekjoon;

import java.io.*;
public class Num_1157 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		String[] input=br.readLine().split("");
		int ascii[]=new int[input.length];
		int test[]=new int[91];
		
		for(int i=0;i<91;i++) 
			test[i]=0;
		
		for(int i=0;i<input.length;i++) {
			ascii[i]=input[i].charAt(0);
			
			if(ascii[i] >=97 && ascii[i] <=122)
				ascii[i] -= 32;
			
			test[ascii[i]] += 1;
			
		}
		
		int cnt=0;
		int max=0;
		for(int i=0;i<91;i++) {
			if(max < test[i]) {
				cnt=i;
				max=test[i];
			}
		}
		
		for(int i=0;i<91;i++) {
			if(max == test[i] && cnt != i) {
				
				System.out.println("?");
				cnt=0;
				break;
			}
		}
		
		if(cnt != 0) 
			System.out.println((char)cnt);

	}
}