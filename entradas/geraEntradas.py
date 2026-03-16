#cria um número x de arquivos de entrada com n entre 2 e 1e6
import random

x = 25
nMax = 1000

for i in range(x):
    #Cria o arquivo a ser preenchido
    nomeArquivo = f"e{i + 1}.txt"
    
    #Abre o arquivo
    arquivo = open(nomeArquivo, 'w')

    #Gera o número de entradas
    numeroEntradas = random.randint(2, nMax)

    #Escreve o valor de n gerado no arquivo
    arquivo.write(f"{numeroEntradas}\n")

    #Loop para preencher o arquivo
    for j in range(2 * numeroEntradas):
        numeros = random.sample(range(numeroEntradas), numeroEntradas)
        print(*numeros, sep = " ", file = arquivo, end = "\n")

    #Fechando o arquivo
    arquivo.close()
