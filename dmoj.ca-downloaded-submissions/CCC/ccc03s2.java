import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class MainClass {
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int numVerse = Integer.parseInt(br.readLine());
		
		//go through each poem verse
		for(int i = 0; i < numVerse; i++) {
			
			String[] scheme = new String[4];
			
			//go through each line and add the rhyme
			for(int j = 0; j < 4; j++) {
				
				String[] wholeLine = (br.readLine().split(" "));
				String rhyme = wholeLine[wholeLine.length - 1];
				rhyme = rhyme.toLowerCase();
				if (rhyme.contains("a"))
					rhyme = rhyme.substring(rhyme.lastIndexOf("a"));
				if (rhyme.contains("e"))
					rhyme = rhyme.substring(rhyme.lastIndexOf("e"));
				if (rhyme.contains("i"))
					rhyme = rhyme.substring(rhyme.lastIndexOf("i"));
				if (rhyme.contains("o"))
					rhyme = rhyme.substring(rhyme.lastIndexOf("o"));
				if (rhyme.contains("u"))
					rhyme = rhyme.substring(rhyme.lastIndexOf("u"));
				scheme[j] = rhyme;
				
			}
			
			if(scheme[0].equals(scheme[1]) && scheme[1].equals(scheme[2]) && scheme[2].equals(scheme[3]))
				System.out.println("perfect");
			
			else if(scheme[0].equals(scheme[1]) && scheme[2].equals(scheme[3]))
				System.out.println("even");
			
			else if(scheme[0].equals(scheme[2]) && scheme[1].equals(scheme[3]))
				System.out.println("cross");
			
			else if(scheme[0].equals(scheme[3])&&scheme[1].equals(scheme[2]))
				System.out.println("shell");
			else
				System.out.println("free");
		}

		br.close();
	}
	
	
}