import java.io.Serializable;

public class Reta {
    float a,b,x,y;
    public Reta(int valorA,int valorB){
        a = valorA;
        b = valorB;
    }
    public boolean verificaPertenceReta(float pontoX,float pontoY) {
        if (calculaY(pontoX) == pontoY ) {
            return true;
        }
        return false;
    }
    public float calculaY(float x){
        y = a*x +b;
        return y;
    }
    public float coeficienteAngular(){
        return a;
    }
    public float coeficienteLinear(){
        return b;
    }
    public void pontoInterseccao(Reta z) {
        float resultadoA, resultadoB, x, y;
        resultadoA = a - z.a;
        resultadoB = -b + z.b;
        x = resultadoB / resultadoA;
        if (resultadoA == 0 && resultadoB == 0) {
            System.out.println("As retas são paralelas");
        } else {
            y = calculaY(x);
            System.out.printf("O ponto é [%.1f][%.1f]", x, y);
        }
    }
}
