package Exercicio05;

public class CamaroteSuperior extends VIP{
    private String localizacao;
    private float valueAdd = 20;
    public CamaroteSuperior(String localizacao) {
        super.setValue(super.getValue()+valueAdd);
        this.localizacao = localizacao;
    }

    @Override
    public float getValue() {
        return super.getValue();
    }
}
