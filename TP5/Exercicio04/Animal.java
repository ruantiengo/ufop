package Exercicio04;

public class Animal {
    private String nome,raca;

    public Animal(String nome) {
        this.nome = nome;
    }
    public Animal(){}
    public void caminha(){
        System.out.println("O animal caminhou");
    }

    public String getNome() {
        return nome;
    }

    public String getRaca() {
        return raca;
    }
}
