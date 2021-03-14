import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.Clock;
import java.time.LocalDate;
import java.time.LocalDateTime;

public class Exercicio04 {
    public static void main(String[] args) throws ParseException {
        Blog blog = new Blog();
        blog.cadastrar();
        blog.logar();

    }
}
