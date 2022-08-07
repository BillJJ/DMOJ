import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A_Block_Game {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st; 
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
 
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		int N = readInt(), K = readInt(), D = readInt();
		double jwkdr = readDouble();
		for(int i=0; i<N; i++) {
			K += readInt();
			D += readInt();
		}
		double lkdr = Double.valueOf(K)/Double.valueOf(D);
		if(D ==0) {
			System.out.println("stop hacking!");
		} else {
			if(lkdr >= jwkdr) {
				System.out.println("Y");
			} else {
				System.out.println("N");
			}
		}
	}

}