package Exercicio03;

public class Restaurante extends Empresa {
    private String typeFood;
    private float averagePrice;

    public Restaurante(String name, String adress, String city, String state, String CEP, String telephone, String typeFood, float averagePrice) {
        super(name, adress, city, state, CEP, telephone);
        this.typeFood = typeFood;
        this.averagePrice = averagePrice;
    }

    public String getTypeFood() {
        return typeFood;
    }

    public void setTypeFood(String typeFood) {
        this.typeFood = typeFood;
    }

    public float getAveragePrice() {
        return averagePrice;
    }

    public void setAveragePrice(float averagePrice) {
        this.averagePrice = averagePrice;
    }

    @Override
    public void showInfo() {
        super.showInfo();
        System.out.println("Restaurante{" +
                "typeFood='" + typeFood + '\'' +
                ", averagePrice=" + averagePrice +
                '}');
    }
}


