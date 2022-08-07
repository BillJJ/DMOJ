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
		
		int ant = nextInt();
		int eyes = nextInt();
		
		if(ant >= 3 && eyes <= 4)
			System.out.println("TroyMartian");
		if(ant <= 6 && eyes >= 2)
			System.out.println("VladSaturnian");
		if(ant <= 2 && eyes <= 3)
			System.out.println("GraemeMercurian");
	}
}