package Exercicio09;

public class Teste {
    public static void main(String[] args) throws Exception {
        try {
            someMethod();
        }catch (Exception o){
            o.printStackTrace();
        }
    }
        public static void someMethod() throws Exception {
            try {
                someMethodo2();
            } catch (Exception teste){
                System.out.println("Dentro do metodo 1: ");
                throw teste;
            }
        }
        public static void someMethodo2() throws Exception{
            throw new Exception("Teste");
        }
}
