public class Complex {
    private double parteReal;
    private double parteImaginaria;

    public Complex(){
        parteReal = 0;
        parteImaginaria = 0;
    }
    public Complex(double a, double b){
        parteReal = a;
        parteImaginaria = b;
    }
    public void imprime(){
        System.out.printf("%.1f + %.1f*i", parteReal,parteImaginaria);
    }
    public void somar(Complex z){
        parteReal = parteReal + z.parteReal;
        parteImaginaria = parteImaginaria + z.parteImaginaria;
    }
    public void subtrair(Complex z){
        parteReal = parteReal - z.parteReal;
        parteImaginaria = parteImaginaria - z.parteImaginaria;
    }
    public void multiplicar(Complex z){
        double parteRealFinal, parteImaginariaFinal;
        parteRealFinal = (parteReal * z.parteReal) - (parteImaginaria*z.parteImaginaria);
        parteImaginariaFinal = parteReal*z.parteImaginaria + parteImaginaria*z.parteReal;
        parteReal = parteRealFinal;
        parteImaginaria = parteImaginariaFinal;
    }
    public void divide(Complex z){
        parteReal = parteReal / z.parteReal;
        parteImaginaria = parteImaginaria / z.parteImaginaria;
    }
    public void setParteReal(double parteReal) {
        this.parteReal = parteReal;
    }

    public void setParteImaginaria(double parteImaginaria) {
        this.parteImaginaria = parteImaginaria;
    }
}
