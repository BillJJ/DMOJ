import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;
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
		return readInt();
	}
	
	public static class Point{
		public int r;
		public int c;
		Point(int a, int b){
			r = a;
			c = b;
		}
		public String toString() {
			return "(" + r + ", " + c + ")";
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		int rows = nextInt();
		int cols = nextInt();
		int[][] cell = new int[rows][cols];
		
		for(int i = 0; i < rows; i++)
			for(int j = 0; j < cols; j++)
				cell[i][j] = nextInt();
		
		Queue<Point> queue = new ArrayDeque<Point>();
		Set<Integer> set = new HashSet<Integer>();
		queue.add(new Point(0,0));
		boolean escape = false;
		while(!queue.isEmpty() && !escape) {
			Point p = queue.remove();
			int num = cell[p.r][p.c];
			if(p.r == rows-1 && p.c == cols-1) {
				escape = true;
				break;
			}
			if(num == 0 || set.contains(num))
				continue;
			
			for(int i = 1; i <= Math.sqrt(num); i++) {
				if(num%i == 0) {
					int a = num/i-1;
					int b = i-1;
					if(a < rows && b < cols && cell[a][b] != 0) {
						queue.add(new Point(a, b));
					}
					if(b < rows && a < cols && cell[b][a] != 0) {
						queue.add(new Point(b, a));
					}
				}
			}
			cell[p.r][p.c] = 0;
			set.add(num);
		}
		if(escape)
			System.out.println("yes");
		else {
			System.out.println("no");
		}
	}
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