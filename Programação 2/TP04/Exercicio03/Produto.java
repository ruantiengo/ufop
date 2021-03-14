import java.util.List;

public class Produto {
    private int codigo;
    private float valor;
    private String descricao;

    public int getCodigo() {
        return codigo;
    }

    public String getDescricao() {
        return descricao;
    }

    public float getValor() {
        return valor;
    }

    public Produto(int codigo, float valor, String descricao) {
            this.codigo = codigo;
            this.valor = valor;
            this.descricao = descricao;
    }
}
