package Exercicio05;

public class VIP extends Ingresso {
    private float valueAdd = 25;
    public VIP(){
        super.setValue(getValue()+valueAdd);
    }


    @Override
    public float getValue() {
        return super.getValue();
    }
}
