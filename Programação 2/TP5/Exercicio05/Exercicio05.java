package Exercicio05;

import java.util.Scanner;

public class Exercicio05 {
    public static void main(String[] args) {
        Ingresso ingresso;
        int tipoIngresso,tipoCamarote;
        String localizacao;
        Scanner leitor = new Scanner(System.in);
        System.out.println("COMPRAR INGRESSO");
        System.out.println("DIGITE 1 PARA NORMAL OU 2 PARA VIP");
        tipoIngresso = leitor.nextInt();
        if(tipoIngresso==1){
            ingresso = new IngressoNormal();
            System.out.printf("Valor do ingresso: ");
            System.out.print(ingresso.getValue());
        }
        if(tipoIngresso==2){
            System.out.println("TIPO INGRESSO");
            System.out.println("DIGITE 1 PARA CAMAROTE INFERIOR OU 2 PARA CAMAROTE SUPERIOR");
            tipoCamarote = leitor.nextInt();
            if(tipoCamarote==1){
                ingresso = new CamaroteInferior("A1");
                System.out.printf("Valor do ingresso: ");
                System.out.print(ingresso.getValue());
            }
            if(tipoCamarote==2){
                ingresso = new CamaroteSuperior("C2");
                System.out.printf("Valor do ingresso: ");
                System.out.print(ingresso.getValue());
            }
        }
    }
}
