# Memória Virtual

## Desenvolvimento 

### Objetivo 

Escrever programa em C capaz de escrever dados em formato de texto em páginas de memória virtual no sistema operacional

### Implementação

Enfreitei algumas dificuldades para conseguir inserir diretamente na memoria virtual, então usei o ```malloc``` para realizar uma solicitação ao SO um espaço de memória no espaço de endereçamento virtual do processo.


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

## Análise o programa