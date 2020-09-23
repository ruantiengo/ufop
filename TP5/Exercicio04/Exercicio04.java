package Exercicio04;

public class Exercicio04 {
    public static void main(String[] args) {
        Cachorro fred = new Cachorro("Fred");
        Gato milu = new Gato("Milu");
        System.out.println(fred.latir()+milu.miar());
        fred.caminha();
        milu.caminha();
    }
}
