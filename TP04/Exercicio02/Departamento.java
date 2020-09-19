public class Departamento {
    private String nome;
    private Universidade universidade;

    public String getNome() {
        return nome;
    }

    public void setUniversidade(Universidade universidade) {
        this.universidade = universidade;
    }

    public void MostraUniversidadeAfiliada(){
        System.out.println(this.universidade.getNome());
    }


    public Departamento(String nome) {
        this.nome = nome;
    }

    public Departamento() {
    }
}
