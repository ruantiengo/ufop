package Exercicio10;

import Exercicio06.ContaException;

public class Calculator {
    public double div(double a,double b) throws InvalidOperationException {
        if(b==0){
            throw new InvalidOperationException("ERRO - Impossivel realizar essa operação");
        }
        return a / b;
    }
    public double log10(double numero){
        return Math.log10(numero);
    }
}
