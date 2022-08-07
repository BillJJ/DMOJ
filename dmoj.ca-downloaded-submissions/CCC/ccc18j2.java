import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        int N, counter=0;
        //input
        Scanner in = new Scanner(System.in);
        N = Integer.parseInt(in.nextLine());
        String y = in.nextLine(), t = in.nextLine();

        //data processing
        for (int i=0; i<y.length(); i++) {
            if (y.charAt(i) == t.charAt(i) && y.charAt(i) == 'C') {
                counter++;
            }
        }
        System.out.println(counter);
    }
}