/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:40:29 by cmoura-p          #+#    #+#             */
/*   Updated: 2024/08/26 20:24:35 by cmoura-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_init(t_node **a, char **argv);
static bool check_input(int ac, char **av);

int main(int argc, char **argv)
{
    // Declarar 2 ponteiros de t_node para a pilha A e pilha B
    // E inicializar com NULL para evitar comportamento inesperado
    t_node   *stack_a;
    //t_node   *stack_b;

    stack_a = NULL;
    //stack_b = NULL;

    // Entao vamos lidar com erros de input
    // AC tem que ser maior ou igual a 2 e AV nao pode ser vazio
    if (argc == 1)
        return (0);
    if (argc == 2 && !argv[1][0])
    {
        ft_printf("ARGUMENT ERROR \n");
        return(0);
    }

    // Se AV for um unico argumento, ou seja, uma string,
    // tem que chamar o split
    if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else
        argv = argv + 1;

    // Verificamos erros nos valores inputados
    // So pode haver numeros ou '-' ou '+'
    // o numero nao pode ser maior que o INT_MAX
    // nem menor que o INT_MIN (#include <limits.h>)
    // tambem nao pode haver duplicados
    if (!check_input(argc, argv)) // ta' funcionando
        return(0);

    // DUVIDA GIGANTE!!!
    // O QUE ACONTE COM O RETURN DO CHECK_INPUT QUANDO HA ERRO???
    // (PERGUNTEI AO GPT E ELE CONFIRMOU QUE EXECUTA A STACK_INIT DE QQ MANEIRA)
    // Vamos inicializar a stack A
    stack_init(&stack_a, argv);


    if (!stack_ordered(stack_a))
    {
        if (stack_len(stack_a) == 2)        // se tem apenas dois nos faz um swap de A se necessario
            sa(&stack_a, false);
        else if(stack_len(stack_a) == 3)    // se tem tres nos executa o short_sort
        	//short_sort(stack_a, stack_b);
            printf("Tem 3 \n");
        else
            //real_sort(stack_a, stack_b);    // tem mais de tres nos parte pro algoritmo
            printf("Tem mais de 3 \n");
    }

    // Por fim de tudo faz free da stack que foi posta em memoria
    stack_freed(&stack_a);

    return(0);
}

static bool check_input(int ac, char **av)
{
    // muito importante lembrar, caso haja erro e fez split,
    // fazer free da pilha
    // Aqui chamamos outras funcoes:
    //      * ft_atol (long numbers)
    //      * ft_printf
    //      * free_argv
    //      * dupli_error
    long nbr;
    int i;

    nbr = 0;
    i = 0;
    while (av[i])
    {
        if (syntax_error(av[i]))
        {
            if (ac == 2)
                free_argv(av);
            ft_printf("SYNTAX ERROR \n");
            return(false);
        }
        nbr = ft_atol(av[i]);
        if ((nbr > INT_MAX || nbr < INT_MIN)
            || (dupli_error(av, nbr, i)))
        {
            if (ac == 2)
                free_argv(av);
            ft_printf("DUPLICITY ERROR \n");
            return(false);
        }
        i++;
    }
    return(true);
}

void    stack_init(t_node **a, char **argv)
{
    long    nbr;
    t_node *aux;
    t_node *new_node;

    while (*argv)
    {
        nbr = ft_atol(*argv);
        new_node = (t_node *) malloc(sizeof(t_node));
        if (!new_node)
        {
            ft_printf("Malloc error \n");
            return;
        }
        new_node->num = (int)nbr;
        new_node->next = NULL;
        if (!*a)
        {
            *a = new_node;
            aux = new_node;
        }
        else
        {
            aux->next = new_node;
            aux = aux->next;
        }
        ++argv;
    }
}

