import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class MainClass {
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static int readInt() throws IOException{
		return Integer.parseInt(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	
	static class Require {
		char c; int x, pos;
		Require(char c0, int x0, int p0) {c = c0; x = x0; pos = p0;}
	}
	
	static class cmp implements Comparator<Require>{
		public int compare(Require p, Require q) {
			return Integer.compare(p.pos,  q.pos);
		}
	}
	public static void main(String[] args) throws IOException {
		int n = readInt(), m = readInt();
		char word[] = new char[n];
		int count[] = new int[26], next[] = new int[26];
		
		Require a[] = new Require[m];
		for(int i=0; i<m; i++) {
			char s = readCharacter(); int x = readInt(), pos = readInt()-1;
			a[i] = new Require(s, x, pos);
		}
		Arrays.sort(a, new cmp());
		for(Require e: a) {
			int id = e.c - 'a';
			if(count[id] > e.x) { System.out.println(-1); return;}
			else if (count[id] < e.x) {
				for(int i=next[id]; i<= e.pos && count[id] < e.x; i++) {
					if(word[i] ==0) { word[i] = e.c; count[id]++;}
				}
				if (count[id] <e.x) {System.out.println(-1); return;}
			}
			next[id] = e.pos +1;
		}
		int min = Integer.MAX_VALUE; char c = ' ';
		for(int i=0; i<26; i++) {
			if(min > next[i]) {min = next[i]; c = (char)(i+'a');}
		}
		for(int i=0; i<n; i++) {
			if(word[i] ==0) {
				if(i < min) {System.out.println(-1); return;}
				word[i] =c; min =i+1;
			}
		}
		for (int i=0; i<n; i++) {
			System.out.print(word[i]);
		}
		System.out.println();
	}

}