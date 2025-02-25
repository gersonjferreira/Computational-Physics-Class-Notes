# Atividade 2

Nesta atividade, abordaremos os tópicos:

- Numpy, documentação: [User Guide](https://numpy.org/doc/stable/user/index.html) e [API Ref](https://numpy.org/doc/stable/reference/index.html)
- Matplotlib: [documentação](https://matplotlib.org/stable/index.html)

---

**Instruções gerais**

Todos os exercícios podem ser desenvolvidos no ambiente Jupyter da plataforma [Google Colab](https://colab.research.google.com/). Porém, usuários mais experientes podem optar por desenvolver na sua IDE favorita.

A atividade deve ser devolvida na forma de relatório, preferencialmente em PDF, contendo o código com documentação clara e ilustração dos resultados.

Todas as atividades serão divididas em três etapas com pontuações indicadas como abaixo.

## Atividades mínimas: 65 pts

1. Siga os exemplos de gráficos disponíveis nas minhas páginas:

- [Repositório geral do curso](https://github.com/gersonjferreira/Computational-Physics-Class-Notes)
- [Livro online com tutoriais](https://compphysics.readthedocs.io/)
- Slides em PDF no repositório.

Após seguir e reproduzir os exemplos por conta própria, faça gráficos das funções abaixo usando `numpy` para gerar os dados e `matplotlib` para plotar. Em cada caso, escolha os limites do eixo x de forma razoável para uma boa visualização das funções.

- Gaussianas de diferentes larguras e centros.
- Função `sinc(x) = sin(x)/x`.
- Exponencial `y = exp(ax)`, com para diferentes valores de `a = -10, -1, 2, 10`.

2. Considere a função `y = ax² + bx + c`, com valores arbitrários para a, b, c, que devem ser definidos como variáveis no inicio do código. Use o código de Bhaskara da atividade anterior para achar as raízes `r1` e `r2`. Faça um gráfico da parábola e indique as raízeis com círculos. Faça isso para pelo menos três casos, com discriminantes positvo, zero e negativo.

## Atividades intermediárias: 20 pts

3. Repita o exercício 1 acima, mas agora em duas etapas. 

- Em um arquivo de código você deve gerar os dados que serão plotados e salvar em um arquivo. Para isso, veja a documentação das funções `numpy.savetxt`, `numpy.save`, `numpy.savez`. Entenda a diferença entre elas e escolha a que preferir. Neste código você só pode usar a biblioteca `numpy`, não deve usar a `matplotlib`.

- Em um segundo arquivo de código, você irá ler os dados salvos no arquivo gerado pelo código anterior, e irá plotar o gráfico usando `matplotlib`. Para ler os dados, veja a documentação das funções `numpy.loadtxt` e `numpy.load`.

## Atividades avançadas: 15 pts

4. Faça um gráfico das curvas paramétricas:

- Deltoid:
```math
x = 2 \cos\theta + \cos 2\theta
```

```math
y = 2\sin\theta - \sin 2\theta
```

- Espiral de Galileu: $r = \theta^2$

- Fey’s function: $r = e^{\cos\theta} -2\cos 4\theta + \sin^5(\theta/12)$

