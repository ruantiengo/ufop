import javax.xml.crypto.dsig.spec.XSLTTransformParameterSpec;
import java.util.Scanner;

public class Exercicio2 {
    public static void main(String[] args) {
        Complex operacao1 = new Complex(2,3);
        Complex z1 = new Complex(7,1);
        operacao1.somar(z1);
        operacao1.imprime();

        System.out.println("\n----------------------------------");
        Complex operacao2 = new Complex(5,4);
        Complex z2 = new Complex(2,2);
        operacao2.multiplicar(z2);
        operacao2.imprime();

        System.out.println("\n-----------------------------------");
        Complex operacao3 = new Complex(3,1);
        Complex z3 = new Complex(4,2);
        operacao3.divide(z3);
        operacao3.imprime();
    }
}
