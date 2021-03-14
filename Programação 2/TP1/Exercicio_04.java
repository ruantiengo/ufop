import java.util.Scanner;

public class Exercicio04 {


    public static void main(String[] args) {
        int matriz[][] = new int[10][4];
        preencheMatriz(matriz);
        imprimeMatriz(matriz);
        encontraCR(matriz);
    }
    public static void preencheMatriz(int matriz[][]){
        Scanner leitor = new Scanner(System.in);
        for(int i=0;i<10;i++) {
            int j = 0;
            System.out.println("Digite a matricula (AACCCCNNN): ");
            matriz[i][j] = leitor.nextInt();
            System.out.println("Digite o codigo do sexo: ");
            matriz[i][j+1] = leitor.nextInt();
            System.out.println("Digite o codigo do curso: ");
            matriz[i][j+2] = leitor.nextInt();
            System.out.println("Digite o coefienciente de rendimento: ");
            matriz[i][j+3] = leitor.nextInt();
        }
    }
    public static void encontraCR(int matriz[][]){
        int maior = matriz[0][3];
        for (int i=0;i<9;i++){
            if(matriz[i][3]<matriz[i+1][3]){
                maior = matriz[i+1][3];
                System.out.printf("A aluna de matricula %d, de CR  %d é a premiada", matriz[i+1][1], matriz[i+1][3]);
            }
        }
    }
    public static void imprimeMatriz(int matriz[][]){
        System.out.println("Matricula //   Sexo  //     Curso       //   Coefienciente de Rendimento");
        for (int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                System.out.printf("      %d      ", matriz[i][j]);
            }
            System.out.println("\n");
        }
    }
}
