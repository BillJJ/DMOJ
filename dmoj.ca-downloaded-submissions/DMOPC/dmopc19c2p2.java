import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
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
		return Integer.parseInt(next());
	}
	
	public static class Point{
		public int x;
		public int y;
		Point(int a, int b){
			x = a;
			y = b;
		}
	}
	
	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		int[][] weight = new int[n][m];
		int[][] matrix = new int[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				weight[i][j] = nextInt();
				matrix[i][j] = Integer.MAX_VALUE;
			}
		}
		
		Queue<Point> queue = new ArrayDeque<Point>((int)Math.sqrt(n * n + m * m) + 1);
		queue.add(new Point(0,0));
		matrix[0][0] = weight[0][0];
		while(!queue.isEmpty()){
			Point p = queue.remove();
			if(p.x + 1 != n) {
				int draft = matrix[p.x][p.y] + weight[p.x + 1][p.y];
				if(draft < matrix[p.x + 1][p.y]) {
					matrix[p.x + 1][p.y] = draft;
					queue.add(new Point(p.x + 1, p.y));
				}
			}
			if(p.y + 1 != m) {
				int draft = matrix[p.x][p.y] + weight[p.x][p.y + 1];
				if(draft < matrix[p.x][p.y + 1]) {
					matrix[p.x][p.y + 1] = draft;
					queue.add(new Point(p.x, p.y + 1));
				}
			}
		}
		
		System.out.println(matrix[n-1][m-1]);
	}
}