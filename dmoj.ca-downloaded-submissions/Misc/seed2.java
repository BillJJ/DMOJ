import java.io.IOException;
import java.io.InputStream;

public class MainClass {
	
	public static void main(String[] args) throws IOException {
		double base = (int)Math.pow(10, 9);
		double next = base;
		print(base);
		String input = "";
		int times = 0;
		while(!(input = readLine()).equals("OK")) {
			next /= 2;
			base += input.equals("FLOATS") ? -(next) : next;
			print(base);
		}
		print(base);
	}
	public static void print(double i) {
		System.out.println(Math.round(i));
		System.out.flush();
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
}