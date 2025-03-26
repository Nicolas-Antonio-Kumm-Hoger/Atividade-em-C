#include <stdio.h>

int main(){
    
    int menu;
    int estq;
    int ctrl_estq(){
        printf("• Itens Disponíveis:\n 101 - Produto A - 50 unidades\n 102 - Produto B - 30 unidades\n 103 - Produto C - 20 unidades\n 104 - Produto D - 15 unidades\n 5. Voltar ao Menu Principal\n");
        scanf("%d", &estq);
        switch(estq){
            case 101:
                printf("1\n");
            default:
                printf("OPÇÃO INVALIDA!\n");
                break;
        }
    }
    int ctrl_vendas(){
        
    }
    int ctrl_finan(){
        
    }
    
    printf("Escolha \n 1)Controle de estoque\n 2)Controle de vendas\n 3)Controle financeiro\n 4)SAIR\n");
    scanf("%d", &menu);
    
    switch(menu){
        case 1:
            ctrl_estq();
            
        case 2:
            ctrl_vendas();
            
        case 3:
            ctrl_finan();
            
        case 4:
            
            
        default:
            printf("OPÇÃO INVALIDA!");
            
    }
    return 0;
}
