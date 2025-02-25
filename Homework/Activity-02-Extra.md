# Atividade 2 - Exercícios Extras

**Aviso:** Este é um exercício extra, e não é necessário entregá-lo.

Alguns exercícios aqui foram inspirados ou extraídos dos livros:

1. Mark Newman - Computational Physics (2013, University of Michigan)

## Exercício 1

O arquivo `millikan.txt` contém dados experimentais de Millikan sobre a carga do elétron. O arquivo contém duas colunas de números, a primeira representa a frequência $\nu$ em Hertz e a segunda o potencial $V$ em volts. A teoria do efeito fotoelétrico nos diz que:

$$
V = \frac{h}{e}\nu - \phi
$$

Sendo $h$ a constante de Planck, $e$ a carga do elétron e $\phi$ a função trabalho do material.

a) Escreva um programa que leia os dados do arquivo e faça um gráfico de $V$ em função de $\nu$. Faça um gráfico de pontos, sem linhas.

b) Ajuste uma reta aos dados, plote-a junto aos pontos do item anterior, e determine o valor da razão $h/e$ e da função trabalho $\phi$ do material.

> Sugestão: Use a função `numpy.polyfit` para ajustar uma reta aos dados.


## Exercício 2

Considere o arquivo de dados `sunspots.txt` que contém o número de manchas solares observadas a cada mês desde janeiro de 1749. O arquivo contém duas colunas de números, o primeiro representando o mês e o segundo o número de manchas solares observadas.

a) Escreva um programa que leia os dados do arquivo e faça um gráfico do número de manchas solares em função do tempo. Faça um gráfico de pontos, sem linhas.

b) Escreva um código que calcule a média movel dos dados, considerando uma janela de 50 meses. Plote a média móvel como linha sólida sobre os pontos do item anterior.

> Sugestão: Use a função `numpy.convolve` para fazer a convolução dos dados com um vetor de média móvel.

A equação para a média móvel é dada por:

$$
\bar{y}_i = \frac{1}{2k+1} \sum_{j=-k}^{k} y_{i+j}
$$
