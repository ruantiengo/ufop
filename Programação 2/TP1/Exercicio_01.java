public class Exercicio01 {
    public static int negativos(float vet[]){
        int cont = 0;
        for(int i=0;i< vet.length;i++){
            if(vet[i]<0){
                cont++;
            }
        }
        return cont;
    }
}
