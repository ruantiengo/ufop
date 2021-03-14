package Exercicio10;

public class InvalidOperationException extends Exception{
    private String message;

    public InvalidOperationException(String msg){
        message = msg;
    }

    @Override
    public String getMessage() {
        return message;
    }
}
