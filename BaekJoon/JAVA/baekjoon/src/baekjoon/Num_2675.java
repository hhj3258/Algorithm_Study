package baekjoon;

import java.util.Scanner;

public class Num_2675 {

	public static void main(String[] args) {
		
		Scanner in=new Scanner(System.in);
		
		int a=in.nextInt();
		String result="";
		
		for(int i=0;i<a;i++) {
			int b=in.nextInt();
			String str1=in.next();
			
			for(int k=0;k<str1.length();k++)
				for(int j=0;j<b;j++)
					result+=str1.charAt(k);
			result+="\n";
		}
		
		System.out.print(result);
	}

}
