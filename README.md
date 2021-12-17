<h1>AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria</h2>

Este trabalho consiste na implementação da estrutura da árvore vermelho-preto, bem como, sua comparação com as árvores binária e AVL. Sua função é preparar três bases diferentes, uma com 1000 entradas, uma com 10.000 entradas e uma terceira com 1.000.000 entradas do tipo ponto flutuante, valores esses não repetidos e randomicos. Para cada uma das bases você precisará pesquisar 5000, 10.000 e 100.000 itens, os quais são fornecidos por arquivos de números aleatórios, seguindo o mesmo processo de geração utilizado nas bases de entrada. No arquivo de pesquisa, pode haver valores repetidos, valores não existêntes na estrutura e valores únicos e válidos. 

Para tanto, pode-se considerar as implementações já realizadas, adaptando as mesmas para essa necessidade. Este trabalho tem como  pontos de avaliação:

   - Laboratório de AEDS:

           1) - Qualidade do código implementado. Observando organização, clareza e autenticidade da solução por aluno.

           2) - Estratégia de aplicação. Neste ponto será avaliado os esforços de cada aluno em buscar uma solução interessante para avaliar as estruturas. 

   - AEDS:

           1) - Documentação. Qualidade da documentação apresentada sobre o tema, bem como, das fontes utilizadas para pesquisa.

           2) - Definição dos gráficos de tempo apresentados para comparar o tempo de pesquisa e inserção de todas as três estruturas. Observem que há várias formas de apresentação interessantes, como: apresentar o tempo médio a cada X entradas, apresentar o tempo total gasto, apresentar uma linha temporal mostrando o tempo gasto por cada entrada, etc. Sejam criativos e detalhistas nesse ponto.

           3) - Qualidade da discussão apresentada como conclusão para as seguintes perguntas:

                    3.1) - Qual das estruturas é mais rápida para pesquisa e porquê?

                    3.2) - Há diferença de tempo das inserções, o que afeta cada estrutura em termos de mecanismo de manipulação / balanceamento?

                    3.3) - Considerando as três bases de entrada, para quais você indica cada uma das estruturas e porquê?

<h1>Como usar o software</h1>

1) copie o código da página do github: https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria.git
2) abra uma pasta em seu sistema operacional e digite o seguinte comando: git clone https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria.git
3) passos à baixo:

Para acessar o software e rodar o software:
~~~
make clean

make 

make run
~~~

Ao abrir o software, através do Makefile, clique na opção 4 caso queira gerar novos arquivos. Após, escolha em qual árvore vai analisar!

<h2>Análise dos Algorítmos</h2>

<h1>Árvore Binária</h1>

Gráfico de 1.000 inserções.

~~~~
Tempo de inserção:  1,768 segundos
busca 5.000: 7,057 segundos
busca 10.000: 6,031 segundos
busca: 100.000: 55,898 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/binaria_1000.png" width="400" height="300">
</p>

Gráfico de 10.000 inserções.

~~~~
Tempo de inserção: 13,203 segundos
busca 5.000: 3,264 segundos
busca 10.000: 6,563 segundos
busca: 100.000: 75,221 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/binaria_10000.png" width="400" height="300">
</p>

Gráfico de 1.000.000 inserções.

~~~~
Tempo de inserção: 1.434,772 segundos
busca 5.000: 14,799 segundos
busca 10.000: 21,408 segundos
busca: 100.000: 202,427 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/binaria_1000000.png" width="400" height="300">
</p>

<h1>Árvore AVL</h1>

Gráfico de 1.000 inserções.

~~~~
Tempo de inserção:  2,414 segundos
busca 5.000: 4,441 segundos
busca 10.000: 7,777 segundos
busca: 100.000: 47,468 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/avl_1000%20-%20Copia.png" width="400" height="300">
</p>

Gráfico de 10.000 inserções.

~~~~
Tempo de inserção: 15,325 segundos
busca 5.000: 3,004 segundos
busca 10.000: 5,802 segundos
busca: 100.000: 71,969 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/avl_10000.png" width="400" height="300">
</p>


Gráfico de 1.000.000 inserções.

~~~~
Tempo de inserção: 2.992,989 segundos
busca 5.000: 15,720 segundos
busca 10.000: 34,456 segundos
busca: 100.000: 258,755 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/avl_1000000.png" width="400" height="300">
</p>


<h1>Árvore Rubro-Negra</h1>

Gráfico de 1.000 inserções.

~~~~
Tempo de inserção:  2,099 segundos
busca 5.000: 5,213 segundos
busca 10.000: 6,024 segundos
busca: 100.000: 51,800 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/Rubro%20Negra%201.000.png" width="400" height="300">
</p>

Gráfico de 10.000 inserções.

~~~~
Tempo de inserção: 14,302 segundos
busca 5.000: 4,091 segundos
busca 10.000: 6,354 segundos
busca: 100.000: 64,721 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/Rubro%20Negra%2010.000.png" width="400" height="300">
</p>


Gráfico de 1.000.000 inserções.

~~~~
Tempo de inserção: 2.373,385 segundos
busca 5.000: 10,344 segundos
busca 10.000: 22,235 segundos
busca: 100.000: 194,391 segundos
~~~~

<p>
	<img src="https://github.com/leonardo8787/AED_2_Trabalho_3_comparacao_de-estruturas_de_busca_binaria/blob/main/imagens/Rubro%20Negra%201.000.000.png" width="400" height="300">
</p>

<h1>Considerações Finais</h1>
	É notório que as inserções nas árvores influênciam no tempo de execução das mesmas, como visto nos gráficos supra-citados. Partindo desse pressuposto, fica nítido ao analisar os gráficos dos respectivos tempos de execução dos softwares de ordenação e busca, que ao aumentar os números de busca ou inserção influênciamos no desempenho. Outrossim, ao analizar cada árvore separadamente é possível notar leves diferenças de desempenho, ao trabalhar com os números de tempo de execução, como por exemplo, a árvore AVL se mostra mais rápida com poucas entradas e se mostra pior com grandes entradas.
	
--> Qual das estruturas é mais rápida para pesquisa e porquê? A estrutura mais rápida analisada neste software foi a Rubro Negra, visto que o tempo de execução foi menor!

--> Há diferença de tempo das inserções, o que afeta cada estrutura em termos de mecanismo de manipulação / balanceamento?  Essa diferença se dá em função da manipulação de folhas que há nas árvores AVL e Rubro Negra, o quê não está presente na árvore binária, que tem um mecanismo mais simples. Inclusive é possível notar essa diferença nos tempos de execução supra-citados!

--> Considerando as três bases de entrada, para quais você indica cada uma das estruturas e porquê? para 1.000 inserções, indico a binária. Para 10.000 inserções, recomendo a Binária. Para 1.000.000 de inserções, recomendo a binária também! A árvore binária se mostra mais dinâmica do que as outras pelo fato de ter uma estrutura mais simples, assim é mais rápido inserir elementos na árvore. Nas outras árvores começam a interarir com balanceamento e rotação o quê deixa o processo de inserção mais lento!
