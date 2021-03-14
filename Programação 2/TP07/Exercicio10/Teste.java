package Exercicio10;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Teste {
    public static void main(String[] args) {
        Calculator calculator = new Calculator();
        Scanner leitor = new Scanner(System.in);
        try {
            System.out.println("Digite a operação que deseja realizar");
            System.out.println("1- Divisão  ||  2-  Log na base 10");
            int teste = leitor.nextInt();
            if(teste == 1) {
                System.out.println("Digite o valor do numero: ");
                double a = leitor.nextDouble();
                System.out.println("Digite o valor do numero: ");
                double b = leitor.nextDouble();
                System.out.println(calculator.div(a, b));
            }
            if(teste ==2) {
                System.out.println("Digite o valor do numero: ");
                double a = leitor.nextDouble();
                System.out.println(calculator.log10(a));
            }
        }catch (InvalidOperationException o){
            System.out.println("ERRO - InvalidOperationException");
        } catch (InputMismatchException o){
            System.out.println("ERRO - InputMismatchException");
        }

    }
}
