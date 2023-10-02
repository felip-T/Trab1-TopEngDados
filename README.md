# Matriz em POO

O trabalho é composto por 5 arquivos, sendo um deles o Makefile com comandos para compilação em Linux, utilizando o GCC, um arquivo .cpp contendo a função main do programa e 3 arquivos de cabeçalho, contendo a implementação da matriz.

Todas as classes foram implementadas como classes templates, e não há vazamentos de memória de acordo com a ferramenta valgrind.

# Structures.h
Esse arquivo implementa classes podem ser utilizadas pela classe “Matrix” para armazenar dados. Os dados são armazenados utilizando arrays e tem o tamanho apropriado para cada tipo de matriz. Há uma interface “MatrixDataStructure” que serve de base para todas as outras classes. Foi implementada as classes “TwoDMatrix”, para matrizes quadradas e de tamanho arbitrário, “OneDMatrix” para matrizes diagonais, TriMatrix e TriUpMatrix para matrizes triangulares. Cada uma dessas classes possuem construtor, destrutor e métodos get para retornar o valor de uma posição e at, para retornar uma referência há uma posição.

# Matrix.h
Implementa matrizes de tamanho arbitrário, com métodos comuns há todas as matrizes, como os operadores de soma, subtração, adição, multiplicação de matrizes e multiplicação por escalar. Implementa também métodos para imprimir a matriz (pelo operador « e pelo método “show”), e um método para aplicar uma operação em todos os elementos (“doOp”), utilizado pelos operadores. A classe “Matrix” implementa métodos virtuais para serem sobrescritos pelas outras classes.

# SquareMatrix.h
Implementa as classes “squareMatrix”, “diagonalMatrix”, “triangularDownMatrix” e “triangularUpMatrix”, com seus métodos especializados. Todas as classes implementadas nesse arquivo herdam da classe “Matrix” e adaptam seus métodos e estruturas para o tipo específico de matriz.

# Main.cpp
Programa principal simples para testes com algumas matrizes prontas e opções para fazer operações entra as matrizes.
