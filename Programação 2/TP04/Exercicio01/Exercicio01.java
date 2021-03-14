import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class Exercicio01 {
    public static void main(String[] args) throws ParseException {
        Pessoa einstein = new Pessoa("Albert Einstein","14/3/1879");
        Pessoa newton = new Pessoa("Isaac Newton", " 4/1/1643");
        Universidade princeton = new Universidade("Princeton");
        Universidade cambridge = new Universidade("Cambridge");
        einstein.setUniversidade(princeton);
        einstein.setMateria("Matématica");
        newton.setUniversidade(cambridge);
        newton.setMateria("Física");
        Pessoa.relatorio(einstein);
        Pessoa.relatorio(newton);
    }
}
