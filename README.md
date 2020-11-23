<!-- TABLE OF CONTENTS -->
## Table of Contents

* [Authors](#authors)
* [Description of the Problem](#description)
* [Run guide](#run-guide)
* [Usage and interpretation](#usage-and-interpretation)
* [Solution](#solution)
* [Project layout](#project-layout)
* [Miscellaneous limitations](#miscellaneous-limitations)

## Authors
Piotr Frątczak 300207

Bartosz Świtalski 300279

## Description
Dany jest zbiór punktów w przestrzeni trójwymiarowej. Wyznaczyć z zadaną
dokładnością jego powłokę wypukłą (tzn. tak, aby żaden z punktów nie
wystawał ponad znalezioną powłokę bardziej niż zostanie to dopuszczone).
Porównać czas obliczeń i wyniki różnych metod.

## Run guide
todo
1. Lorem ipsum dolor sit amet, consectetur adipiscing elit.  [https://example.com](https://example.com)
2. Morbi egestas enim nunc, et laoreet augue posuere ut.
```sh
git clone https://github.com/bartoszswitalski/convex-hull.git
```
3. Nam sem lectus, tristique at metus vel, tempor finibus eros.
```sh
npm install
```
4. Sed ac turpis non turpis posuere venenatis sit amet eget justo.
```JS
const API_KEY = 'ENTER YOUR API';
```

## Usage and interpretation
todo

## Solution 
### Algorithms
- Gift wrapping: O(nh) //fP(n) <= cnh
- Graham Scan: O(n log n) //fP(n) <= cn log n
- Chan's algorithm: O(n log h) //fP(n) <= cn log h
- Kirkpatrick-Seidel algorithm O(n log h)

n - the number of input points  
h - the number of points on the convex hull

## Project layout
todo
```
.
├── dir1
│   ├── file11.ext
│   └── file12.ext
├── dir2
│   ├── file21.ext
│   ├── file22.ext
│   └── file23.ext
├── dir3
├── file_in_root.ext
└── README.md
```

## Miscellaneous limitations
todo
