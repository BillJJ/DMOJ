//java is so bad!!! 

import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter pr = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	static StringTokenizer st;
        
	public static void main(String[] args) throws IOException {
		
		int m = readInt(), n = readInt();
		StringBuilder[] o = new StringBuilder[n + 1];
		for(int i = 1; i <= n; i++) o[i] = new StringBuilder();
		
		Map<Integer, String> map = new TreeMap<Integer, String>();
		while(m-- > 0) {
			int x = readInt(); String y = next();
			map.put(x, y);
		}
				
		for(int k : map.keySet()) {
			for(int i = k; i <= n; i+= k) {
				o[i].append(map.get(k));
			}
		}
		
		for(int i = 1; i <= n; i++) {
			if(o[i].length() < 1) System.out.println(i);
			else System.out.println(o[i].toString());
		}
	  }
        
	static String next () throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong () throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble () throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter () throws IOException {
		return next().charAt(0);
	}
	static String readLine () throws IOException {
		return br.readLine().trim();
	}
   
    
    
}