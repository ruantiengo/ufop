package Exercicio05;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Questao2 {
    public static void main(String[] args) {
        while (true) {
            Scanner teclado = new Scanner(System.in);
            System.out.println("Eu sei dividir");
            try {
                System.out.println("Informe o primeiro valor");
                int x = teclado.nextInt();
                System.out.println("Informe o segundo valor");
                int y = teclado.nextInt();
                double r = (x/y);
                System.out.println("O resultado é " + r);
                System.exit(1);
            } catch (InputMismatchException o){
                System.out.println("ERRO- Insira apenas numeros inteiros");
            } catch (ArithmeticException o){
                System.out.println("ERRO- O numero não pode ser divido por 0");
            }
        }
    }

}
