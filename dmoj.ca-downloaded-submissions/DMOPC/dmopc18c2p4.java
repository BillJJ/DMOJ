import java.io.IOException;
import java.io.InputStream;

public class MainClass {
	
	public static void main(String[] args) throws IOException {
		int n = readInt();
		int[] arr = new int[n];
		long m = readLong();
		int l = 0, r = 0;
		int smallest = Integer.MAX_VALUE;
		long sum = 0;
		for(int i = 0; i < n; i++) {
			arr[i] = readInt();
			if(sum < m) {
				sum += arr[r];
				r++;
			}while(sum >= m && l < r) {
				if(r-l < smallest) {
					smallest = r-l;
				}
				sum -= arr[l];
				l++;
				}
			}
		if(smallest != Integer.MAX_VALUE)
			System.out.println(smallest);
		else
			System.out.println(-1);
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