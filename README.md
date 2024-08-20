# Memória Virtual

## Desenvolvimento 

### Objetivo 

Escrever programa em C capaz de escrever dados em formato de texto em páginas de memória virtual no sistema operacional

### Implementação

Enfreitei algumas dificuldades para conseguir inserir diretamente na memoria virtual, inicialmete usei o ```malloc``` para realizar uma solicitação ao SO um espaço de memória no espaço de endereçamento virtual do processo, mas a pedido do professor eu mudei a estrategia de solicitação para ```mmap``` foi complicado pois é uma biblioteca para Unix e estava dando erro no meu Windowns, consegui contornar a situação executando o porgrama via um WSL.

## Saída esperada

É esperado de saída desse programa todo o conteúdo do arquivo txt diretamente no terminal, ao final do texto do arquivo o programa devolve algumas informações como: Quantidade de bytes e equivalencia de paginas na memória virtual.

## Como executar o programa

### Clone o Repositório

```
git clone https://github.com/Rosialdo/memoria_virtual.git
```

### verifique se a pasta está correta

```
cd MEMORIA_VIRTUAL
```

### Crie o executavel

```
gcc main.c -o main
```

### Rode o programa

```
./main
```

### Após esses passos é esperado que o programa rode sem mais problemas.
