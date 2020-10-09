package Exercicio2;

import java.util.HashMap;
import java.util.Map;

public class Empregado {
    private Map<String,String> empregados = new HashMap<String, String>();

    public void addFuncionario(String id,String nome){
        empregados.put(id,nome);

    }
    public void imprimaFuncionario(String id){
        System.out.println(empregados.getOrDefault(id.toUpperCase(), "Esse Identificador não está cadastrado"));
    }


}
