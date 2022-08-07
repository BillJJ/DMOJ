import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        
		Scanner in = new Scanner(System.in);
		ArrayList<Double> streams = new ArrayList<Double>();
		int initialNum = in.nextInt();
		
		for(int i = 0; i < initialNum; ++i) {
			streams.add((double)in.nextInt());
		}
		
		int action = in.nextInt();
		
		while (action != 77) {
			
			if(action == 99) { 
				int leftStream = in.nextInt() - 1;
				
				double splitToLeftPerc = in.nextDouble() / 100;
				
				double currentPerc = streams.get(leftStream);
				double leftFork = currentPerc * splitToLeftPerc;
				double rightFork = currentPerc - leftFork;
				
				streams.add(leftStream + 1, rightFork);
				streams.add(leftStream, leftFork);
				streams.remove(leftStream+1);
			}
			else if (action == 88){
				int stream1 = in.nextInt() - 1;
				double leftPer = streams.get(stream1);
				streams.remove(stream1);
				
				streams.add(stream1, (leftPer + streams.get(stream1)));
				streams.remove(stream1 + 1);
			}
			
			action = in.nextInt();
		}
		
		for(int i = 0; i < streams.size(); ++i) {
			try{
				if (streams.get(i) == 0)
					throw new ArrayIndexOutOfBoundsException();
				System.out.printf("%s ", Math.round(streams.get(i)));
			} catch (ArrayIndexOutOfBoundsException e) {}
		}
    }
}