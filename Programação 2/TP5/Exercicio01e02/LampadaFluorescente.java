package Exercicio01e02;

public class LampadaFluorescente extends Lampada {
    private float lenght;
    LampadaFluorescente(float lenght,float energy){
        super.setEnergy(energy);
        this.lenght = lenght;
    }

    public float getLenght() {
        return lenght;
    }
}
