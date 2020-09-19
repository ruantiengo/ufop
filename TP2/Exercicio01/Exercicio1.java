import java.util.List;

public class Exercicio1 {
    public static void main(String[] args) {
        Calculadora calculadora = new Calculadora(5,'+',3);
        calculadora.imprimeResultado();
        Calculadora calculadora2 = new Calculadora(5,'-',3);
        calculadora2.imprimeResultado();
        Calculadora calculadora3 = new Calculadora(5,'*',3);
        calculadora3.imprimeResultado();
        Calculadora calculadora4 = new Calculadora(5,'/',3);
        calculadora4.imprimeResultado();
    }
}
