# Aula 1

Alguns exercícios aqui foram inspirados nos livros:

1. Mark Newman - Computational Physics (2013, University of Michigan)

## Exercício 1

Escreva uma função que receba o tempo em segundos, converta para horas, minutos e segundos e retorne uma tupla com esses valores. Inclua também um parâmetro `verbose` que seja `False` por padrão, mas que caso seja verdadeiro, imprima o tempo no formato `hh:mm:ss`. Sua função deve ter a seguinte assinatura:

```python
def segundos_para_hhmmss(tempo_em_segundos, verbose=False):
    '''
    Escreva uma DOCSTRING para a função com uma breve descrição de seu propósito e uma descrição dos parâmetros e do valor de retorno.
    '''

    # seu código aqui
```

Teste seu código testando para alguns exemplos. Quando estiver usando `verbose=False`, precisará escolher uma forma de imprimir o resultado para verificar se está correto.

## Exercício 2

Escreva uma função que receba como parâmetro um ponto dado em coordenadas cartesianas (x, y), converta e retorne em coordenadas polares (r, θ). Sua função não deve imprimir nada na tela, e deve ter a seguinte assinatura:

```python
def cartesianas_para_polares(x, y):
    '''
    Escreva uma DOCSTRING para a função com uma breve descrição de seu propósito e uma descrição dos parâmetros e do valor de retorno.
    '''

    # seu código aqui
```

Modifique o código acima para que o parâmetro de entrada seja um vetor ou tupla `r = (x, y)`, tal que a assinatura passe a ser:

```python
def cartesianas_para_polares(r):
    '''
    Escreva uma DOCSTRING para a função com uma breve descrição de seu propósito e uma descrição dos parâmetros e do valor de retorno.
    '''

    # seu código aqui
```

Nos dois casos, rode a função para alguns exemplos e verifique se o resultado está correto. Você deve receber a saída da função e imprimir na tela por fora do escopo da função.

## Exercício 3

Uma espaçonave viaja da Terra a um planeta em outra estrela a uma velocidade próxima à da luz. Escreva uma função que receba a distância até o planeta em anos-luz e a velocidade da espaçonave em fração da velocidade da luz, e retorne o tempo que a espaçonave leva para chegar ao planeta (em segundos). 

Talvez você queira usar e modificar a função do Exercício 1 para imprimir o tempo no formato (anos, meses, dias, horas, minutos, segundos). Mas para isso, assuma inicialmente meses de 30 dias e anos de 365 dias (ignore anos bisextos). Mas veja, a função deste exercício não deve escrever nada na tela, ela deve apenas retornar o tempo, e você deve capturar o tempo e imprimir na tela diretamente, ou usando a função do Exercício 1.

