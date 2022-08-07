import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
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
		int n = nextInt(), t = nextInt();
		int[] cups = new int[n+1];
		
		for(int i = 0; i < t; i++) {
			int a=nextInt()-1,b=nextInt(),c=nextInt();
			cups[a] += c; cups[b] -= c;
		}
		for(int i = 1; i < n; i++) {
			cups[i] = cups[i] + cups[i-1];
		}
		int l = nextInt();
		int length = 0;
		int sum = cups[0];
		int first = 0, last = 0;
		
		while(first < n) {
			while(first < n && sum <= l) {
				first++;
				sum += cups[first];
			}
			length = Math.max(length, first-last);
			sum -= cups[last];
			last++;
		}
		System.out.println(length);
	}
}