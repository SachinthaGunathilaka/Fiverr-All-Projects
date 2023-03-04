package hada;

import java.util.Scanner;

public class Lemain {
	public static void main(String[] args) {
		int rep=0;
		Partie z=new Partie();
		Scanner lect=new Scanner(System.in);
		
		do {
			System.out.println("voulez vous jouer oui(1)");
			rep=lect.nextInt();
			if(rep==1) {
				z.partie();	
			}else System.out.println("okeey à bientôt :)");
		}while (rep==1);
		
		
	}

}
