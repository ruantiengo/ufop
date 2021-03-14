import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

public class Exercicio02 {
    public static void main(String[] args) throws ParseException {
        Pessoa einstein = new Pessoa("Albert Einstein","14/3/1879");
        Pessoa newton = new Pessoa("Isaac Newton", " 4/1/1643");
        Universidade princeton = new Universidade("Princeton");
        Universidade cambridge = new Universidade("Cambridge");
        Departamento fisicaP = new Departamento("Física");
        Departamento matematicaC = new Departamento("Matemática");
        princeton.add(fisicaP);
        cambridge.add(matematicaC);
        einstein.setUniversidade(princeton);
        einstein.setDepartamentoTrabalho(princeton.getDepartamento(0));
        einstein.setMateria("Matématica");
        newton.setUniversidade(cambridge);
        newton.setDepartamentoTrabalho(cambridge.getDepartamento(0));
        newton.setMateria("Física");
        Pessoa.relatorio(newton);
        for(int i=1;i<50;i++){
            princeton.add(new Departamento());
            cambridge.add(new Departamento());
        }
    }
}
