import java.util.ArrayList;
import java.util.List;

public class Pais {
        private String codigo;
        private String nome;
        private String populacao;
    private String dimensao;
    public List<Pais> paisesFronteiras = new ArrayList<Pais>(3);

    public String getCodigo() {
        return codigo;
    }

    public String getDimensao() {
        return dimensao;
    }

    public void setDimensao(String dimensao) {
        this.dimensao = dimensao;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }


    public String getPopulacao() {
        return populacao;
    }

    public void setPopulacao(String populacao) {
        this.populacao = populacao;
    }

    public boolean verificaFronteira(Pais x) {
        if (paisesFronteiras.contains(x)) {
            return true;
        }
        return false;
    }

    public String mostraDensidade() {
        return getPopulacao();
    }


    public void mostraFronteira() {
        for(int i=0;i<paisesFronteiras.size();i++){
            System.out.println(paisesFronteiras.get(i).nome);
        }
    }
    public void addPaisAFronteira(Pais x){
        this.paisesFronteiras.add(x);
    }

    public Pais(String codigo,String nome,String populacao,String dimensao){
        this.codigo = codigo;
        this.nome = nome;
        this.populacao = populacao;
        this.dimensao = dimensao;
    }
}
