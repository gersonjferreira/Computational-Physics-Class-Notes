# Atividade 4

Nesta primeira atividade, abordaremos os tópicos:

- Números aleatórios: use `rng = np.random.default_rng()`, veja exemplos na [página do numpy](https://numpy.org/doc/2.1/reference/random/generator.html#numpy.random.default_rng)
- Loops para gerar listas, vetores, ou arrays.
- Gráficos com matplotlib.
- Leitura de artigos: passeio aleatório e movimento browniano, Einstein (1905).

## Atividades mínimas: 65 pts

1. **Passeio aleatório (implementação básica).** Considere um passeio aleatório unidimensional, onde a cada instante de tempo o caminhante dá um passo uma unidade para a direita ou para a esquerda com probabilidades $p$ e $1-p$, respectivamente. O passeio termina depois de $N=1000$ passos. Faça um gráfico da posição do caminhante em função do número de passos (que representa o tempo). Use $p=0.5$ e $p=0.8$. Implemente na forma de uma função que receba como argumento o número de passos $N$ e a probabilidade $p$, e retorne um *array* com a posição do caminhante em cada passo.

2. **Passeio aleatório (repetição).** Rode o código acima 100 vezes para um valor fixo $p$ e faça o gráfico conjunto de todos os passeios. Use $p=0.5$ e $p=0.8$. O que observa?

## Atividades intermediárias: 20 pts

3. **Passeio aleatório (médias).** Calcule a média e o desvio padrão da posição do caminhante em função do número de passos. Faça um gráfico da média e do desvio padrão em função dos passos. Use $p=0.5$ e $p=0.8$.

4. **Passeio aleatório (histograma 1).** Usando os dados do exercício 2, faça histogramas da posição do caminhante no inicio, no meio e no final do passeio. Plote os 3 histogramas no mesmo gráfico. Veja se o resultado condiz com o observado no exercício 2.

## Atividades avançadas: 15 pts

5. **Passeio aleatório (histograma).** Usando os dados do exercício 2, faça um histograma da posição do caminhante em cada passo. Faça um gráfico de mapa de cores da evolução do histograma usando `plt.imshow`, `plt.pcolormesh`, ou tente fazer gráficos 3D. Se optar por fazer gráficos 3D, recomendo usar a biblioteca `plotly`, pois gráficos 3D no `matplotlib` não ficam bons.

6. Leia o artigo (traduzido para inglês) [original do Einstein (1905) sobre o movimento browniano](https://www.ift.uam-csic.es/sites/default/files/Einstein1905.pdf). O artigo é longo, mas encontre a seção onde ele deduz a equação de difusão. Reproduza as contas. Usaremos essa equação em atividades futuras. Pode dar uma lida na [wikipedia: Brownian motion](https://en.wikipedia.org/wiki/Brownian_motion) para complementar.