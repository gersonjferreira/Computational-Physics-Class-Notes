# Atividade 1

## Gradiente descendente

O método do **gradiente descendente** é um algoritmo de otimização utilizado para minimizar funções. Ele é amplamente utilizado em aprendizado de máquina e redes neurais para ajustar os pesos e vieses de um modelo. Vamos aplicar o método para encontrar o mínimo de funções simples.

O algoritmo é muito parecido com a dinâmica de uma partícula se movendo em um potencial e sujeita a muito atrito. Seja $U(\vec{r})$ a energia potencial, sabmos que a força que atua sobre a partícula é dada por: 

$$
\vec{F} = -\nabla U(\vec{r})
$$

Note que a direção da força é oposta ao gradiente da função potencial. Daí vem o nome **gradiente descendente**.

Considerando um intervalo de tempo infinitesimal $\Delta t$, podemos considerar a força constante durante esse intervalo. Assim, a variação da posição da partícula é dada pelo MRUV: $\Delta \vec{x} = \vec{v}_ {0} \Delta t + \frac{1}{2} \vec{a} \Delta t^2$, sendo $\vec{a} = \vec{F}/m$. Mas, se assumirmos que o atrito é muito grande, podemos assumir que a particula sempre para depois de cada passo $\Delta \vec{r}$, então $\vec{v}_ {0} = 0$ e a variação da posição da partícula é dada por:

$$
\Delta \vec{r} = \frac{1}{2} \vec{a} \Delta t^2 = -\alpha \nabla U(\vec{r})
$$

Onde definimos a constante $\alpha = \Delta t^2/2m$, que chamaremos de **taxa de aprendizado**, pois determina o tamanho do passo que daremos na direção do gradiente. 

Assim, os passos do algoritmo para achar o mínimo de uma função $U(\vec{r})$ qualquer são:

1. Inicializar a posição da partícula $\vec{r}_ {0}$.
2. Calcular o gradiente $\nabla U(\vec{r})$ na posição atual $\vec{r}_ {0}$.
3. Atualizar a posição da partícula: $\vec{r}_ {1} = \vec{r}_ {0} - \alpha \nabla U(\vec{r}_ {0})$.
4. Considerar $\vec{r}_ {1}$ como a nova posição inicial da partícula e repetir os passos 2 e 3 em um loop da forma $\vec{r}_ {n} = \vec{r}_ {n-1} - \alpha \nabla U(\vec{r}_ {n-1})$.
5. Interromper o loop quando a variação da posição for menor que um valor de tolerância $\epsilon$ ou quando o número máximo de iterações for atingido.
6. Retornar a posição final da partícula $\vec{r}_ {n}$ como o mínimo da função $U(\vec{r})$.

A descrição acima funciona para qualquer dimensionalidade. Mas nota-se que se a dimensionalidade for muito grande, como no caso de NNs, o cálculo do gradiente pode ser muito custoso. Para evitar isso, podemos usar o método de **gradiente descendente estocástico** (SGD). Veremos isso em outra etapa do curso.

## Exercício 1

Implemente o algoritmo de gradiente descendente para encontrar o mínimo da função $U(x) = x^2 -1$. É um caso bem simples para o qual sabemos a solução exata. Ilustre o algoritimo com um gráfico mostrando a função $U(x)$ e a trajetória da partícula. Use inicialmente uma taxa de aprendizado $\alpha = 0.1$ e uma tolerância $\epsilon = 0.01$. O número máximo de iterações deve ser 1000. A posição inicial da partícula deve ser $x_ {0} = 5$. Depois, varie estes parâmetros para ver como eles afetam a convergência do algoritmo.

## Exercício 2

Repita o exercício 1 para a função $U(x) = x^2 (x-1)(x+1)$. Esta função tem dois mínimos globais. Use $x_ {0} = 2$ e tente ajustar $\alpha$ para tentar fazer o código convergir ora num mínimo, ora no outro. O que acontece? O que você pode concluir sobre a escolha da taxa de aprendizado $\alpha$?

## Exercício 3

Repita o exercício 2, mas agora vamos manipular a altura dos mínimos somando uma reta em $U(x)$, tal que a função agora é $U(x) = x^2 (x-1)(x+1) + x/4$. O que acontece? O que você pode concluir sobre a escolha da taxa de aprendizado $\alpha$?

## Exercício 4

Considere agora uma função bidimensional $U(\vec{r}) = U(x,y) = \sin(x)\cos(y) + 2 (xy)^2/1000$. A função tem multiplos mínimos locais. A vizualiação 3D dos passos neste caso pode ser dificil de interpretar. Então, neste caso, para acompanhar a evolução do algoritmo, faça dois gráficos:

a. Um gráfico de contorno (use `plt.imshow` ou `plt.pcolormesh`) da função $U(x,y)$ e desenhe a trajetória da partícula no gráfico.

b. Faça um gráfico do valor de $U(x_ {n}, r_ {n})$ a cada passo como função das iterações (passos) $n$. No contexto de redes neurais chamaremos estes passos de **epochs**.

Varie a posição inicial $(x_ {0}, y_ {0})$ e a taxa de aprendizado $\alpha$ e veja como isso afeta a convergência do algoritmo. O que acontece se você aumentar muito a taxa de aprendizado? E se você diminuir muito? Você consegue atingir o mínimo global?