public class Empregado {
    String nome;
    double salario;
    int numHorasTrabalho;
    protected static int contador = 0;
    public Empregado(String nome, double salario){
        this.nome=nome;
        this.salario = salario;
        this.numHorasTrabalho = 8;
        contador++;
    }
    public static int getNumEmpregados(){
        return contador;
    }
    public void printInfo(){
        System.out.printf("Nome: %s \nSalário: %d \nCarga Horaria: %d", nome,salario,numHorasTrabalho);
    }
    public void promocao(double percentual){
        percentual = 1+percentual/100;
        this.salario = this.salario * percentual;
    }
    public void adicionaGratificacao(double extra){
        if(numHorasTrabalho>6){
            this.salario = this.salario + extra;
        }
    }
}
