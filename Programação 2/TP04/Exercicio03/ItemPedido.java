public class ItemPedido {
    private int quantidade;
    private Produto produto;
    private float valorItem;

    public ItemPedido(Produto produto, int quantidade) {
        this.quantidade = quantidade;
        this.produto = produto;
        this.valorItem = quantidade * produto.getValor();
    }


    public float getValorItem() {
        return valorItem;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public Produto getProduto() {
        return produto;
    }
}
