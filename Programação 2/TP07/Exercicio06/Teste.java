package Exercicio06;

public class Teste {
    public static void main(String[] args) {
        Conta conta = new Conta();
        conta.deposita(100);
        conta.setLimite(100);
        try {
            conta.saca(1000);
        } catch (ContaException o){
            System.out.println("ERRO - Saldo para saque insuficiente");
        }
    }
}
