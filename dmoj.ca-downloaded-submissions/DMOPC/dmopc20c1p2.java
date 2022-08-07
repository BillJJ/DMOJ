import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class MainClass {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	
	static int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(next());
	}
	
	public static void main(String[] args) throws IOException {
		int n = nextInt(), d = nextInt();
		int[] trolls = new int[n];
		for(int i = 0; i < n; i++) {
			trolls[i] = nextInt();
		}
		for(int i = 0; i < d; i++) {
			int part = nextInt();
			int sumF = 0, sumS = 0;
			for(int j = 0; j < part; j++)
				sumF += trolls[j];
			for(int j = part; j < trolls.length; j++)
				sumS += trolls[j];
			
			if(sumF >= sumS) {
				System.out.println(sumF);
				trolls = Arrays.copyOfRange(trolls, part, trolls.length);
			} else {
				System.out.println(sumS);
				trolls = Arrays.copyOfRange(trolls, 0, part);
			}
		}
	}
}