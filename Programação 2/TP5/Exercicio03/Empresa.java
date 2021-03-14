package Exercicio03;

public class Empresa {
    private String name,adress,city,state,CEP,telephone;
    public Empresa(){}

    public Empresa(String name, String adress, String city, String state, String CEP, String telephone) {
        this.name = name;
        this.adress = adress;
        this.city = city;
        this.state = state;
        this.CEP = CEP;
        this.telephone = telephone;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getCEP() {
        return CEP;
    }

    public void setCEP(String CEP) {
        this.CEP = CEP;
    }

    public String getTelephone() {
        return telephone;
    }

    public void setTelephone(String telephone) {
        this.telephone = telephone;
    }


    public void showInfo() {
        System.out.println("Empresa{" +
                "name='" + name + '\'' +
                ", adress='" + adress + '\'' +
                ", city='" + city + '\'' +
                ", state='" + state + '\'' +
                ", CEP='" + CEP + '\'' +
                ", telephone='" + telephone + '\'' +
                '}');
    }
}
