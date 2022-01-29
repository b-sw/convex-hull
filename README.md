<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Authors](#authors)
* [Description of the Problem](#description)
* [Solution](#solution)

## Authors
Piotr Frątczak 300207

Bartosz Świtalski 300279

## Description
Dany jest zbiór punktów w przestrzeni trójwymiarowej. Wyznaczyć z zadaną
dokładnością jego powłokę wypukłą (tzn. tak, aby żaden z punktów nie
wystawał ponad znalezioną powłokę bardziej niż zostanie to dopuszczone).
Porównać czas obliczeń i wyniki różnych metod.

## Solution 
- Naive Algorithm O(n^4)
- Gift Wrapping O(nF)
- Incremental O(n^2)
- Divide-and-Conquer (n log n)
F is the number of faces on CH
