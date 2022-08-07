import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
		Scanner in = new Scanner(System.in);
		
		String t = in.nextLine();
		String s = in.nextLine();
		
		//all cyclic shift possibilities
		String[] allPoss = new String[s.length()];
		allPoss[0] = s;
		
		
		for(int i = 0; (i+1) < s.length(); ++i) 
			allPoss[i + 1] = allPoss[i].substring(1, s.length()) + allPoss[i].substring(0, 1); 
		
        for(String str : allPoss) { 
        	if(t.contains(str)) {
        		System.out.println("yes");
        		return;
        	}
        }
		System.out.println("no");
    }
}