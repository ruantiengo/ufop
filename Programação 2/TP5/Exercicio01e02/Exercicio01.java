package Exercicio01e02;

public class Exercicio01 {
    public static void main(String[] args) {
       Lampada lampada = new LampadaFluorescente(50,39);
       lampada.informLuminosity(100);
        System.out.println(lampada.isOn());
    }
}
