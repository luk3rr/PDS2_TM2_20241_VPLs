# WARNING: VPL is under construction
# Connected and Autonomous Vehicles
CAVs são veículos que incorporam tanto a tecnologia de veículos conectados, isto é, são capazes de trocar informações entre si, como também a tecnologia de serem autônomos. A união dessas duas tecnologias permite que os veículos formem pelotões que planejam manobras em conjunto para atingir um certo objetivo, além de trazer outros benefícios, como a segurança e a eficiência no transporte.

Um pelotão de CAVs é formado por um veículo líder e os veículos seguidores. A responsabilidade do líder é enviar comandos para os veículos seguidores, como o de acelerar, frear, alinhar com o pelotão etc. A imagem abaixa ilustra um pelotão de 5 CAVs.

![Pelotão de CAVs](./imgs/platoon.png)

# Tarefa
O objetivo deste VPL é trabalhar conceitos relacionados ao desenvolvimento de classes em C++, especificamente encapsulamento e herança.

Como um engenheiro e, principalmente, como um entusiasta dos carros autônomos, sua tarefa é implementar um programa que simula **um único** pelotão de CAVs em uma via. Para essa tarefa, considere que a via é alguma reta paralela ao eixo X. Os veículos podem trafegar tanto no sentido positivo quanto no negativo, a depender da aceleração e velocidade correntes.

O objetivo é, dado um ponto qualquer na via, atravessá-lo com o veículo líder. Em outros palavras, se $v$ é o veículo líder do pelotão e $t$ é o ponto alvo (target), o objetivo é atingido quando:

1. Se no início da simulação $t.x > v.x$, então o objetivo é atingido quando $v.x \ge t.x$;

2. Se no início da simulação $t.x < v.x$, então o objetivo é atingido quando $v.x \le t.x$.

Para essa tarefa, considere o tempo como uma grandeza discreta. Você pode, por exemplo, ter um loop que a cada interação incrementa um contador em uma unidade e considerar isso como o seu tempo. Assim, a velocidade pode ser alterada a cada interação (como se cada loop durasse 1 segundo).

Inicialmente, o nosso cenário começa com a velocidade de aceleração de todos os veículos iguais a zero. A velocidade é alterada através de **eventos** registrados pelo usuário. Um evento consiste em dois valores:

1. Inteiro positivo que representa o tempo da simulação que ele deve ocorrer;

2. O novo valor da aceleração dos veículos.

Por exemplo, antes da execução do programa, o usuário pode registrar 3 eventos:

1. No tempo 10, a aceleração deve ser definida como 10;

2. No tempo 14, a aceleração deve ser definida como -5;

3. No tempo 20, a aceleração deve ser definida como 1.

Não menos importante, os veículos têm uma velocidade máxima permitida. Então, supondo que a velocidade máxima para o exemplo acima seja 10, a partir do momento 20 até atingir o objetivo os veículos poderiam acelerar até atingir 10.

## O que você deve implementar
### class Point
Classe responsável por representar um ponto no plano, ou seja, deve conter os atributos necessários para armazenar coordenadas.

#### Atributos
1. **m_x**, **m_y** do tipo double, utilizado para armazenar as coordenadas.

#### Métodos
1. Point(double, double): Construtor que recebe os parâmetros x e y, nessa ordem, e inicializa os atributos da classe;

2. SetX(double) e SetY(double): Métodos para definir um novo valor para os atributos;

3. GetX() e GetY(): Métodos para obter os valores dos atributos.

### class Vehicle
Classe responsável por representar nossos queridos CAVs. Essa classe deve ser uma classe derivada de **Point**.

Cada veículo deve conter um ID, que deve ser um número inteiro positivo e deve ser sequencial. Assim, o veículo com ID zero será o líder e os demais serão seguidores.

#### Atributos
1. **m_id** do tipo std::size_t (veja o link 2), utilizado para armazenar o ID do veículo;

2. **m_speed** do tipo double, que deve armazenar a velocidade atual;

3. **m_maxSpeed** do tipo double, que indica a velocidade máxima que o veículo pode ter;

4. **m_acceleration** do tipo double, que indica a aceleração do veículo.

#### Métodos
1. Vehicle(std::size_t id, double x, double y, double limitSpeed, double acceleration): Construtor que recebe e inicializa os atributos da classe

2. SetSpeed(double), SetAcceleration(double): Métodos utilizados para alterar os atributos da classe;

3. GetID(), GetSpeed(), GetAcceleration(): Métodos para obter os valores dos atributos.

OBS.: Se você estiver apanhando para inicializar os atributos da classe base (Point) através do construtor de Vehicle, o link 3 pode iluminar a sua vida.

### class Platoon
Essa classe é a responsável por armazenar os veículos do pelotão e coordená-los, simulando o envio de informações do veículo líder para os seguidores. Como sugestão, você pode armazenar os veículos em um vector.

### class ou struct Event, ou utilizar std::pair
Aqui você pode decidir utilizar class ou struct (aliás, você sabe a diferença entre class e struct?). Um event consiste em um par **<tempo, aceleração a definir>**. Onde o tempo é o momento em que a aceleração deve ser alterada.

Você também pode optar por utilizar uma estrutura já implementada da STL que tem o mesmo objetivo (armazenar dois valores) chamada **std::pair**.

### Freedom
Além disso, você é livre para implementar outros métodos ou classes que achar necessário para a sua solução.

#### main
O main já foi implementado é você pode (e provavelmente deva) copiá-lo para testar o seu programa localmente. A ideia é que vocês implementem somente os TADs, simulando o caso em que sua implementação será utilizada por outra pessoa (que conhece apenas o contrato).

OBS.: Você **não** deve alterar o main.

# Regras do jogo
1. Todos os atributos de todas as classes devem ser encapsulados e serem acessados somente através de métodos Get e Set.

# Exemplos de entrada e saída
A entrada e saída do programa já foi programada no main, mas deixo aqui uma explicação sobre como ela é feita.

## Entrada
A entrada para o seu programa consiste em $N$ linhas.

A primeira linha recebe 5 valores, na seguinte ordem:

1. Número total de eventos ($e$);

2. Número total de veículos ($v$);

3. Velocidade máxima que os veículos podem atingir na via;

4. Coordenada X do ponto alvo;

5. Coordenada Y do ponto alvo.

As próximas $v$ linhas são responsáveis por criar os veículos do nosso cenário, e cada uma contém dois valores que são as coordenadas cartesianas que indicam a posição inicial de veículo.

As demais $e$ linhas são os eventos que devem ocorrer durante a simulação. Também são compostas por dois valores:

1. Tempo em que o evento devo ocorrer;

2. Aceleração a ser definida no tempo em questão.

## Saída
A saída é composta por $1 + v$ linhas.

A primeira linha deve indicar o tempo total até atingir o objetivo.

As demais $v$ linhas devem conter o ID, a velocidade e a posição do veículo no momento em que o objetivo foi atingido.

O formato definido no main é o seguinte:
+ ID : VELOCIDADE : X Y

## Exemplo 1
**input**\
3 2 10 30 0\
5 0\
3 0\
0 0\
1 2\
5 1

**output**\
6\
0 : 9 : 34 0\
1 : 9 : 32 0\
2 : 9 : 29 0

## Exemplo 2
Observe que nesse exemplo, os veículos começam a desacelerar no tempo 20 e até mesmo viajam no sentido negativo da via por um determinado tempo.

**input**\
5 3 3 50 0.2\
0 0\
-1 0\
-2 0\
-3 0\
-4 0\
10 1.0\
20 -5\
30 1

**output**\
528\
0 : 3 : 51 0\
1 : 3 : 50 0\
2 : 3 : 49 0\
3 : 3 : 48 0\
4 : 3 : 47 0

## Exemplo 3
**input**\
2 6 42 2001 0\
1 0\
0 1\
0 1\
1 3\
2 4\
5 -0.5\
80 0.19\
220 -0.003

**output**\
1098\
0 : 2.466 : 2002.46 0\
1 : 2.466 : 2001.46 1

# Links não tão inúteis

1. https://onlinelibrary.wiley.com/doi/10.1002/asmb.2772
   - Se estiver curioso sobre CAVs, comece por este artigo, foi um dos mais legais que li durante a minha iniciação científica.
2. https://en.cppreference.com/w/cpp/types/size_t
3. https://stackoverflow.com/questions/6923722/how-do-i-call-the-base-class-constructor
4. https://www.geeksforgeeks.org/pair-in-cpp-stl/
