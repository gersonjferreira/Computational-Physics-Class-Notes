# Atividade 5

Nesta atividade, abordaremos os tópicos:

- Equações diferenciais de condição inicial (IVP = initial value problem).
- Equações diferenciais de condição de contorno (BVP = boundary value problem).
- Diferenças finitas.

Desta vez mudei a organização das notas. Preste atenção na nova organização.

## [1] Método de Euler via planilha eletrônica

Considere a equação diferencial para um corpo em queda livre com resistência do ar: $$\frac{dv}{dt} = -g - \frac{b}{m} v^2,$$ onde $g$ é a aceleração da gravidade, $b$ é o coeficiente de arrasto, e $m$ é a massa do corpo. A equação acima é uma equação diferencial de condição inicial (IVP = initial value problem).

Considere $g = 9.8$ m/s², $b = 0.1$ kg/m, e $m = 1$ kg. A condição inicial é $v(0) = 0$ m/s.

### Atividades mínimas: 65 pts

- 1a. Considerando que o tempo avança em passos discretos na forma de $t_n = n \Delta t$, sendo $\Delta t$ o passo temporal, use o método de Euler para obter a formula iterativa para a velocidade no instante $t_{n+1}$ em termos dos dados em $t_n$: 

$$ v_{n+1} = v_n + \left(-g - \frac{b}{m} v_n^2\right)\Delta t $$

- 1b. Usando $\Delta t = 0.1$ s, faça uma tabela no Excel com os valores de $t_n$ e $v_n$ para $n=0, 1, \ldots, 100$. Use a fórmula de Euler para calcular $v_{n+1}$ a partir de $v_n$ iterativamente no Excel ou outras planilhas eletrônicas equivalentes.

- 1c. Usando as duas colunas obtidas no item anterior, use as funções gráficas da planilha eletrônica para fazer um gráfico de $v_n$ em função de $t_n$. Verifique se a velocidade terminal atinginda bate com o valor esperado.

### Atividades intermediárias: 20 pts

- 1d. Refaça o mesmo problema acima, mas agora em python usando arrays do `numpy` para armazenar $t_n$ e $v_n$ e `matplotlib` para os gráficos.

### Atividades avançadas: 15 pts

- 1e. Refaça o mesmo problema, mas agora usando o método de [Runge-Kutta de quarta ordem (RK4)](https://en.wikipedia.org/wiki/Runge%E2%80%93Kutta_methods). Nesta etapa você deve implementar o método RK4 e não deve usar o comando `scipy.integrate.solve_ivp`, usaremos este comando mais adiante. Rode para diferentes passos $\Delta t$ e compare os resultados dos métodos de Euler e RK4. O que você observa? 

- 1f. Explique o que significa o método de Euler ser de segunda ordem e o de RK4 ser de quarta ordem. Como isso afeta a precisão das evoluções temporais?

## [2] Oscilador harmônico

Considere a EDO do oscilador harmônico amortecido:

$$
\frac{d^2x}{dt^2} = -\omega_0^2 x - b \frac{dx}{dt}
$$

Esta é uma EDO de segunda ordem, mas os métodos de Euler e RK4 são feitos para EDOs de primeira ordem. Para resolver este impasse, temos duas opções: redução de ordem ou método de Verlet.

### Atividades mínimas: 65 pts

- 2a. Transformar a EDO de segunda ordem em um sistema de duas EDOs de primeira ordem via *redução de ordem*. Para isso, introduza a variável $v = dx/dt$ e escreva o sistema de duas EDOs para $x(t)$ e $v(t)$. Procure escrever o sistema de equações em uma forma vetorial, tal que fique com a seguinte estrutura: $$\frac{d}{dt} \begin{pmatrix} x \\ v \end{pmatrix} = \begin{pmatrix} f_1(t, x, v) \\ f_2(t, x, v) \end{pmatrix}$$ ou $$ \frac{d\vec{y}}{dt} = \vec{f}(t, \vec{y})$$

### Atividades intermediárias: 20 pts

- 2b. Usar o método RK4 para o sistema de EDOs usando o comando `scipy.integrate.solve_ivp`. Use $\omega_0 = 2\pi$, tal que o período natural de oscilações seja $T = 1$. Varie o valor de amortecimento $b$ para obter resultados nos regimes de amortecimento subcrítico, crítico e supercrítico. Faça gráficos de $x(t)$ e $v(t)$ em função do tempo. 

### Atividades avançadas: 15 pts

- 2c. Repita o item anterior, mas agora usando o [método de Verlet](https://en.wikipedia.org/wiki/Verlet_integration).

## [3] Vibrações na corda

Considere a equação de ondas:
$$
\frac{\partial^2 u}{\partial t^2} = c^2 \frac{\partial^2 u}{\partial x^2}
$$
onde $u(x, t)$ é a função de onda, $c$ é a velocidade da onda, e $x$ é a posição ao longo da corda. A equação acima é uma equação diferencial de condição de contorno (BVP = boundary value problem). Como condição de contorno, consideraremos que as duas pontas da corda estão presas: $u(0, t) = 0$ e $u(L, t) = 0$, onde $L$ é o comprimento da corda. 

Neste exercício estaremos interessados apenas nos modos normais de vibração e não na evolução temporal da onda. Portanto, não precisamos de condição inicial.

### Atividades mínimas: 65 pts

- 3a. Considere o *ansatz* $$
u(x, t) = \phi(x) e^{i \omega t}. $$ Substitua o *ansatz* na equação de ondas e obtenha a equação diferencial para $\phi(x)$. Note que ela toma a forma de uma equação de autovalores e autovetores. Obtenha as soluções analíticas.

- 3b. Use o método de diferenças finitas para expressar o operador $d^2/dx^2$ na forma de uma matriz tridiagonal (**veja as notas de aula do professor**). Para isso, considere uma grade de pontos igualmente espaçados $x_n = n \Delta x$, com $n=0, 1, \ldots, N-1$ e $\Delta x = L/(N-1)$. Com isso, você terá escrito a equação diferencial na forma $$A \phi = \lambda \phi,$$ onde $A$ é um matriz e $\lambda$ é o autovalor. Identifique corretamente a matriz $A$ e o autovalor $\lambda$ em termos dos parâmetros do problema.

### Atividades intermediárias: 20 pts

- 3c. Use o comando `numpy.linalg.eigh` para calcular os autovalores e autovetores da matriz $A$ obtida no item anterior. Compare os autovalores obtidos com os valores analíticos obtidos no item 3a. O que você observa?

- 3d. Faça o gráfico dos 4 primeiros modos de vibração.

### Atividades avançadas: 15 pts

- 3e. Reveja o *ansatz* feito acima, e nome que pode reconstruir a onda $u(x, t)$ a partir dos modos de vibração. Faça uma animação dos 4 primeiros modos de vibração oscilando em um subplot 2x2. 

- 3f. Considere $$u(x,t) = \sum_n c_n u_n(x,t),$$ sendo $u_n(x,t)$ o modo de vibração $n$ e $c_n$ um coeficiente de Fourier. Use os 4 primeiros modos de vibração para fazer uma animação da onda $u(x,t)$ em função do tempo. Use $c_n = 1/n^2$ para os coeficientes de Fourier. 