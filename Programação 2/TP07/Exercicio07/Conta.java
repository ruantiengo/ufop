package Exercicio07;

import Exercicio06.ContaException;

public class Conta {
    private double saldo;
    private double limite;


    public double getSaldo() {
        return saldo;
    }

    public void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }

    public void deposita(double valor){
        saldo += valor;
    }
    public void saca (double valor) throws ContaException {
        if(saldo < valor){
            ContaException e = new ContaException("ERRO - Saldo insuficiente para essa operação");
            throw e;
        }
        saldo -= valor;
    }

}
