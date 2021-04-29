package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Num_15552 {

	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw=new BufferedWriter(new OutputStreamWriter(System.out));

		int A=Integer.parseInt(br.readLine());

		for(int i=0;i<A;i++) {
			String[] s = br.readLine().split(" ");
			bw.write(Integer.parseInt(s[0])+Integer.parseInt(s[1])+"\n");
		}
		bw.flush();
		bw.close();
	}

}
