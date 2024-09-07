/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:43:47 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/06/29 18:48:57 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    o algoritmo passa da lista A para lista B ate que
    so hajam 3 elementos na lista A
    (obdecendo regras)
    1. faz um pb() dos 2 primeiros elementos de A sem checar nada
    2. os 2 elementos serao o MIN e MAX da pilha B, ate entao
    3. cada elemento da pilha A tem de ter um target node na pilha B
    4. o target node eh o menor mais proximo em B do elemento de A
    5. se nao houver nenhum elemento menor o target node eh o MAX
    6. o que for sendo colocado na pilha B vai em ordem decrescente
    7. para mover para pilha B temos que analisar o "custo do movimento"
        (precisamos encontrar qual o elemento que menos custa mover)
        a formula eh a soma de:
        quantas operacoes para ter o elemento A no topo (da pilha A) +
        quantas operacoes para ter o target node de A no topo (da pilha B)
        (esse eh o push cost)
    8. quando encontrar o "cheapest" elemento de A faz o pb()
    daqui voltamos ao ponto 3. ate que tenhamos apenas 3 elementos na pilha A

    9. com 3 elementos executamos o meu short_sort que com apenas 2 movimentos
       coloca os 3 em ordem crescente

    Agora vamos esvaziar a pilha B
        (o unico requisito para essa etapa eh ter certeza que
        empurramos para a pilha A correta)
        *** lembrar que essa pilha vai em ordem crescente ***
    10. cada elemento da pilha B tem que ter um target node na pilha A
    11. o target node eh o maior mais proximo em A do elemento de B
    12. se nao houver nenhum elemento maior o target node eh o MIN
    13. encontrando o target node fazer os movimentos necessario para entao pa()

    muito importante: antes de fazer os movimentos necessarios
    avaliar se eh "cheapest" fazer rra() ou ra()

    14. encontar o meio a pilha A
        se o target node estiver acima do meio fazer ra()
        se o target node estiver abaixo do meio fazer rra()
    15. quando esvaziar a pilha B confirmar se o menor elemento esta no topo
        e o maior elemento esta no fim da pilha A
    16. procurar onde esta o menor elemento na pilha A e
        se estiver acima do meio fazer ra()
        se estiver abaixo do meio fazer rra()
*/

#include "push_swap.h"

void    real_sort(t_node **a, t_node **b)
{
    int size;

    size = stack_len(*a);
	while (size > 3)
    {
		pb(b, a, false);
        size--;
    }
	short_sort(a);
    set_position(*b);
    set_position(*a);
    set_target(*a, *b);
    set_price(*a, *b);
    find_cheapest(*b);
}

