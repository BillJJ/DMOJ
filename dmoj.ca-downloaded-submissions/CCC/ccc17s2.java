import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

public class MainClass {
	
	public static void main(String[] args) throws IOException {
		int n = readInt();
		//using Integer because Arrays.sort(int[]) has worst case O(N^2)
		//while Arrays.sort(Object[]) has worst case O(Nlog(n))
		Integer[] arr = new Integer[n];
		for(int i = 0; i < n; i++) {
			arr[i] = readInt();
		}
		Arrays.sort(arr);
		if(n%2 == 0) {
			int half = n/2;
			for(int i = 0; i < half; i++) {
				System.out.print(arr[half - i - 1] + " ");
				System.out.print(arr[half + i] + " ");
			}
		}else {
			int half = n/2;
			System.out.print(arr[half] + " ");
			for(int i = 1; i < half + 1; i++) {
				System.out.print(arr[half + i] + " ");
				System.out.print(arr[half - i] + " ");
			}
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