# Atividade 3

Nesta atividade, abordaremos os tópicos:

- Números aleatórios: use `rng = np.random.default_rng()`, veja exemplos na [página do numpy](https://numpy.org/doc/2.1/reference/random/generator.html#numpy.random.default_rng)
- Loops para gerar listas, vetores, ou arrays.
- Gráficos com matplotlib.
- Eficiência dos cálculos com numpy.

## Atividades mínimas: 65 pts

1. $\pi$ **via Monte Carlo (etapa 1)** Considere um círculo de raio $r=1$ inscrito em um quadrado de lado $2r=2$. A área do círculo é $\pi r^2 = \pi$. A área do quadrado é $4$. A razão entre a área do círculo e a área do quadrado é $\pi/4$. Se gerarmos $N$ pontos aleatórios uniformemente distribuídos no quadrado, a fração de pontos que cairão dentro do círculo será $\pi/4$. Assim, podemos estimar $\pi$ como $4$ vezes a fração de pontos que caíram dentro do círculo. Como visto em aula, pode considerar o círculo e quadrados completos, ou apenas o primeiro quadrante. Varie o número de pontos sorteados $N$ para ver como o resultado muda. Implemente na forma de uma função com assinatura:

```python
def pi_monte_carlo(N):
    '''
    DOCSTRING
    '''
    # seu código aqui
    return estimativa_pi
```

2. **Mapa logístico, caos e fractais (etapa 1)** O mapa logístico é definido pela equação $$x_{n+1} = r x_n (1 - x_n),$$ onde $x_n$ é a população (normalizada entre 0 e 1) no instante de tempo discreto $n$, e $r$ é o parâmetro de crescimento. Para um dado valor de $r$, a população $x_n$ pode convergir para um valor fixo, oscilar entre dois valores, ou oscilar entre mais de dois valores, ou simplesmente enlouquecer e parecer aleatório. 

    a) Implemente uma função `mapa_logistico(r, x0, N)` que recebe o parâmetro de crescimento `r`, a condição inicial `x0` (i.e. $x_0$ para $n=0$), e o número de iterações `N`, e retorna uma lista com os valores de $x_n$ para $n=0,1,2,\ldots,N$.

    b) Faça gráficos de $x_n$ vs $n$ (de 0 a 200 ou 300) para $r = 2, 3.3, 3.5, 3.9$, sempre iniciando de $x_0=0.3$. Talvez seja melhor usar um gráfico de linhas (`plt.plot`) para $r=2$, e um gráfico de pontos (`plt.scatter`) para os outros valores de $r$. O que você observa?

## Atividades intermediárias: 20 pts

3. $\pi$ **via Monte Carlo (etapa 2)** Modifique sua função `pi_monte_carlo(N)` para que agora receba um booleando `retorna_pontos` que indica se a função deve retornar os pontos sorteados separados em duas listas: `dentro` e `fora`. Usando estas listas, faça um gráfico dos pontos sorteados, com os pontos dentro do círculo em azul e os pontos fora em vermelho. A assinatura da função deve ser:

```python
def pi_monte_carlo(N, retorna_pontos = False):
    '''
    DOCSTRING
    '''
    # seu código aqui
    if retorna_pontos:
        return estimativa_pi, dentro, fora
    else:
        return estimativa_pi
```

4. **Mapa logístico, caos e fractais (etapa 2)** Nesta etapa iremos utilizar apenas os últimos $M$ valores de $x_n$ gerados pela sua função `mapa_logistico(r, x0, N)`. Sugiro usar $N=2000$ e $M=1000$, mas se ficar pesado, reduza $M$. Faça um loop de $r=1$ até 4 em passos de 0.1 (use `np.arange`), e para cada valor de $r$, plote os últimos $M$ pontos $x_n$ no eixo y, e o valor de $r$ no eixo x, sugiro fazer assim:

```python
# dentro do loop de r:
    # ...
    plt.plot(r*np.ones(M), xn[-M], 'k.', markersize=0.5)
    # ...
# fora do loop de r:
plt.show()
```

Note que o comando `plt.show()` e outras configurações de aparência do plot devem estar fora do loop de $r$. O que você observa? O que acontece com o mapa logístico a medida que $r$ cresce?

## Atividades avançadas: 15 pts

5. $\pi$ **via Monte Carlo (etapa 3)** Seja $E_N = |\pi-\pi_N|/\pi$ o erro relativo da estimativa de $\pi$ com $N$ pontos. Faça gráficos de $E_N$ em função de $N$ para $N = 10^1, 10^2, 10^3, 10^4, 10^5, 10^6$. Compare os gráficos feitos em escala linear (`plt.plot`), log-log (`plt.loglog`), e semi-logs (`plt.semilogx` ou `plt.semilogy`). O que você observa? Faça um ajuste dos dados com uma função apropriada usando `numpy.polyfit` ou `scipy.optimize.curve_fit`.

6. **Mapa logístico, caos e fractais (etapa 3)** Modifique o plot da etapa 2 deste exercício para que entre no modo interativo do `matplotlib`, de forma a permitir que você possa dar zoom em regiões interessantes do gráfico. Para uma boa visualização, talvez seja necessário rodar com valores maiores de $M$. Sempre use $N = M + 1000$. O que você observa ao dar zoom no gráfico?

7. $\pi$ **via Monte Carlo (etapa 4)** Implemente uma versão eficiente do cálculo de $\pi$ via Monte Carlo, que não use *loops* e *ifs* explícitos, mas sim operações vetorizadas do numpy. Compare o tempo de execução desta versão com a versão lenta que usa *loops* e *ifs*. Pode usar o `%timeit` do jupyter para os primeiros testes, mas como poderia fazer o gráfico do tempo de execução como função do número de pontos sorteados $N$?