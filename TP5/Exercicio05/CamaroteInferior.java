package Exercicio05;

public class CamaroteInferior extends VIP {
    private String localizacao;
    private float valorAdd;
    public CamaroteInferior(String localizacao) {
        this.localizacao = localizacao;
    }


    public String getLocalizacao() {
        return localizacao;
    }
    public void showLocalizacao(){
        System.out.println(localizacao);
    }
}
