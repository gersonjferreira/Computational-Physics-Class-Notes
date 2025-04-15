# Atividade 3

## Redes neurais simples

Na pasta **NNFS** ilustramos o funcionamento básico de uma rede neural e a utilizamos para fazer um treinamento ilustrativo onde a rede neural simplesmente aprendeu a interpolar uma função seno no intervalo de 0 a 2π. Vimos que qualquer tentativa de extrapolação falha.

Nesta atividade, vocês farão a mesma coisa, treinar redes neurais para interpolar funções seno, mas...

1. Implementar via PyTorch
2. Implementar via TensorFlow

Em todos os casos, use MSE para a fução de perda (loss), otimizador Adam e funções de ativação `tanh`. Varie o número de camadas ocultas e neurônios por camada para ver como afetam o resultado. 

Há muitos outros parâmetros que podem ser ajustados, como a taxa de aprendizado, número de épocas, batch size, número de pontos. Procure entender o que são estes parâmetros e como afetam os resultados.

Anote tudo que aprender na forma de um relatório informal, mas organizado. Pode ser um arquivo markdown ou um jupyter notebook que serão salvos no seu github. 



