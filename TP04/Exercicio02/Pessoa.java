import javax.xml.crypto.Data;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Pessoa {
    private String nome;
    private String materia;
    private Date dataCadastro;
    private Universidade universidade;
    private Departamento departamentoTrabalho;

    SimpleDateFormat sdf1= new SimpleDateFormat("dd/MM/yyyy");

    public String getNome() {
        return nome;
    }

    public Universidade getUniversidade() {
        return universidade;
    }

    public Date getDataCadastro() {
        return dataCadastro;
    }

    public void setDepartamentoTrabalho(Departamento departamentoTrabalho) {
        this.departamentoTrabalho = departamentoTrabalho;
    }

    public void setMateria(String materia) {
        this.materia = materia;
    }

    public void setUniversidade(Universidade universidade) {
        this.universidade = universidade;
    }

    public static void relatorio(Pessoa pessoa) {
        System.out.println(pessoa.nome+" trabalhou como professor de "+pessoa.departamentoTrabalho.getNome()+" em "+pessoa.universidade.getNome()+".");
    }

    public Pessoa(String nome, String data) throws ParseException {
        this.nome = nome;
        this.dataCadastro = sdf1.parse(data);
        materia = null;
    }
}
