public class Universidade {
    private String nome;
    private Departamento departamento[] = new Departamento[50];
    private int i = 0;
    public String getNome(){
        return nome;
    }

    public void setDepartamento(Departamento[] departamento) {
        this.departamento = departamento;
    }
    public Departamento add(Departamento dep){
        departamento[i] = dep;
        dep.setUniversidade(this);
        i++;
        return departamento[i-1];
    }

    public Departamento getDepartamento(int i) {
        return departamento[i];
    }

    public Universidade(String nome){
        this.nome = nome;
    }
}
