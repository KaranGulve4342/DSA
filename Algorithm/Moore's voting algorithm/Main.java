import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Reading the dimentions of the grid
        int n = scanner.nextInt(); // Read the rows
        int m = scanner.nextInt(); // Read the columns
        int count = 0;  // Initializing count with 0
        char[][] arr = new char[n + 1][m + 1]; // Initializing a 2D array to store the characters

        // Taking input
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                arr[i][j] = scanner.next().charAt(0);
            }
        }

        //  vertical pattern
        for (int i = 1; i <= n - 4 + 1; i++) {
            for (int j = 1; j <= m - 1 + 1; j++) {
                char ch1, ch2, ch3, ch4;
                ch1 = arr[i][j];
                ch2 = arr[i + 1][j];
                ch3 = arr[i + 2][j];
                ch4 = arr[i + 3][j];
                if ((ch1 == 's') && (ch2 == 'a') && (ch3 == 'b') && (ch4 == 'a')) {
                    count++;
                }
            }
        }
        // Horizontal pattern
        for (int i = 1; i <= n - 1 + 1; i++) {
            for (int j = 1; j <= m - 4 + 1; j++) {
                char ch1, ch2, ch3, ch4;
                ch1 = arr[i][j];
                ch2 = arr[i][j + 1];
                ch3 = arr[i][j + 2];
                ch4 = arr[i][j + 3];
                if ((ch1 == 's' && ch2 == 'a' && ch3 == 'b' && ch4 == 'a')) {
                    count++;
                }
            }
        }

        // specific diagonal pattern (top-left to bottom-right)
        for (int i = 1; i <= n - 4 + 1; i++) {
            for (int j = 1; j <= m - 4 + 1; j++) {
                char ch1, ch2, ch3, ch4;
                ch1 = arr[i][j];
                ch2 = arr[i + 1][j + 1];
                ch3 = arr[i + 2][j + 2];
                ch4 = arr[i + 3][j + 3];
                if ((ch1 == 's' && ch2 == 'a' && ch3 == 'b' && ch4 == 'a')) {
                    count++;
                }
            }
        }

        // specific diagonal pattern (top-right to bottom-left)
        for (int i = 1; i <= n - 4 + 1; i++) {
            for (int j = 4; j <= m; j++) {
                char ch1, ch2, ch3, ch4;
                ch1 = arr[i][j];
                ch2 = arr[i + 1][j - 1];
                ch3 = arr[i + 2][j - 2];
                ch4 = arr[i + 3][j - 3];
                if ((ch1 == 'a' && ch2 == 'b' && ch3 == 'a' && ch4 == 's')) {
                    count++;
                }
            }
        }

        System.out.println(count); // OUTPUT
    }
}


/*

// INPUT
5 5
s a f e r
a m j a d
b a b o l
a a r o n
s o n g s



 */