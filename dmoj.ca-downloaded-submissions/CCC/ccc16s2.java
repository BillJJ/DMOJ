//java is so bad!!! 

import java.util.*;
import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;

	public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int question = input.nextInt();
        int citizens = input.nextInt();
        int value = 0;
        int value2 = 0;
        int value3 = 0;
        Integer[] Dmojistan = new Integer[citizens];
        Integer[] Pegland = new Integer[citizens];
        for(int i = 0; i < citizens; i++){
            Dmojistan[i] = input.nextInt();
        }
        for(int j = 0; j < citizens; j++){
            Pegland[j] = input.nextInt();
        }
        if(question == 1){
            Arrays.sort(Dmojistan);
            Arrays.sort(Pegland);
            for(int k = 0; k < citizens; k++){
                if(Dmojistan[k] > Pegland[k]){
                    value += Dmojistan[k];
                }
                else{
                    value += Pegland[k];
                }
            }
            System.out.println(value);
        }
        else if(question == 2){
            Arrays.sort(Dmojistan, Collections.reverseOrder());
            Arrays.sort(Pegland);
            for(int l = 0; l < citizens; l++){
                if(Dmojistan[l] > Pegland[l]){
                    value += Dmojistan[l];
                }
                else if(Dmojistan[l] < Pegland[l]){
                    value += Pegland[l];
                }
                else if(Dmojistan[l] == Pegland[l]){
                    value += Pegland[l];
                }
            }
            Arrays.sort(Pegland, Collections.reverseOrder());
            Arrays.sort(Dmojistan);
            for(int q = 0; q < citizens; q++){
                if(Dmojistan[q] > Pegland[q]){
                    value2 += Dmojistan[q];
                }
                else{
                    value2 += Pegland[q];
                }
            }
            if(value > value2){
                System.out.println(value);
            }
            else if(value < value2){
                System.out.println(value2);
            }
            else if(value == value2){
                System.out.println(value);
            }
        }
    }
	
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static char readCharacter() throws IOException {
		return next().charAt(0);
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

}