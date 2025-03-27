#include <stdio.h>

// Variáveis globais
float saldo = 0.00;  // Saldo inicial
float total_vendas = 0;
int total_vendas_realizadas = 0;
int total = 0;

// Categorias de produtos
float total_categoria_A = 0;
float total_categoria_B = 0;
float total_categoria_C = 0;
float total_categoria_D = 0;

// Guarda lugar na memória para não dar erro
void menu_principal();
void menu_estoque();
void menu_financeiro();
void menu_vendas();
float processar_pagamento(float total);

void menu_principal() {
    int opcao;
// "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida
    while(1) {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Controle de Estoque\n");
        printf("2. Controle Financeiro\n");
        printf("3. Vendas\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                menu_estoque(); 
                break;
            case 2: 
                menu_financeiro(); 
                break;
            case 3: 
                menu_vendas(); 
                break;
            case 4:
                printf("\n=== RESUMO FINAL ===\n");
                printf("Vendas realizadas: %d\n", total_vendas_realizadas);
                printf("Faturamento total: R$%.2f\n", total_vendas);
                printf("Saldo atual: R$%.2f\n", saldo);
                printf("=====================\n");
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

void menu_estoque() {
    int opcao;
// "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida
    while(1) {
        printf("\n=== CONTROLE DE ESTOQUE ===\n");
        printf("Itens Disponiveis:\n");
        printf("101. Produto A (50 unid)\n");
        printf("102. Produto B (30 unid)\n");
        printf("103. Produto C (20 unid)\n");
        printf("104. Produto D (15 unid)\n");
        printf("5. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 101: printf("50 unidades disponiveis\n"); break;
            case 102: printf("30 unidades disponiveis\n"); break;
            case 103: printf("20 unidades disponiveis\n"); break;
            case 104: printf("15 unidades disponiveis\n"); break;
            case 5: return;
            default: printf("Opcao invalida!\n");
        }
    }
}

void menu_financeiro() {
    int opcao;
    float valor;
// "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida    
    while(1) {
        printf("\n=== CONTROLE FINANCEIRO ===\n");
        printf("201. Registrar Despesa\n");
        printf("202. Registrar Receita\n");
        printf("203. Consultar Saldo\n");
        printf("6. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 201:
                printf("Valor da despesa: R$");
                scanf("%f", &valor);
                saldo -= valor;
                printf("Despesa registrada. Saldo: R$%.2f\n", saldo);
                break;
            case 202:
                printf("Valor da receita: R$");
                scanf("%f", &valor);
                saldo += valor;
                printf("Receita registrada. Saldo: R$%.2f\n", saldo);
                break;
            case 203:
                printf("Saldo atual: R$%.2f\n", saldo);
                break;
            case 6:
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}

float processar_pagamento(float total) {
    int opcao, status;
    float valor_pago;
// "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida    
    while(1) {
        printf("\n=== FORMA DE PAGAMENTO ===\n");
        printf("Total: R$%.2f\n", total);
        printf("1. Dinheiro (com desconto)\n");
        printf("2. Cartao\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            float desconto = 0;
            if(total <= 50){
                desconto = total * 0.05;
            }else if(total < 100){
                desconto = total * 0.10;
            } 
            else{
                desconto = total * 0.18;
            } 
            
            float total_com_desconto = total - desconto;
            printf("Desconto: R$%.2f\n", desconto);
            printf("Total com desconto: R$%.2f\n", total_com_desconto);
            // "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida
            while(1) {
                printf("Valor recebido: R$");
                scanf("%f", &valor_pago);
                
                if(valor_pago >= total_com_desconto) {
                    printf("Troco: R$%.2f\n", valor_pago - total_com_desconto);
                    return total_com_desconto;
                }
                printf("Valor insuficiente!\n");
            }
        }
        else if(opcao == 2) {
            printf("Pagamento:\n1. Aprovado\n0. Recusado\nStatus: ");
            scanf("%d", &status);
            
            if(status == 1) {
                printf("Pagamento aprovado!\n");
                return total;
            }
            printf("Pagamento recusado!\n");
        }
        else {
            printf("Opcao invalida!\n");
        }
    }
}

void menu_vendas() {
    int opcao, quantidade;
    float total_compra = 0;
    
    // Resetar totais por categoria
    total_categoria_A = 0;
    total_categoria_B = 0;
    total_categoria_C = 0;
    total_categoria_D = 0;
// "while(1)" Faz com que o codigo se repita enquanto nenhuma opção for escolhida
    while(1) {
        printf("\n=== VENDAS ===\n");
        printf("301. Produto A - R$10.00\n");
        printf("302. Produto B - R$20.00\n");
        printf("303. Produto C - R$15.00\n");
        printf("304. Produto D - R$25.00\n");
        printf("5. Finalizar compra\n");
        printf("6. Voltar\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 301:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total_categoria_A += quantidade * 10.00;
                total_compra += quantidade * 10.00;
                printf("Subtotal: R$%.2f\n", quantidade * 10.00);
                break;
            case 302:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total_categoria_B += quantidade * 20.00;
                total_compra += quantidade * 20.00;
                printf("Subtotal: R$%.2f\n", quantidade * 20.00);
                break;
            case 303:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total_categoria_C += quantidade * 15.00;
                total_compra += quantidade * 15.00;
                printf("Subtotal: R$%.2f\n", quantidade * 15.00);
                break;
            case 304:
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                total_categoria_D += quantidade * 25.00;
                total_compra += quantidade * 25.00;
                printf("Subtotal: R$%.2f\n", quantidade * 25.00);
                break;
            case 5:
                if(total_compra > 0) {
                    printf("\n=== RESUMO ===\n");
                    if(total_categoria_A > 0){
                        printf("Produto A: R$%.2f\n", total_categoria_A);
                    } 
                    if(total_categoria_B > 0){
                        printf("Produto B: R$%.2f\n", total_categoria_B);
                    } 
                    if(total_categoria_C > 0){
                        printf("Produto C: R$%.2f\n", total_categoria_C);
                    } 
                    if(total_categoria_D > 0){
                        printf("Produto D: R$%.2f\n", total_categoria_D);
                    } 
                    printf("TOTAL: R$%.2f\n", total_compra);
                    
                    float valor_recebido = processar_pagamento(total_compra);
                    total_vendas += valor_recebido;
                    total_vendas_realizadas++;
                    saldo += valor_recebido;
                    
                    return;
                }
                printf("Nenhum item selecionado!\n");
                break;
            case 6:
                return;
            default:
                printf("Opcao invalida!\n");
        }
    }
}
int main() {
    menu_principal();
    return 0;
}
