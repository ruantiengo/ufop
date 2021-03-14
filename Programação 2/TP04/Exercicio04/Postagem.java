import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Postagem {
    private int id;
    private String titulo;
    private String texto;
    private LocalDate dataPublicacao;
    Scanner leitor = new Scanner(System.in);
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");


    public int getId() {
        return id;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getTexto() {
        return texto;
    }

    public LocalDate getDataPublicacao() {
        return dataPublicacao;
    }

    public Postagem(int id, String titulo, String texto, String dataPublicacao) throws ParseException {
        this.id = id;
        this.titulo = titulo;
        this.texto = texto;
        this.dataPublicacao = LocalDate.parse(dataPublicacao,formatter);
    }

    public Postagem(){

    }
    private void escreveTitulo(){
        System.out.printf("Titulo: ");
        this.titulo = leitor.nextLine();
    }
    private void escreveTexto(){
        System.out.printf("Texto: ");
        this.texto = leitor.nextLine();
    }
    private void escreveDataPublicacao(){
        System.out.printf("Data Publicação: ");
        String data = leitor.nextLine();
        System.out.println(data);
        this.dataPublicacao = LocalDate.parse(data,formatter);
    }

    public void escrevePublicacao(){
        escreveTitulo();
        escreveTexto();
        escreveDataPublicacao();
    }


}
