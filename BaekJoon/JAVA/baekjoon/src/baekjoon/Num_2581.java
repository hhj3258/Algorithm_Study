package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Num_2581 {

	public static void main(String[] args) throws Exception {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int m=Integer.parseInt(br.readLine());
		int n=Integer.parseInt(br.readLine());
		int sum=0;
		
		int cnt=0, cnt2=0;
		for(int i=m;i<=n;i++) {
			sum += mycal(i);
			if(mycal(i) >1) cnt++;
		}
		int arr[] = new int[cnt];
		for(int i=m;i<=n;i++) {
			if(mycal(i) > 1)
				arr[cnt2++]=mycal(i);
		}
		
		if(sum != 0) {
			System.out.println(sum);
			System.out.println(arr[0]);
		}
		else
			System.out.println("-1");
		
	}
	public static int mycal(int a) {
		int b=2;
		while(b<=a){
			int c=a%b;
			
			if(c == 0 && b<a) { break; }
				
			if(c == 0 && b==a)
				return a;
			b++;
		}
		return 0;
	}
}
