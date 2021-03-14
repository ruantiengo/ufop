package Exercicio03;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Random;

public class ExercicioA {
    public static void main(String[] args) {
        ArrayList<Integer> numeros = new ArrayList<Integer>();
        Random generator = new Random();
        for(int i=0;i<50;i++){
            numeros.add(generator.nextInt(100));
        }
        for(int i=0;i<50;i++){
            System.out.print(numeros.get(i)+ " ");
        }
        System.out.println("\n");
        System.out.println(Collections.min(numeros));
        System.out.println(Collections.max(numeros));
        Collections.sort(numeros);
        System.out.println("\n");
        for(int i=0;i<50;i++){
            System.out.print(numeros.get(i)+ " ");
        }
    }

}
