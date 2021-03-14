public class Exercicio03 {
    public static int recursiva(int n){
        if(n == 1){
            return 1;
        }
        if(n ==2){
            return 2;
        }
        return 2*recursiva(n-1)+3*recursiva(n-2);
    }

    public static void main(String[] args) {
        System.out.println(recursiva(3));
    }
}
