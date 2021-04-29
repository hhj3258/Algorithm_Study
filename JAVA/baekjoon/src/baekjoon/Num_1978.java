package baekjoon;

import java.io.*;
public class Num_1978 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int test=Integer.parseInt(br.readLine());
		int arr[]=new int[test];
		String str[]=new String[test];
		int cnt=0;
		str=br.readLine().split(" ");
		
		for(int i=0;i<arr.length;i++) {
			arr[i]=Integer.parseInt(str[i]);
			if(mycal(arr[i])) cnt++;
		}
		System.out.println(cnt);
	}
	
	public static boolean mycal(int a) {
		int b=2;
		while(b<=a){
			
			int c=a%b;
			
			if(c == 0 && b<a) {
				return false;
			}
			if(c == 0 && b==a) {
				//System.out.println("!");
				return true;
			}
			b++;
			//System.out.println("b:"+b);
		}
		//System.out.println("?");
		return false;
	}
	
}
