package Exercicio07;

public class ContaException extends RuntimeException {
    private String msg;
    public ContaException(String msg){
        this.msg = msg;
    }

    public String getMsg() {
        return msg;
    }
}
