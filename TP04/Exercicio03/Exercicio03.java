public class Exercicio03 {
    public static void main(String[] args) {
        Produto produto = new Produto(0,150,"Alface");
        Produto produto2 = new Produto(1,50,"Alho");
        ItemPedido itemPedido = new ItemPedido(produto,5);
        ItemPedido itemPedido2 = new ItemPedido(produto2,3);
        Pedido pedido = new Pedido();
        pedido.adicionarItem(itemPedido);
        pedido.adicionarItem(itemPedido2);
        pedido.imprimirPedido();
    }
}
