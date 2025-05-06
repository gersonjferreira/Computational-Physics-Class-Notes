# Atividade 4

## Physics Informed Neural Networks (PINNs)

Redes Neurais Informadas por Física (PINNs) vão além de regressões e classificações tradicionais, e incorporam fundamentos de física no seu treinamento. Em geral, são projetadas para resolver problemas de equações diferenciais parciais (PDEs) e sistemas dinâmicos regidos por uma equação conhecida, mas de solução desconhecida. O treinamento de uma PINN envolve a minimização de uma função de perda que combina:

1. Dados conhecidos (se disponíveis): dados experimentais ou simulações que fornecem informações sobre o sistema.
2. Restrições físicas: resíduo das equações diferenciais que descrevem o comportamento do sistema.
3. Condições de contorno: condições iniciais e de contorno que devem ser satisfeitas pela solução.

A primeira condição é a minimização do **erro dos dados**, que já usamos nas regressões tradicionais. A segunda e a terceira são as **restrições físicas**. Estas três condições são combinadas em uma função de perda total, que é minimizada durante o treinamento da rede neural. O resultado é uma rede neural que não apenas se ajusta aos dados, mas também respeita as leis da física. Consequentemente, é capaz de extrapolar os dados.

Além disso, a PINN é capaz de descobrir os parâmetros da PDE que descrevem os dados. Por exemplo, podemos ter dados de um oscilador harmônico para o qual não sabemos a frequência e constante de amortecimento. A PINN é capaz de aprender a resolver a equação e descobrir estes parâmetros.

## Exercício 1

Siga o tutorial do site [Physics-informed Neural Networks: a simple tutorial with PyTorch](https://medium.com/@theo.wolf/physics-informed-neural-networks-a-simple-tutorial-with-pytorch-f28a890b874a). Neste exemplo, você irá resolver a EDO do resfriamento de uma caneca de café em etapas:

1. Resolva analiticamente a EDO do resfriamento de uma caneca de café. A equação é dada por:

```math
   \frac{dT}{dt} = r(T_{amb} - T)
```
onde $T$ é a temperatura do café, $T_{amb} = 25$ ºC é a temperatura ambiente e $r = 0.005$ 1/s é uma taxa de resfriamento.

2. Resolva a EDO usando o método de Runge-Kutta de quarta ordem (RK4) e compare com a solução analítica. Use o comando `scipy.integrate.solve_ivp`.

3. Usando a solução analítica, ou RK4, gere dados sintéticos para treinar a PINN. Cerca de 10 pontos no intervalo de 0 a 200 segundos (veja exemplo no tutorial). Some um ruído gaussiano com média 0 e desvio padrão 0.5 em cada ponto.

4. Tente usar uma NN de regressão simples para ajustar os dados sintéticos e extrapolar para tempos maiores (até 1000 segundos). Compare com a solução analítica. Sabemos que a extrapolação será péssima.

5. Agora, siga o tutorial e implemente a PINN incluindo as restrições físicas na minimização da perda, mas assumindo que conhecemos o valor da taxa $r = 0.005$ 1/s. Compare com a solução analítica e com a NN de regressão simples.

6. Ainda seguindo o tutorial, implemente a PINN sem conhecer o valor da taxa $r$. A rede deve ser capaz de descobrir o valor correto. Compare com a solução analítica e com a NN de regressão simples.

## Exercício 2

Ainda não decidi. As opções são:

- EDO do oscilador harmônico. Ver TCC Bianca e muitos tutoriais online.

- Evolução temporal da equação de onda 1D.

- EDP para difusão de calor 2D, ou membrana vibrante 2D.