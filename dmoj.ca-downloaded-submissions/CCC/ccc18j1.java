import java.io.*;
import java.util.*;

public class Main {
    public static void main(String ars[]){
    Scanner in = new Scanner(System.in);
        int a = in.nextInt(), b = in.nextInt(), c = in.nextInt(), d = in.nextInt();        
        if((a==8 || a==9) && (d==8 || d==9) && b==c) {
            System.out.println("ignore");
            
        }else {
            System.out.println("answer");
        }
    }
}