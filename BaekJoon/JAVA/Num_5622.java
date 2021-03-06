package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Num_5622 {
	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String tel=br.readLine();
		int temp[]=new int[tel.length()];
		
		for(int i=0;i<tel.length();i++) 
			temp[i]=(tel.charAt(i)-65+1);

		int sum=0;
		for(int i=0;i<tel.length();i++) {
			if(temp[i] <=15) 		temp[i]=((tel.charAt(i)-65)/3)+2;
			else if(temp[i] <=19) 	temp[i]=7;
			else if(temp[i] <=22) 	temp[i]=8;
			else 					temp[i]=9;
		
			sum += temp[i]+1;
			}
		
		System.out.println(sum);
	}
}