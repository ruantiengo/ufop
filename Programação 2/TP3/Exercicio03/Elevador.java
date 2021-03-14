public class Elevador {
    private int totalAndares,andarAtual,capPessoas,pessoasPresentes;

    public int getTotalAndares() {
        return totalAndares;
    }

    public void setTotalAndares(int totalAndares) {
        this.totalAndares = totalAndares;
    }

    public int getAndarAtual() {
        return andarAtual;
    }

    public void setAndarAtual(int andarAtual) {
        this.andarAtual = andarAtual;
    }

    public int getCapPessoas() {
        return capPessoas;
    }

    public void setCapPessoas(int capPessoas) {
        this.capPessoas = capPessoas;
    }

    public int getPessoasPresentes() {
        return pessoasPresentes;
    }

    public void setPessoasPresentes(int pessoasPresentes) {
        this.pessoasPresentes = pessoasPresentes;
    }

    public void Inicializa(int capPessoas, int totalAndares){
        this.capPessoas = capPessoas;
        this.totalAndares = totalAndares;
        setAndarAtual(0);
        setPessoasPresentes(0);
    }
    public void Entra(){
        if(pessoasPresentes<capPessoas){
            setPessoasPresentes(getPessoasPresentes()+1);
        }
    }
    public void Sai(){
        if(pessoasPresentes>=0){
            setPessoasPresentes(getPessoasPresentes()-1);
        }
    }
    public void Sobe(){
        if(andarAtual < totalAndares){
            setAndarAtual(getAndarAtual()+1);
        }
    }
    public void Desce(){
        if(andarAtual>0){
            setAndarAtual(getAndarAtual()-1);
        }
    }
}
