import java.util.Scanner;

public class jp {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n;
        String jpStatus;

        n = scanner.nextInt();
        jpStatus = scanner.next();

        // Drawing the top part of jam pasir
        for (int i = 0; i < 3+2*(n-1); i++) {
            System.out.print('*');
        }
        System.out.println("");

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(' ');
            }
            System.out.print('*');
            
            if (jpStatus.equals("PENUH")) {
                for (int j = 1; j <= (2*(n-1)-1)-(i-1)*2; j++) {
                    System.out.print(' ');
                }
            } else { // jpStatus.equals("KOSONG")
                for (int j = 1; j <= (2*(n-1)-1)-(i-1)*2; j++) {
                    System.out.print('*');
                }
            }
            System.out.println('*');
        }


        // Drawing the middle of jam pasir
        for (int i = 0; i < n; i++) {
            System.out.print(' ');
        }
        System.out.println('*');

        // Drawing the bottom part of jam pasir
        
        for (int i = n-1; i >= 1; i--) {
            for (int j = 1; j <= i; j++) {
                System.out.print(' ');
            }
            System.out.print('*');
            if (jpStatus.equals("KOSONG")) {
                for (int j = 1; j <= (2*(n-1)-1)-(i-1)*2; j++) {
                    System.out.print(' ');
                }
            } else { // jpStatus.equals("PENUH")
                for (int j = 1; j <= (2*(n-1)-1)-(i-1)*2; j++) {
                    System.out.print('*');
                }
            }
            System.out.println('*');
        }
        
        for (int i = 0; i < 3+2*(n-1); i++) {
            System.out.print('*');
        }
        System.out.println("");
    }
}