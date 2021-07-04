package baekjoon;

import java.util.Scanner;
public class Num_1546 {

	public static void main(String[] args) throws Exception {
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		double[] sub=new double[n];
		double sum=0;
		double max=0;
		
		
		for(int i=0;i<n;i++) {
			sub[i]=in.nextDouble();
			if(sub[i] > max)
				max=sub[i];
		}
		
		for(int i=0;i<n;i++) {
			sub[i]=sub[i]/max*100;
			sum+=sub[i];
		}
		
		double avg=sum/n;
		
		System.out.println(avg);

	}

}
