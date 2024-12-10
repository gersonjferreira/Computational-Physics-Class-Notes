---
lang: pt-br
---

# Atividade 1

Nesta primeira atividade, abordaremos os tópicos:

- Introdução a linguagem python e a IDE Google Colab
- Operações numéricas simples: +, -, *, /, %, **
- Print, strings, formatação
- Loops *for* e *while*
- Tipos de variáveis: inteiros, complexos, listas
- Funções, argumentos e quantidades retornadas
- Docstrings e documentação
- Assertion, Raise Exception, Try/Except

---

**Instruções gerais**

Todos os exercícios podem ser desenvolvidos no ambiente Jupyter da plataforma [Google Colab](https://colab.research.google.com/). Porém, usuários mais experientes podem optar por desenvolver na sua IDE favorita.

A atividade deve ser devolvida na forma de relatório, preferencialmente em PDF, contendo o código com documentação clara e ilustração dos resultados.

Todas as atividades serão divididas em três etapas com pontuações indicadas como abaixo.

## Atividades mínimas: 65 pts

1. **Fatorial.** A biblioteca `numpy` já tem uma função otimizada para calcular o fatorial. Porém, vamos fazer a nossa apenas para treinar o uso de loops. Então, faça uma função chamada `fatorial` que recebe um parâmetro `n` e calcula `n!` usando um loop tipo `for`. Sua implementação deve funcionar de acordo com o template abaixo:

```python
def fatorial(n):
    '''
    Calcula e retorna o fatorial de n.

    Argumentos
    ----------
    n : int
        O número para o qual calcular o fatorial.
    
    Retorna
    -------
    int
        O fatorial de n.
    '''
    # Seu código deve ir aqui.
    # E deve terminar retornando o valor do fatorial.
    # Evite usar print dentro de funções.
    # ...
    return # variável com valor do fatorial

print(f'O fatorial de 3 é {fatorial(3)}')

print('O fatorial de 1 é', fatorial(1))

f10 = fatorial(10)
print(f'O fatorial de 10 é {f10}')

f0 = fatorial(0)
print('O fatorial de 0 é', f0)
```

2. **Fibonacci.** Use um loop do tipo `for` em uma função chamada `fibonacci`, que recebe um número `n` e retorna uma lista com os `n` primeiros números da sequência de Fibonacci. Seu código deve seguir o template abaixo:

```python
def fibonacci(n):
    '''
    Escreva uma docstring descritiva como a do exercício anterior.
    '''
    # Seu código vai aqui.
    # ...
    return # lista com sequência de Fibonacci


print('Sequência dos 5 primeiros números de Fibonacci:', fibonacci(5))

f = fibonacci(20)
print('Sequência dos 20 primeiros números de Fibonacci:', f)

numero = 30
f = fibonacci(numero)
print(f'Sequência dos {numero} primeiros números de Fibonacci: {f}')
```

3. **Bhaskara.** Defina uma função chamada `bhaskara` que recebe três parâmetros `(a, b, c)` e retorne a duas raízes `(x1 , x2)` da equação `ax<sup>2</sup> + bx + c = 0`. O código deve seguir o template abaixo:

```python
def bhaskara(a, b, c):
    '''
    Escreva uma docstring descritiva como a do exercício anterior.
    '''
    # Seu código vai aqui.
    # ...
    return # tupla com as duas raízes

x1, x2 = bhaskara(2, 12, -14)
print('A primeira raiz é:', x1)
print('A segunda raiz é:', x2)
```

4. **Divisores.** Escreva uma função chamada `is_divisor(a, b)` que verifica se `a` é divisível por `b` e retorna `True` ou `False` adequadamente. Não se esqueça de escrever a *docstring* e após a função escreva duas chamadas de exemplo como em todos os exemplos acima.

## Atividades intermediárias: 20 pts

5. Refaça o exercício sobre fatorial, mas desta vez, implemente usando (i) loop `while`; (ii) funções *recursivas*.

6. Reveja o exercício sobre a sequência de Fibonacci e edite a função para receber um *keyword argument* do tipo `lista_completa = True`. Quando este argumento for `True`, o código deve retornar a sequência completa como antes, mas caso seja `False` deve retornar apenas o `n`-ésimo (último) número da sequência.

7. Verifique se seu código de Bhaskara funciona quando as raízes são complexas. Pode testar com parâmetros `a = 1`, `b = 2` e `c = 3`. Caso não esteja funcionando, corrija para que retorne raízes complexas corretamente. Não use nenhuma biblioteca externa para isso. Permita também que o código funcione com `a = 0`, neste caso deve retornar duas raízes iguais.

## Atividades avançadas: 15 pts

8. Use `assertions` nos códigos do fatorial e Fibonacci para restringir o parâmetro `n` ao tipo inteiro. No caso de Fibonacci, use também o `assert` para verificar se o parâmetro `lista_completa` é do tipo booleano.

9. Modifique o código de Bhaskara para que: (i) funcione apenas com `a` diferente de zero (use `assertions`); (ii) não permita raízes completas e levante um erro caso o delta seja negativo.

10. O código dos *divisores* acima não deve funcionar quando `b = 0`. Faça esta verificação de duas formas: (i) usando `assertions`; (ii) usando `try/except` para levantar um erro do tipo `ZeroDivisionError`, imprimir uma mensagem de erro na tela, e retornar `None` ao invés de `True/False`.