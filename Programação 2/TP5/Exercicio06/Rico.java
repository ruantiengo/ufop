package Exercicio06;

public class Rico extends Pessoa{
    private double dinheiro;

    private void fazCompras(double dinheiro){
        this.dinheiro -= dinheiro;
    }
}
