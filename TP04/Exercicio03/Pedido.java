import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

public class Pedido {
    private float valor_total;
    private LinkedList<ItemPedido> itensPedidos = new LinkedList<ItemPedido>();

    public void adicionarItem(ItemPedido itemPedido){
        valor_total += itemPedido.getValorItem();
        itensPedidos.add(itemPedido);
    }

    public void imprimirPedido(){
        System.out.println("Codigo           Quantidade           Valor Unidade");
        int tam = itensPedidos.size();
        for(int i=0;i<tam;i++){
            System.out.println(itensPedidos.get(i).getProduto().getCodigo()+"                  "
                    +itensPedidos.get(i).getQuantidade()+"                   "
                    +itensPedidos.get(i).getProduto().getValor());
        }
        System.out.println("\n Valor total: "+obterTotal());

    }
    public float obterTotal(){
        return valor_total;
    }
}
