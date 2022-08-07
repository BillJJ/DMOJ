import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MainClass {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String[] inTemp = bf.readLine().split(" ");
		int numRows = Integer.parseInt(inTemp[0]);
		int numColumns = Integer.parseInt(inTemp[1]);
		int[][] sheet = new int[numRows][numColumns];
		
		//fill 2d array with [row index, row stuff]
		for(int i = 0; i < numRows; i++) {
			
			String[] fill = bf.readLine().split(" ");
			for(int j = 0; j < numColumns; j++) {
				sheet[i][j] = Integer.parseInt(fill[j]);
			}
		}
		
		//go through each sort command
		int sortCommands = Integer.parseInt(bf.readLine());
		for (int i = 0; i < sortCommands; i++) {
			
			//sort using the column number, going through each index
			//j = row to move
			int sortBy = Integer.parseInt(bf.readLine()) - 1;
			
			for(int j = 1; j < numRows; j++) {
				
				//for each column number sort it in it's place
				//k = j-1, always
				for(int k = j - 1; k > -1; k--){
				
					//if k[sortyBy] > j[sortBy], move j to k's spot.
					if(sheet[k][sortBy] > sheet[k + 1][sortBy]) {
						
						//test later if swapping keys would be much faster
						int[] temp = sheet[k];
						sheet[k] = sheet[k + 1];
						sheet[k + 1] = temp;
						int a = 1;
					}
					//if they are the same value or less, then it has been successfully sorted
					else {
						break;
					}
					
				}
				
			}
		}
		
		
		for(int i = 0; i < numRows; i++) {
			for(int j = 0; j < numColumns - 1; j++) {
				
				System.out.print(sheet[i][j] + " ");
			}
			System.out.println(sheet[i][numColumns - 1]);
			
		}
		
		bf.close();
		
	}
	
}