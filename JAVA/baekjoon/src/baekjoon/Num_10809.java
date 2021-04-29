package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Num_10809 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int ascii[]=new int[26];
		int key[]=new int[26];
		int abc=97;
		
		String str[]=br.readLine().split("");
		
		for(int i=0;i<26;i++) {
			ascii[i]=abc++;	//97~122ÀÇ ¹è¿­
			key[i]=-1;
		}

		int par[]=new int[str.length];
		
		for(int i=0;i<str.length;i++) {
			int x=str[i].charAt(0);
			par[i]=(int)x;
		}

		for(int i=0;i<par.length;i++) {
			for(int j=0;j<26;j++) 
				if(ascii[j]==par[i]) 
					if(key[j]==-1)
						key[j]=i;
		}
		
		for(int i=0;i<26;i++)
			System.out.print(key[i]+" ");

	}
}
