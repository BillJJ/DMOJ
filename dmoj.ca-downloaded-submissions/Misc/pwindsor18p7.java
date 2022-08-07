import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class MainClass {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int numInts = Integer.parseInt(br.readLine());
		
		String[] ints = new String[numInts];
		for(int i = 0; i < numInts; i++) {
			ints[i] = br.readLine();
		}
		Arrays.sort(ints, new Comparator<String>(){
			public int compare(String s1, String s2) {
				return (s2 + s1).compareTo(s1 + s2);
			}
		});
		
		for(String s : ints)
			System.out.print(s);
		br.close();
	}
	
	
}