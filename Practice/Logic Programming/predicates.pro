%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Numbers   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Generate natural numbers
nat(0).
nat(N) :- nat(M), N is M + 1.

% Generate integers
% integer(5, X) -> X = 5; X = -5
int(0, 0).
int(X, Y) :- X > 0, (Y is X; Y is -X).

% Generator & recognizer of even numbers
even(X) :- nat(X), X mod 2 =:= 0.

% Generate numbers in interval [A, B].
% between(10, 15, X) -> 10, 11, 12, 13, 14, 15
% between(10, 15, 12) -> true
between(A, B, A) :- A =< B.
between(A, B, C) :- A < B, A1 is A + 1, between(A1, B, C).

% isPrime() ???
isPrime(N) :- N1 is N // 2, not((between(2, N1, X), N mod Y =:= 0)).
prime(N) :- nat(N), isPrime(N).

is_not_prime(X) :- X1 is X - 1, between(2, X1, Y), X mod Y =:= 0.
all_primes(X) :- nat(X), X > 1, not(is_not_prime(X)).

/*
?- integer(7, Y).
Y = 7 ;
Y = -7.
*/

% Generate a list of numbers in interval [A, B]
% range(10, 15, X) -> [10, 11, 12, 13, 14, 15]
range(A, A, [A]).
range(A, B, [A|C]) :- A < B, A1 is A + 1, range(A1, B, C).

% Generate a pair of naturals
% pairs(X, Y) -> X = 0,Y = 0; X = 1,Y = 0; X = 0,Y = 1; ...
pairs(A, B) :- nat(N), between(0, N, A), B is N - A.

% Length of list
len([], 0).
len([_|T], N) :- len(T, M), N is M + 1.

% Is list empty
is_empty(L) :- length(L, N), N = 0.

% Generate sum of numbers
sum([], 0).
sum([H|T], N) :- sum(T, N1), N is N1 + H.

% Power
% pow(5, X, 2) -> X = 25;
pow(_, 1, 0).
pow(X, Y, N) :- N > 0, N1 is N - 1, pow(X, Z, N1), Y is Z * X.

% Generate K numbers with sum S
% genKS(2, 5, X) -> X = [0,5]; X = [1,4]; X = [2,3]; X = [3,2]; ...
genKS(1, S, [S]).
genKS(K, S, [XI|Result]) :- K > 1, K1 is K - 1, between(0, S, XI), S1 is S - XI, genKS(K1, S1, Result).

% Generate all finite lists of natural numbers, генератор на всички крайни редици от естествени числа (изброимо много).
% genAll(X) -> [], [0], [1], [0, 0], [2], [0, 1], [1, 0], [0, 0, 0], [3], ...
genAll([]).
genAll(L) :- nat(N), between(1, N, K), S is N - K, genKS(K, S, L).

% Divide list in smaller lists
/*
?- divide([1,2,3],L).
L = [[1], [2], [3]] ;
L = [[1], [2, 3]] ;
L = [[1, 2], [3]] ;
L = [[1, 2, 3]] ;
false.
*/
divide([], []).
divide(L, [H|R]) :- append(H, T, L), H \= [], divide(T, R).

% Opposite of divide
% flatten([[1],[2,3]], X) -> X = [1,2,3]
flatten(X, [X]) :- not(is_list(X)).
flatten([], []).
flatten([H|T], R) :- flatten(H, FH), flatten(T, FT), append(FH, FT, R).

% Count occurrences of Y in L
% count([1, 1, 1, 2, 2, 3], 1, X) -> X = 3
count([], _, 0).
count([H|T], H, N) :- count(T, H, M), N is M + 1.
count([H|T], Y, N) :- H \= Y, count(T, Y, N).

% Find the GCD of two numbers
% gcd(5, 10, X) -> X = 5
gcd(A, 0, A).
gcd(A, B, G) :- B > 0, C is A mod B, gcd(B, C, G).

% Напишете предикат, който е истина т.с.т.к. X дели Y. прим 5 дели 10, но 5 не дели 27.
% Трябва да го има това оценяване стойността на Y, иначе се натрупват (...((Y - X) - X)... - X) и не се изчислява.
div(_, Y) :- Y =:= 0.
div(X, Y) :- Y >= X, div(X, Y - X).

% Може и така.
% Като има оператор за присвояване към нова променлива се форсира изчисляването на аритметичния израз от лявата страна
% преди да бъде присвоена неговата стойност на новата променлива
div1(_, 0).
div1(X, Y) :- Y >= X, Y1 is Y - X, div1(X, Y1).

symm(R) :- not(member([X, Y], R)), not(member([Y, X], R)).

trans(R) :- not(member([X, Y], R)), member([Y, Z], R), not(member([X, Z], R)).

switchSign(0, 0).
switchSign(X, Y) :- X > 0, (X is Y; X is -Y).

int(Z) :- nat(N), switchSign(N, Z).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%   Lists   %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Definition of list
islist([]).
islist([_|_]).

% append(L1, L2, L3) where L3 = L1 + L2
append([], L, L).
append([H|L1], L2, [H|L3]) :- append(L1, L2, L3).

% First and last element of a list
first(H, [H|_]).
last(X, L) :- append(_, [X], L).

% Is X a member of the list L
% member(X, [X|_]).
% member(X, [H|T]) :- X \= H, member(X, T).

member(X, L) :- append(_, [X|_], L).

% Insert X in the list L arbitrary
insert(X, L, RL) :- append(A, B, L), append(A, [X|B], RL).

% Remove X in the list L (Only from one position, if X is contained more than once in L)
remove(X, L, RL) :- append(A, [X|B], L), append(A, B, RL).

% Permute the list L
permutation([], []).
permutation([H|T], P) :- permutation(T, Q), insert(H, Q, P).

% Check if sorted
is_sorted(L) :- not((append(_, [A,B|_], L), A > B)).

% The slowest sort algorithm, but valid
simplestSort(L, SL) :- permutation(L, SL), is_sorted(SL).

% Min/Max element of list (with recursion) , \+ означава пак not, но е по-лесно за изписване
min1(L, X) :- member(X, L), not((member(Y, L), X \= Y, Y < X)).
max1(L, X) :- member(X, L), not((member(Y, L), X \= Y, Y > X)).

% Min/Max element of list (play with quantifiers)
% lesser(A, B, A) :- A < B.

% min2(X, [X]).
% min2(X, [H|T]) :- min2(M, T), lesser(H, M, X).

% max2(X, [X]).
% max2(X, [H|T]) :- max2(M, T), \+ lesser(H, M, X).

% Prefix and suffix of list
prefix(P, L) :- append(P, _, L).
suffix(S, L) :- append(_, S, L).

% Sublist of list (a slice/chunk of the list) - префикс на някой суфикс
sublist(R, L) :- append(_, S, L), append(R, _, S).
%sublist(L, S) :- suffix(L, F), prefix(F, S).

% Subset of L
% правим характеристичен вектор от 0 и 1 на участието на даден елемент в подмножеството на списъка L - "тука има, тука няма")
% subset([1,2], X) -> X = [], X = [1], X = [2], X = [1, 2]
subset([], []).
subset([_|T], R) :- subset(T, R).
subset([H|T], [H|R]) :- subset(T, R).

% Get element at position N - generates the position where element X is at or gives the element at position N
% n_th_element(X, 3, [10, 11, 12, 13]) -> X = 12
n_th_element(X, 1, [X|_]).
n_th_element(X, N, [_|T]) :- n_th_element(X, M, T), N is M + 1.

% Set predicates
in_union(X, A, B) :- member(X, A); member(X, B).
in_intersection(X, A, B) :- member(X, A), member(X, B).
in_difference(X, A, B) :- member(X, A), not(member(X, B)).
is_subset_of(A, B) :- not((member(X, A), not(member(X, B)))).
are_equal(A, B) :- is_subset_of(A, B), is_subset_of(B, A).

% Reverse of lists
reverse(L, RL) :- rev(L, [], RL).
rev([], S, S).
rev([H|T], S, R) :- rev(T, [H|S], R).

% Check if L is a palindrome
is_palindrome(L) :- reverse(L, L).

% Erase duplicates in list L
% removeDuplicates([1, 1, 1, 2, 2, 3], X) -> X = [1, 2, 3]
rem_dupl([], []).
rem_dupl([H|T], [H|R]) :- rem_dupl(T, R), not(member(H, R)).
rem_dupl([H|T], R) :- rem_dupl(T, R), member(H, R).

% Split L in two subsets
% split([1, 2, 3], [2, 3, 4], X) ->
split([], [], []).
split([H|T], [H|L], R) :- split(T, L, R).
split([H|T], L, [H|R]) :- split(T, L, R).

get_element_from_list([H|T], R) :- R = H; get_element_from_list(T, R).
