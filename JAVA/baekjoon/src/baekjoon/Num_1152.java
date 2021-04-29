package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Num_1152 {
	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str[]=br.readLine().trim().split(" ");
		int cnt=0;
		for(int i=0;i<str.length;i++) {
			if(str[i].isEmpty()) {
				System.out.print(cnt);
				cnt=1;
			}
		}
		if(cnt != 1)
			System.out.print(str.length);
	}
}