# Atividade 2

## Classe partícula

Nesta atividade, vamos explorar fundamentos de orientação a objetos em python. Vamos criar uma classe chamada `Particula` que representa uma partícula em um espaço bidimensional. A classe deve ter os seguintes atributos e métodos:

- Atributos:
  - `x`: coordenada x da partícula
  - `y`: coordenada y da partícula
  - `vx`: velocidade na direção x
  - `vy`: velocidade na direção y
  - `massa`: massa da partícula

- Métodos:
    - `__init__(self, x, y, vx, vy, massa)`: construtor da classe que inicializa os atributos da partícula.
    - `newton(self, fx, fy, dt)`: aplica a segunda lei de Newton para atualizar a velocidade e a posição da partícula com base nas forças `(fx, fy)` aplicadas e no intervalo de tempo `dt`. Considerar que a força é constante durante o intervalo de tempo `dt`.

## Como organizar os arquivos e repositório

1. Crie um arquivo chamado `particula.py` e implemente a classe `Particula` conforme as especificações acima.
2. Crie um arquivo chamado `exemplo01.py` onde iremos desenvolver os exemplos. Veja mais abaixo.
3. Crie um arquivo chamado `README.md` e escreva uma breve descrição do que o código faz, como usá-lo e quais são os requisitos para executá-lo.
4. Crie um arquivo chamado `LICENSE` e adicione a licença MIT.
5. Crie um arquivo chamado `.gitignore` e adicione os arquivos e pastas que você não quer que sejam versionados pelo git.
6. Crie um repositório no GitHub e faça o push do seu código para o repositório.

## Exemplo de uso

Nos arquivos `exemplo01.py`, `exemplo02.py` iremos implementar alguns exemplos de uso da classe `Particula`. 

### Exemplo 1: lançamento oblíquo

Crie a particula inicialmente com posição (x,y) = (0,0), velocidade (vx,vy) = (10,10) m/s, e massa m = 1 kg. Consideraremos apenas a força da gravidade, (fx, fy) = (0, -9.8) m/s². A cada dt = 0.1 s, aplique a força da gravidade e atualize a posição e velocidade da partícula. Salve a posição, velocidade e tempo em listas ou arrays para posterior plotagem. Interrompa o loop quando a partícula atingir o solo (y <= 0). Faça um gráfico da posição como função do tempo.

### Exemplo 2: em breve

