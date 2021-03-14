import java.text.SimpleDateFormat;
import java.time.Clock;
import java.time.LocalDate;
import java.util.Date;
import java.util.Scanner;

public class Blog {
    private Postagem[] postagens = new Postagem[50];
    private int i =0;
    private int j =0;
    private SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
    private Clock cl = Clock.systemUTC();
    private LocalDate lt = LocalDate.now(cl);
    Scanner leitor = new Scanner(System.in);
    private Usuario[] usuarios = new Usuario[50];

    public void addPostagem(Postagem postagem){
        postagens[i] = postagem;
    }

    public void excPostagem(Postagem postagem) {
        for(int j =0;j<postagens.length;i++){
            if(postagens[j].equals(postagem)){
                postagens[j] = null;
            }
        }
    }
    public void publicarPostagem(Postagem postagem){
        System.out.println(postagem.getTitulo()+"\n"+postagem.getTexto()+"\n"+postagem.getDataPublicacao());
    }
    public void listarPostagensPublicadas(){
        for(int j=0;j<postagens.length;j++){
            if(postagens[j].getDataPublicacao().isBefore(lt))
                System.out.println(postagens[j].getTitulo()+"\n"+postagens[j].getTexto());
        }
    }
    public void listarTodasPostagens(){
        for(int j=0;j<postagens.length;j++){
                System.out.println(postagens[j].getTitulo()+"\n"+postagens[j].getTexto());
        }
    }
    public void cadastrar(){
        System.out.println("Digite o seu login: ");
        usuarios[j].setLogin(leitor.nextLine());
        System.out.println("Digite a sua senha: ");
        usuarios[j].setSenha(leitor.nextLine());
        System.out.println("Digite o seu nome: ");
        usuarios[j].setNome(leitor.nextLine());
    }
    public void logar(){
        String login = leitor.nextLine();
        String senha = leitor.nextLine();
        for(int i=0;i<usuarios.length;i++){
            if(login.equals(usuarios[i].getLogin()) && senha.equals(usuarios[i].getSenha())){
                System.out.println("Bem vindo "+usuarios[i].getNome()+"!");
            } else{
                System.out.println("Usuario Incorreto");
            }
        }
    }


}
