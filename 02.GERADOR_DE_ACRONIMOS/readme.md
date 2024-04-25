# Acrônimos
Acrônimos são abreviações formadas pelas letras iniciais de uma expressão ou conjunto de palavras, que juntas formam uma nova palavra pronunciável.

Eles são utilizados em diversos contextos, desde áreas técnicas e científicas até na linguagem cotidiana. Por exemplo, "NASA" é um acrônimo para "National Aeronautics and Space Administration".

Existem ainda os acrônimos recursivos (estes são os mais legais), que são aqueles que contém a própria palavra ou parte dela em sua definição. Isso significa que uma ou mais letras do acrônimo representam a palavra ou frase que o próprio acrônimo está tentando abreviar. Esse tipo de acrônimo cria um loop auto-referencial. Por exemplo, se você já programou em python provavelmente conhece o "PIP Installs Packages", que é um exemplo de acrônimo recursivo.

# Tarefa
O objetivo desse VPL é avançar na prática dos comandos de entrada e saída específicos de C++ (cout, cin e getline) e também a utilização do tipo string.

Como um entusiasta dos acrônimos (principalmente dos recursivos), sua tarefa é criar um programa em C++ que lê um texto escrito pelo usuário, mostra o seu acrônimo e identifica se ele é um acrônimo recursivo ou não.

# Regras do jogo
1. É garantido que todos os textos recebidos pelo seu programa terão as palavras separadas por espaço;
2. A primeira letra de cada palavra é sempre maiúscula, mas as demais podem ser maiúsculas ou minúsculas;
   1. Para as preposições que ocasionalmente se intrometam no meio do texto, terão a primeira letra maiúscula somente se fizerem parte do acrônimo (vide exemplo 3 e 4)
3. O texto pode, ocasionalmente, conter símbolos especiais, como ':', '&' etc, mas estes não devem fazer parte do acrônimo;
4. O acrônimo deve ser mostrado completamente em letra maiúscula;
5. O seu programa deve utilizar **std::cin** ou **std::getline** para obter a entrada do usuário;
6. O seu programa deve imprimir um inteiro que pode assumir o valor de 0 ou 1, e o acrônimo encontrado. O inteiro deve ser 0 caso o acrônimo não seja um acrônimo recursivo ou 1 caso contrário (veja os exemplos).

Para os fins desta tarefa, considere para a formação do acrônimo somente a primeira letra de cada palavra. Casos em que o acrônimo e formada por uma combinação de várias letras de uma palavra não aparecem nos casos de teste. Por exemplo:
> REMAX: **R**eal **E**state **MAX**imums

> Gestapo: **Ge**heime **Sta**ats**po**lizei

> Interpol: **Inter**national **Po**lice

> Hamas: **Ha**rakat al-**M**uqawamah **a**l-I**s**lamiyyah

# Exemplos de entrada e saída
## Exemplo 1
**input**
> PHP: Hypertext Pre-processor

**output**
> 1 PHP

## Exemplo 2
**input**
> PhP: Hypertext Pre-processor

**output**
> 1 PHP

## Exemplo 3
**input**
> Institute of Electrical and Electronics Engineers

**output**
> 0 IEEE

## Exemplo 4
**input**
> WINE Is Not an Emulator

**output**
> 1 WINE

# Links não tão inúteis
1. https://en.wikipedia.org/wiki/Acronym
2. https://en.wikipedia.org/wiki/Recursive_acronym
3. https://cplusplus.com/reference/sstream/stringstream/stringstream/
4. https://cplusplus.com/reference/cctype/toupper/
