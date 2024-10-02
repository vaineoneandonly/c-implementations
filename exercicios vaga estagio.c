#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//exercício 1
int valorDaSoma(int indice)
{
	int soma = 0;
	int k = 0;
	
	while (k < indice)
	{
		++k;
		soma += k;
	}

	return soma;
}

//exercicio 2
const char *fibonacciOuNao(int num)
{
	int fibo[num];
	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= num; ++i) fibo[i] = fibo[i-1] + fibo[i-2];
    	
	for (int j = 0; j < num; ++j) if (fibo[j] == num) return "pertence";

	return "não pertence";
}

//exercicio 4
typedef struct estado
{
	char nomeEstado[2];
	float faturamento;
	struct estado *proximoEstado;	
} estado;

estado *criarEstado(float faturamentoEstado, char nome[2])
{
	estado *novoEstado = malloc(sizeof(estado));
	
	novoEstado -> proximoEstado = NULL;
	novoEstado -> faturamento = faturamentoEstado;
	strcpy( novoEstado -> nomeEstado, nome);

	return novoEstado;
}

estado *adicionarEstado(float faturamentoEstado, char nome[2], estado *listaDeEstados)
{
	estado *novoEstado = criarEstado(faturamentoEstado, nome);

	novoEstado -> proximoEstado = listaDeEstados;
	
	return novoEstado;
}

void faturamentoPorEstado(estado *conjuntoDeEstados)
{
	estado *estadoAtual = conjuntoDeEstados;
	float faturamentoTotal = 0;

	while (estadoAtual != NULL)
	{
		faturamentoTotal += estadoAtual -> faturamento;
			
		estadoAtual = estadoAtual -> proximoEstado;
	}

	printf("faturamento total: %f\n", faturamentoTotal);
	estadoAtual = conjuntoDeEstados;


	while (estadoAtual != NULL)
	{

		printf("estado: %s\nfaturamento: %f\nfaturamento sobre faturamento total:%.2f\n", estadoAtual -> nomeEstado, estadoAtual -> faturamento, (estadoAtual -> faturamento / faturamentoTotal) * 100); 

		estadoAtual = estadoAtual -> proximoEstado;
	}
}

//exercicio5
void inverterString(char *string)
{
	char *caractere = string;
	int qtdCaracteres = 0;

	while (*caractere != '\0')
	{
		++qtdCaracteres;
		++caractere;
	}

	char novaString[qtdCaracteres];

	for (int i = qtdCaracteres; i >= 0; --i) 
	{
		novaString[qtdCaracteres - i] = string[i];
		printf("%c", novaString[qtdCaracteres - i]); 
	}
}


int main()
{
	printf("%d\n", valorDaSoma(13));
	printf("%s\n", fibonacciOuNao(55));

	estado *conjuntoDeEstados = criarEstado(67836.43, "SP");

	conjuntoDeEstados = adicionarEstado(36678.66, "RJ", conjuntoDeEstados);
	conjuntoDeEstados = adicionarEstado(29229.88, "MG", conjuntoDeEstados);
	conjuntoDeEstados = adicionarEstado(27165.48, "ES", conjuntoDeEstados);
	conjuntoDeEstados = adicionarEstado(19849.53, "OU", conjuntoDeEstados);

	estado *impressor = conjuntoDeEstados;

	faturamentoPorEstado(conjuntoDeEstados);

	char *string = "teste pro estagio";

	inverterString(string);
}

