import java.util.Scanner;


public class Betyg {
	public static void main(String[] args) {
		
		int IG=0;
		int medel=0;
		int antalGbetyg=0;
		int betyg=0;
		
		System.out.println("Skriv ett antal betyg (0, 3, 4 eller 5)");
		Scanner scan = new Scanner(System.in);
		while(betyg>=0) {
			
		
		betyg = scan.nextInt();
		
		if(betyg==0) {
			IG++;
			
		}
		
		if(betyg>0) {
			medel=medel+betyg;
			antalGbetyg++;
		}
			
		}
		
		System.out.println("Antal inlästa betyg:" + (antalGbetyg+IG));
		System.out.println("Antalet underkända betyg:" + IG);
		
		if(antalGbetyg>0){
		System.out.println("Medelvärde av de godkända betygen:" + medel/antalGbetyg);
		}
		
		else {
			System.out.println("Ingen fick godkänt, DÅLIGT!");
			
		}
			
		}
		
	}

