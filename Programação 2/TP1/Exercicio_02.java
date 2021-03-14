import java.util.Scanner;

public class Exercicio02 {
    public static void main(String[] args) {
        int tam;
        System.out.println("Digite o tamanho do vetor");
        Scanner leitor = new Scanner(System.in);
        tam = leitor.nextInt();
        int vet[] = new int[tam];
        preencheVetor(vet);
        primos(vet);
    }
    public static void preencheVetor(int[] vet){
        Scanner leitor = new Scanner(System.in);
        for(int i=0;i< vet.length;i++){
            System.out.printf("Digite o valor da posição %d: ", i);
            vet[i] = leitor.nextInt();;
        }
    }
    public static void primos(int[] vet){
        for(int i=0;i< vet.length;i++){
            if(vet[i] == 1 || vet[i] == 2){
                System.out.printf("O numero %d é primo e está na posição %d \n", vet[i],i);
            }
            else if (veriPrimo(vet[i]) == true){
                System.out.printf("O numero %d é primo e está na posição %d \n", vet[i],i);
            }
        }
    }
    public static boolean veriPrimo(int numero) {
        for (int i = 2; i < numero; i++) {
            if (numero % i == 0)
                return false;
        }
        return true;
    }
}
