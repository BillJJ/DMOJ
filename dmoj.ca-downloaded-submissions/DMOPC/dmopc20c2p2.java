import java.io.IOException;
import java.io.InputStream;
import java.lang.System;
import java.util.ArrayList;
import java.util.Scanner;



public class charArray {

	public static void main(String[] args) throws IOException {
		int n = readInt(), numRels = readInt();
		int[][] scarf = new int[1000005][2];
		for(int i = 1 ; i < n+1; i++) {
			int a = readInt();
			if(scarf[a][0] == 0) {
				scarf[a][0] = i;
			}
			if(scarf[a][1] < i) {
				scarf[a][1] = i;
			}
		}
		int largest = 0;
		for(int i = 0;i < numRels; i++) {
			int fc = readInt(), lc = readInt();
			int l = scarf[fc][0];
			int r = scarf[lc][1];
			if(l == 0 || r == 0) {
				continue;
			}
			int length = r - l + 1;
			if(largest < length)
				largest = length;
		}
		System.out.println(largest);
		
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