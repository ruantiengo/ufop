import java.util.Scanner;

public class Matriz {
    int linhas,colunas;
    int matriz[][];

    public Matriz(int linhas,int colunas){
        this.linhas = linhas;
        this.colunas = colunas;
        matriz = new int[linhas][colunas];
    }

    public int getLinhas(){
        return linhas;
    }
    public int getColunas() {
        return colunas;
    }

    public void preencheMatriz(){
        Scanner leitor = new Scanner(System.in);
        for(int i=0;i<linhas;i++){
            for (int j=0;j<colunas;j++){
                matriz[i][j] = leitor.nextInt();
            }
        }
    }
    public void editaValor(int linha,int coluna){
        Scanner leitor = new Scanner(System.in);
        matriz[linha][coluna] = leitor.nextInt();
    }
    public void transporMatriz(){
        if(linhas == colunas) {
            int matriz2[][] = new int[colunas][linhas];
            for (int i = 0; i < linhas; i++) {
                for (int j = 0; j < colunas; j++) {
                    matriz2[j][i] = matriz[i][j];
                }
            }
            matriz = matriz2;
            System.out.println("Matriz transposta com sucesso");
        }
        if(linhas!=colunas){
            System.out.println("A matriz não é quadrada");
        }
    }
    public void imprimeMatriz(){
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                System.out.print(matriz[i][j]);
            }
            System.out.print("\n");
        }
    }

}
