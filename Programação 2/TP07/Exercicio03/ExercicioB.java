package Exercicio03;

import java.text.ParseException;
import java.util.ArrayList;
import java.util.Collections;

public class ExercicioB {
    public static void main(String[] args) throws ParseException {
        ArrayList<Funcionario> funcionarios = new ArrayList<Funcionario>();
        funcionarios.add(new Funcionario(1,"Ruan",2000,"19/09/2025"));
        funcionarios.add(new Funcionario(1,"Pietro",22000,"19/09/2010"));
        funcionarios.add(new Funcionario(1,"Guilherme",21000,"18/09/2009"));
        funcionarios.add(new Funcionario(1,"Alexandre",21000,"18/09/2020"));
        funcionarios.add(new Funcionario(1,"Abcdario",21000,"18/09/2020"));
        Collections.sort(funcionarios);
        for(int i=0;i<funcionarios.size();i++){
            System.out.println(funcionarios.get(i).getNome());
        }
        System.out.println("\n");
        System.out.println(Collections.max(funcionarios).getNome());
        System.out.println(Collections.min(funcionarios).getNome());
    }

}
