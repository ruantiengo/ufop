public class Exercicio4 {
    public static void main(String[] args) {
        Pais br = new Pais("BRA","Brazil","210.000.000","8.516.000");
        Pais arg = new Pais("ARG","Argentina","210.000.000","8.516.000");
        Pais ven = new Pais("VEN","Venezuela","210.000.000","8.516.000");
        Pais par = new Pais("PAR","Paraguai","210.000.000","8.516.000");
        br.paisesFronteiras.add(arg);
        br.paisesFronteiras.add(ven);
        br.paisesFronteiras.add(par);
        System.out.println(arg.verificaFronteira(br));
        br.mostraFronteira();
    }
}
