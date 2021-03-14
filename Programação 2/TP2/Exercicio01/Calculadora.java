import java.util.Scanner;

public class Calculadora {
    private double resultado;
    private double a,b;
    private char operador;
    public void imprimeResultado(){
        System.out.println(resultado);
    }
    public Calculadora(double numA,char sinal,double numB) {
        a = numA;
        b = numB;
        operador = sinal;
        switch (operador) {
            case '+':
                resultado = a+b;
                break;
            case  '-':
                resultado = a-b;
                break;
            case '*':
                resultado = a*b;
                break;
            case '/':
                resultado = a/b;
                break;
        }
    }
}
