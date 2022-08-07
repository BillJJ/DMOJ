//java is so bad!!! 

import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	 public static void main(String[] args) throws IOException {
	        int n = readInt();
	        String fromPeg = "A";
	        String toPeg = "C";
	        String tempPeg = "B";
	        hanoi (fromPeg, toPeg, tempPeg, n);
	    }
	    static public void hanoi (String from, String to, String temp, int n) {
	        if (n ==1) {
	            System.out.println(from + to);
	        } else {
	            hanoi (from, temp, to, n-1);
	            System.out.println(from + to);
	            hanoi (temp, to, from, n-1);
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