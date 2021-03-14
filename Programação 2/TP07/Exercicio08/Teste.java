package Exercicio08;

import java.util.InputMismatchException;

public class Teste {
    public static void main(String[] args) {
        try {
            provandoMetodo(5, 0);
        } catch (ArithmeticException o){
            o.printStackTrace();
            throw o;
        }
    }
    public static void provandoMetodo(int a , int b){
        try {
            System.out.println(a/b);
        } catch (InputMismatchException o){
            System.out.println("Erro - digite apenas numeros inteiros");
        }
    }
}
