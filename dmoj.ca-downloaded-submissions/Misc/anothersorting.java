import java.io.*;
import java.util.*;

public class MainClass {
	
	private static class SortBoi implements Comparator<String>{

		@Override
		public int compare(String o1, String o2) {
			
			//use last digit to sort in ascending order
			int ones = (o1.charAt(o1.length() -1) - 0) - 
					((o2.charAt(o2.length() -1)) - 0);
			if(ones != 0) {
				return ones;
			}
			else {
				//if both are even, use descending order
				return Integer.parseInt(o2) - Integer.parseInt(o1);
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		String[] array = br.readLine().split(" ");
		
		Arrays.sort(array, new SortBoi());
		
		for(String s : array)
			System.out.print(s + " ");
		
		br.close();
	}
}