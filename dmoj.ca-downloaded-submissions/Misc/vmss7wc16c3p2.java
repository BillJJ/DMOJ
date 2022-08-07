import java.util.*;
import java.io.*;

public class Main2 {
	
	static List<Integer>[] adj;
	static boolean[] vis;
	
	public static void dfs(int curr) {
		vis[curr] = true;
		for(int next : adj[curr]) {
			if(!vis[next]) {
				dfs(next);
			}
		}
	}
	public static void main(String[] args) throws IOException {
			
		int m, n, a, b;
		n = readInt(); m = readInt(); a = readInt(); b = readInt();
		
		adj = new List[n+1];
		for (int i = 0; i <= n; i++)
		      adj[i] = new ArrayList<Integer>();
		
		for(int i = 0; i < m; i++) {
			int u = readInt(), v = readInt();
			adj[u].add(v);
			adj[v].add(u);
		}
				
		vis = new boolean[n+1];
		
		dfs(a);
		
		if(vis[b]) {
			System.out.println("GO SHAHIR!");
		}
		else {
			System.out.println("NO SHAHIR!");
		}
		
	}

	//my thanks to whoever made this super fast input
	private static final int BUFFER_SIZE = 1 << 16;
	private static final InputStream in = System.in;
	private static final byte[] buffer = new byte[BUFFER_SIZE];
	private static int bufferPointer = 0, bytesRead = 0;

	public static String read() throws IOException {
		byte[] ret = new byte[1024];
		int idx = 0;
		byte c = Read();
		while (c <= ' ') {
			c = Read();
		}
		do {
			ret[idx++] = c;
			c = Read();
		} while (c != -1 && c != ' ' && c != '\n' && c != '\r');
		return new String(ret, 0, idx);
	}

	public static long readLong() throws IOException {
		long ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');
		if (neg)
			return -ret;
		return ret;
	}
	public static String readLine() throws IOException {
		final StringBuilder sb = new StringBuilder(1024);
		byte c = Read();
		while (c == '\n' || c == '\r') {
			c = Read();
		}
		do {
			sb.append((char) c);
			c = Read();
		} while (c != -1 && c != '\n' && c != '\r');
		return sb.toString();
	}
	
	private static void fillBuffer() throws IOException {
		bytesRead = in.read(buffer, bufferPointer = 0, BUFFER_SIZE);
		if (bytesRead == -1)
			buffer[0] = -1;
	}

	private static byte Read() throws IOException {
		if (bufferPointer == bytesRead)
			fillBuffer();
		return buffer[bufferPointer++];
	}

	public static int readInt() throws IOException {
		int ret = 0;
		byte c = Read();
		while (c <= ' ')
			c = Read();
		boolean neg = (c == '-');
		if (neg)
			c = Read();
		do {
			ret = ret * 10 + c - '0';
		} while ((c = Read()) >= '0' && c <= '9');

		if (neg)
			return -ret;
		return ret;
	}
}