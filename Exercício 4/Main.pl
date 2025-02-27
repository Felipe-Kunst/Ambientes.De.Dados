% Fatos
progenitor(maria, joao). 
progenitor(jose, joao). 
progenitor(maria, ana). 
progenitor(jose, ana). 
progenitor(joao, mario). 
progenitor(ana, helena). 
progenitor(ana, joana). 
progenitor(helena, carlos). 
progenitor(mario, carlos). 

sexo(ana, feminino). 
sexo(maria, feminino). 
sexo(joana, feminino). 
sexo(helena, feminino). 
sexo(mario, masculino). 
sexo(joao, masculino). 
sexo(jose, masculino). 
sexo(carlos, masculino).

% Regras
mae(X, Y) :- progenitor(X, Y), sexo(X, feminino).

pai(X, Y) :- progenitor(X, Y), sexo(X, masculino).

irma(X, Y) :- progenitor(A, X), progenitor(A, Y), X \== Y, sexo(X, feminino).

irmao(X, Y) :- progenitor(A, X), progenitor(A, Y), X \== Y, sexo(X, masculino).

descendente(X, Y) :- progenitor(Y, X).
descendente(X, Y) :- progenitor(Y, A), descendente(A, X).

avo(X, Y) :- progenitor(X, A), progenitor(A, Y), sexo(X, masculino).

tio(X, Y) :- irmao(X, A), progenitor(A, Y).

primo(X, Y) :- irmao(A, B), progenitor(A, X), progenitor(B, Y), X \== Y.

prima(X, Y) :- irma(A, B), progenitor(A, X), progenitor(B, Y), X \== Y.
