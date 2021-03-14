package Exercicio01e02;

public class Lampada {
    private boolean on,halfLit;
    private int count;
    private float luminosity,energy;
    private static int numInstances;

    private void makeLuminosity(){
        if (luminosity==0){
            on = false;
            halfLit = false;
        }
        if(luminosity==100){
            on = true;
            halfLit = false;
            count++;
        }
        if(luminosity>0 && luminosity<100){
            on = false;
            halfLit = true;
        }
    }
    public void informLuminosity(float luminosity){
        this.luminosity = luminosity;
        makeLuminosity();
    }

    public int howManyTimeWasOn(){
        return count;
    }

    public boolean isOn(){
        if(on == true){
            return true;
        }
        return false;
    }
    public boolean isEconomical(){
        if(energy<40){
            return  true;
        }
        return  false;
    }

    public static int getNumInstances() {
        return numInstances;
    }

    public Lampada(){
        energy = 60;
        Lampada.numInstances++;

    }
    public Lampada(float energy){
        this.energy = energy;
        Lampada.numInstances++;
    }

    public void setEnergy(float energy) {
        this.energy = energy;
    }
}
