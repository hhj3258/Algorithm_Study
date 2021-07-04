package baekjoon;

import java.util.*;
public class Num_10250 {
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		
		int C=in.nextInt();
		
		int H[] = new int[C];
		int W[] = new int[C];
		int N[] = new int[C];
		
		for(int i=0;i<C;i++) {
			H[i]=in.nextInt();
			W[i]=in.nextInt();
			N[i]=in.nextInt();
		}
		
		for(int k=0;k<C;k++) 
		{
			int arr[][]=new int[W[k]][H[k]];
			int cnt=0;
			
			for(int i=0;i<W[k];i++) 
			{
				for(int j=0;j<H[k];j++) 
				{
					cnt++;
					if(cnt == N[k])
					{
						if(i < 9)
							System.out.println((j+1)+"0"+(i+1));
						else
							System.out.println((j+1)+""+(i+1));
					}
				}
			}
		}
	}
}