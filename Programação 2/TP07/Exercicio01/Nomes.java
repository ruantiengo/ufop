package Exercicio01;

import org.omg.PortableServer.POA;

import java.rmi.server.ExportException;
import java.util.*;

public class Nomes {
    Set<String> nomes = new HashSet<String>();
    Scanner leitor = new Scanner(System.in);

    public void iniciar() {

        while (true) {
            System.out.println("\nDigite o que gostaria de fazer: ");
            System.out.println("\n1- DIGITAR NOME   || 2- REMOVER NOME  || 3- VERIFICAR SE JÁ FOI ARMAZENADO" +
                    "|| 4- IMPRIMIR SET  ||  5- APAGAR TUDO");
            try {
                int opcao = this.leitor.nextInt();
                if (opcao == 1)
                    adicionarNome();
                else if (opcao == 2)
                    removerNome();
                else if (opcao == 3)
                    verificaArmazenado();
                else if (opcao == 5)
                    limpaLista();
                else if (opcao ==4)
                    imprimeNomes();
            } catch (Exception o){
                System.out.println("Entrada invalida");
                System.exit(1);
            }
        }
    }

    private void adicionarNome() {
        System.out.println("\nDigite o nome a ser adicionado: ");
        Scanner leitor2 = new Scanner(System.in);
        String nome = leitor2.nextLine();
        nomes.add(nome);
    }

    private void removerNome() {
        System.out.println("Digite o nome a ser retirado: ");
        Scanner leitor3 = new Scanner(System.in);
        String nome = leitor3.nextLine();
        if (nomes.contains(nome)) {
            nomes.remove(nome);
            System.out.println("O nome "+ nome + " foi retirado com sucesso");
        } else{
            System.out.println("ERRO- O nome não se encontra no set \n");
        }
    }
    private void verificaArmazenado(){
        System.out.println("Digite o nome a ser verificado: ");
        Scanner leitor4 = new Scanner(System.in);
        String nome = leitor4.nextLine();
        if(nomes.contains(nome))
            System.out.println("O nome está no Set");
        else
            System.out.println("ERRO - O nome nao está no Set");
    }
    private void limpaLista(){
        System.out.println("Tem certeza que deseja eliminar os nomes do Set? \n" +
                "1 - SIM       ||      2- NÃO");
        Scanner leitor5 = new Scanner(System.in);
        try{
            int decisao = leitor5.nextInt();
            if(decisao==1){
                nomes.removeAll(nomes);
                System.out.println("Nomes apagados com sucesso");
            }
            else if(decisao==2){
                System.out.println("OK");
            } else {
                System.out.println("O numero digitado não está entre 1 e 2");
            }
        } catch (InputMismatchException o){
            System.out.println("ERRO- Entrada invalida");
        }
    }
    private void imprimeNomes(){
        System.out.println(Arrays.toString(nomes.toArray()));
    }
}
