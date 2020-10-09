package Exercicio03;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Comparator;
import java.util.Date;

public class Funcionario implements Comparable<Funcionario>{
    private Integer id;
    private String nome;
    private double salario;
    private LocalDate date;
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

    public Funcionario(Integer id, String nome, double salario, String date) throws ParseException {
        this.id = id;
        this.nome = nome;
        this.salario = salario;
        this.date = LocalDate.parse(date,formatter);
    }

    public String getNome() {
        return nome;
    }

    // POR DATA
     @Override
    public int compareTo(Funcionario o) {
        if(this.date.isAfter(o.date)){
            return 1;
        }
        if (this.date.isBefore(o.date)){
            return -1;
        }
        return 0;
    }

    //METODO PARA COMPARAÇÃO POR NOME (ALFABETICO)
    /*@Override
    public int compareTo(Funcionario o) {
        return this.nome.compareTo(o.nome);
    }
*/


    // METODO PARA ORDENAÇÃO POR SALARIO
   /* @Override
    public int compareTo(Funcionario o) {
        if(this.salario>o.salario){
            return 1;
        }
        if(this.salario<o.salario){
            return -1;
        }
        return 0;
    }*/


}
