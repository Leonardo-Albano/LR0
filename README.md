Considere o alfabeto abaixo, formado pelas letras mínusculas do alfabeto, o sinal de adição, os sinais de parênteses e o espaço em branco. (Os parênteses angulares não fazem parte da linguagem, eles foram colocados em torno dos símbolos apenas para facilitar sua visualização. O último símbolo é o espaço em branco.)

Σ = { <a> , <b> , <c> , ... , <z> , <+> , <(> , <)> , < >}

Um transdutor é um autômato que, além de decidir uma cadeia de entrada, gera uma cadeia de saída durante o processo. Modele e implemente um DFA transdutor que reconheça cadeias compostas pelos símbolos de Σ e gere como saída uma cadeia na qual os espaços tenham sido eliminados e as letras alfabéticas contíguas tenham sido substituídas pela letra "x". Os demais símbolos devem ser copiados tal como estão. Se houver na entrada algum símbolo que não pertence ao alfabeto o autômato deve rejeitar a palavra. Exemplos:

Entrada: "abc"
Saída: "x"

Entrada: "Abc"
Saída: <REJEITAR>

Entrada: "aaa + xyz "
Saída: "x+x"

Entrada: " abc xyz +"
Saída: "xx+"

Entrada: "(abc) ) + ("
Saída: "(x))+("

Entrada: "(a bc) ) + ("
Saída: "(xx))+("

Considere agora a seguinte gramática livre de contexto:

S → (E)
S → x
E → S
E → E+S

Esta gramática gera cadeias que representam somas não ambíguas: x, (x), (x+x), (x+(x)), ((x)+x), ((x)+(x)), ((x+x)+x) etc.

Implemente um analisador para a linguagem gerada por esta gramática utilizando o algoritmo LR(0) (requer construção prévia da tabela shift-reduce). O analisador deverá receber como entrada a cadeia gerada pelo transdutor e informar se a cadeia pertence ou não à linguagem.

A composição de uma linguagem livre de contexto com uma linguagem regular resulta em uma linguagem livre de contexto. Ao combinar seu parser com o DFA anterior, seu algoritmo será capaz de aceitar cadeias do tipo: abc, (abc), (abc+def), ((abc+def)+ghi) etc.

A modelagem do transdutor e os tratamentos prévios requeridos pelo algoritmo escolhido são parte do trabalho, devem ser feitos manualmente (em papel ou no computador) e devem ser enviados juntamente com o código.

O trabalho deve ser feito em até quatro pessoas, deve ser implementado em linguagem C padrão e deve ser submetido nesta página por apenas um dos integrantes da equipe até a data especificada ao lado. Não serão aceitas entregas que ultrapassem o prazo. As defesas ocorrerão em sala no mesmo dia da entrega. A apresentação será em grupo, mas a atribuição da nota sera individual e apenas para os integrantes presentes. Como parte da avaliação o professor poderá solicitar explicações e modificações no código para qualquer um dos integrantes durante a defesa. As equipes poderão levar seus próprios computadores, mas o computador da sala estará disponível para execução do código e o professor não se responsabiliza caso o programa não rode na máquina disponível. Instruções adicionais poderão ser dadas ao longo das próximos aulas e/ou acrescentadas nesta especificação.

Documentação funções:

Replacer:
    int isAcceptedSymbol(char c):

        Essa função irá receber qual o símbolo a ser verificado se pertence ao alfabeto ou não, portanto, aceitando somente '+', '(', ')', ' ', e letras minúsculas do alfabeto.

        Caso o item seja algum símbolo "especial" aceito, a função irá retornar 1, caso seja uma letra minúscula, irá retornar 2, e caso seja um espaço em branco, irá retornar 3. (Caso não pertença a nenhum irá encerrar a aplicação, uma vez que essa não pertence ao alfabeto.)

    char* getInput()
        Essa função será chamada no método principal, e irá solicitar uma entrada do usuário, para então chamar o método replaceToGrammar para retornar a palavra já "traduzida" para o alfabeto aceito.

    char* replaceToGrammar(char* input, int len)
    (necessário refatorar para dar um realoc pro tamanho correto da palavra ao invés do tamanho padrão)
        Esse será a função responsável por fazer o replace dos caracteres, e para tal, irá iterar dentre todos os caracteres inseridos no input do usuário, identificando o tipo de cada um por meio do método isAcceptedSymbol(), e para cada número faz uma lógica.
        Caso seja um símbolo especial { (, ), + } irá escreve-lo no output, e caso a variável de verificação para letras seja true, irá escrever um 'x' antes do símbolo especial.
        Caso seja uma letra minúscula, irá alterar uma varíavel booleana (e caso seja o último caractere, só adiciona um x no output)
        Caso seja um espaço, irá fazer a mesma lógica dos símbolos, porém sem escrever o símbolo atuala (que será um espaço).
        E por fim, irá colocar um \0 na última posição