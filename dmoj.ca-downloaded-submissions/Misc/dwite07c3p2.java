import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MainClass {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb;
	
	public static void needSpace() {
		if(sb.toString().equals(""))
			return;
		if(sb.charAt(sb.length()  - 1) == ' ') {
			return;
		}
		else {
			sb.append(" ");
		}
	}
	public static void main(String[] args) throws IOException {
		for(int i = 0; i < 5; i++) {
			String[] line = (br.readLine()).split("");
			String comment = "";
			String previous = "";
			sb = new StringBuilder();
			sb.append("");
			for(int j = 0; j < line.length; j++) {
				
				if(comment.equals("")) {
					if(previous.equals("/")) {
						if(line[j].equals("/")) {
							comment = "//";
							needSpace();
						}
						else if (line[j].equals("*")) {
							comment = "/*";
							if(!sb.toString().equals("")){
								sb.append(" ");
							}
						}
					}
					else if(line[j].equals("'")) {
						comment = "'";
						needSpace();
					}
					else if(line[j].equals("\"")) {
						comment = "\"";
						needSpace();
					}
				}
				else {
					if(comment.equals("//")) {
						sb.append(line[j]);
					}
					else if("'\"".contains(comment)) {
						if(comment.equals(line[j])) {
							comment = "";
						}
						else {
							sb.append(line[j]);
						}
					}
					else if(comment.equals("/*")) {
						
						if(line[j].equals("/") && previous.equals("*")) {
							comment = "";
							sb.append(" ");
						}
						else if(j == line.length) {
							sb.append(line[j]);
						}
						else if(line[j].equals("*") && line[j + 1].equals("/")) {}
						else {
							sb.append(line[j]);
						}
						
					}
				}
				previous = line[j];
			}
			System.out.println(sb.toString());
		}
	}
}