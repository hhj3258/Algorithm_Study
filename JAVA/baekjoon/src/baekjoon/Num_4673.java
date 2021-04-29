package baekjoon;

public class Num_4673 {

	static int arr[]=new int[10000];
	static int ne[]=new int[10100];
	
	public static void main(String[] args) {

		for(int j=0;j<10000;j++) {
			arr[j]=j;
			d(j);
		}

		for(int i=0;i<10000;i++) {
			if(arr[i] != ne[i])
				System.out.println(arr[i]);
		}
	}

	public static void d(int n) {
		int value = n;
		while(n > 0) {
			value += n % 10;
			n /= 10;
		}
		ne[value]=value;
	}
}
