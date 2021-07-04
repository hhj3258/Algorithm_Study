package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Num_10871 {

 public static void main(String[] args) throws Exception {
  BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
  StringTokenizer st = new StringTokenizer(br.readLine());
  
  int num = Integer.parseInt(st.nextToken());
  int max = Integer.parseInt(st.nextToken());

  st = new StringTokenizer(br.readLine());

  for (int i=0; i<num; i++) {
	  int b = Integer.parseInt(st.nextToken());
	  if (b<max) bw.write(b+" ");
  }
  bw.flush();
  bw.close();
 }
}