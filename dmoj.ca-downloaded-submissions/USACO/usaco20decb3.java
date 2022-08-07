import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

public class USACO {
	
	
	final static int MM = 1000000005;
	
	public static class Cow{
		int id;
		int x;
		int y;
		int stop = Integer.MAX_VALUE;
		Cow(int id, int x, int y){
			this.id = id;
			this.x = x;
			this.y = y;
		}
		public String toString() {
			return String.format("ID:%d, (%d, %d)", id, x, y);
		}
	}
	
	public static void main(String[] args) throws IOException{ 
		ArrayList<Cow> north = new ArrayList<Cow>(50);
		ArrayList<Cow> east = new ArrayList<Cow>(50);
		int n = readInt();
		
		for(int i = 0; i < n; i++) {
			char dirc = read().charAt(0);
			int x = readInt(), y = readInt();
			if(dirc == 'N')
				north.add(new Cow(i, x,y));
			else if(dirc == 'E')
				east.add(new Cow(i, x,y));
		}
		Collections.sort(north, new Comparator<Cow>() {
			public int compare(Cow a, Cow b) {
				if(a == null) return 1;
				else if(b == null) return -1;
				
				return a.x - b.x;
			}});
		Collections.sort(east, new Comparator<Cow>() {
			public int compare(Cow a, Cow b) {
				if(a == null) return 1;
				else if(b == null) return -1;
				return a.y - b.y;
			}});
		
		for(Cow c : north) {
			for(Cow e : east) {
				if(e.x > c.x) continue;
				if(e.y < c.y) continue;
				if(e.stop != Integer.MAX_VALUE) continue;
				
				int moveEast = c.x - e.x;
				int moveNorth = e.y - c.y;
				
				if(moveNorth < moveEast) {
					e.stop = moveEast;
				}
				else if(moveEast < moveNorth) {
					c.stop = moveNorth;
				}
				
				if(c.stop != Integer.MAX_VALUE) break;
			}
		}
		
		north.addAll(east);
		Collections.sort(north, new Comparator<Cow>() {
			public int compare(Cow a, Cow b) {
				return a.id - b.id;
			}});
		for(Cow c : north) {
			System.out.println((c.stop == Integer.MAX_VALUE ? "Infinity" : c.stop));
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