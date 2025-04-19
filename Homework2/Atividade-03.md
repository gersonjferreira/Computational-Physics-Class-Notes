# Atividade 3

## Redes neurais simples

Na pasta **NNFS** ilustramos o funcionamento básico de uma rede neural e a utilizamos para fazer um treinamento ilustrativo onde a rede neural simplesmente aprendeu a interpolar uma função seno no intervalo de 0 a 2π. Vimos que qualquer tentativa de extrapolação falha.

Nesta atividade, vocês farão a mesma coisa, treinar redes neurais para interpolar funções seno, mas...

1. Implementar via PyTorch
2. Implementar via TensorFlow
3. Implementar via scikit-learn

Em todos os casos, use MSE para a fução de perda (loss), otimizador Adam e funções de ativação `tanh`. Varie o número de camadas ocultas e neurônios por camada para ver como afetam o resultado. 

Há muitos outros parâmetros que podem ser ajustados, como a taxa de aprendizado, número de épocas, batch size, número de pontos. Procure entender o que são estes parâmetros e como afetam os resultados.

Anote tudo que aprender na forma de um relatório informal, mas organizado. Pode ser um arquivo markdown ou um jupyter notebook que serão salvos no seu github. 

### Instruções básicas

Eu vou enviar por email um exemplo de implementação em scikit-learn para vocês explorarem. Façam o mesmo com PyTorch ou TensorFlow.

Treinem a rede neural para interpolar algumas funções e procurem entender como o número de camadas e neurônios afetam o resultado. Lembrem-se que excesso de parâmetros pode levar a overfitting.

Funções de teste para treinar:

- seno, cosseno, tangente no intervalo de 0 a 2π
- função sync(x) = sin(x)/x no intervalo de -10 a 10
- função gaussiana no intervalo de -10 a 10

### Treinar derivadas

**Aviso:** Eu nunca fiz este exemplo, pode ser que não funcione da forma enunciada. Caso necessário faça alterações e vamos tentar fazer funcionar.

Vamos tentar ensinar a rede neural a calcular derivadas numéricas. Para isso, vamos definir um domínio comum de 0 a 2π a fim de depois testar com funções trigonométricas.

Use como input N pontos gerados por polinômios, e como output a sua derivada. Varie a potência p de 0 a 10 ao longo do treinamento.

```python
x = np.random.random(0, 2*np.pi)
x_input  = x ** p
x_output = p * x ** (p-1)
```

Finalizado o treinamento, faça um teste (predict) usando uma função trigonométrica como input e verifique se o output retorna sua derivada!




