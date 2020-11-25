Autorzy
-------
Piotr Frątczak 300207
Bartosz Świtalski 300279


Problem
-------
Otoczka wypukła
Dany jest zbiór punktów w przestrzeni trójwymiarowej. Wyznaczyć z zadaną dokładnością jego powłokę wypukłą (tzn. tak, aby żaden z punktów nie wystawał ponad znalezioną powłokę bardziej niż zostanie to dopuszczone). Porównać czas obliczeń i wyniki różnych metod.


Uruchomienie
------------
Tryby wykonania:
1. Dane z pliku wejsciowego:
	chull -in <<plik_wejsciowy >>plik_wyjsciowy

2. Automatyczna generacja danych na podstawie parametrów:
	chull -n liczba_punktow -d dokladnosc >>plik_wyjsciowy

3. Testowanie z generacją danych, pomiarem czasu i prezentacją wyników:
	chull -t -n liczba_punktow -d dokladnosc -p liczba_problemow -s krok -r liczba_instancji_problemu



Konwencje
---------
Plik wejściowy
Każdy wiersz składa się z 3 liczb rzeczywistych opisujących współrzędne punktu na osiach x, y, z, oddzielonych średnikiem, z kropką jako separatorem dziesiętnym. Wiersze kończą się znakiem nowej linii. Kolejność punktów jest dowolna

Przykład:
2.15;0.333;4.01
4.665;2.643;9.06

Plik wyjściowy
Format pliku wyjściowego jest podobny do wejściowego, lecz w tym wypadku każde 3 kolejne punkty (w trzech kolejnych wierszach) opisują ścianę powłoki wypukłej. Dodatkowo pierwszy punkt i dwa ostatnie oraz dwa pierwsze i ostatni punkt również opisują ścianę powłoki wypukłej.

Przykład:
2.15;0.333;4.01
4.665;2.643;9.06
5.11;7.45;7.88
1.1;0.34;5.999

Parametry -n, -p, -s, -r powinny być podane jako liczby całkowite.
Parametr powinien być niewielką liczbą rzeczywistą.						//TODO: nadać jakiś warunek wielkośći


Prezentacja wyników
-------------------
Graficzna reprezentacja tworzenia powłoki wypukłej w 3D.				//TODO: czy damy radę zrobić?
																		//TODO: dodać i opisać jeszcze jakieś prostsze typu tabele czy wykresy


Metoda rozwiązania
------------------
Zakładamy, że dane na wejściu nie są podzielone na punkty leżące na powłoce i wewnątrz.

Dane:
	- punkty: zbiór punktów, dla których szukamy powłoki wypukłej
	- n: liczba punktów w punkty

Wynik:
	- uporządkowany zbiór punktów, gdzie każde kolejne 3 punkty tworzą ścianę powłoki wypukłej zbioru punkty

Algorytmy:

1. Algorytm naiwny O(n^4)
Naiwne sprawdzanie każdej trójki punktów czy jest ścianą zewnętrzną powłoki. Wykonają się 4 pętle, każda po n razy.

Pseudokod:
for i in punkty:
	for j in punkty, where j != i:
		for k in punkty, where k != i and k != j:
			for l in punkty, where l != i and l != j and l != k:
				if l jest po zewnętrznej stronie płaszczyzny opisanej przez (i,j,k),
				then (i,j,k) nie jest ścianą powłoki zewnętrznej

2. Gift Wrapping O(nF)
Wykorzystuje fakt, że znamy już punkty należące do powłoki wypukłej i mając krawędź k należącą do takiej ściany, znajdziemy kolejną ścianę przez znalezienie punktu po drugiej stronie krawędzi niż znana już ściana. Dzięki temu nie musimy przeglądać wszystkich trójek, lecz dobieramy kolejny punkt do krawędzi znanej ściany zewnętrznej tak, aby nowa ściana także była zewnętrzna.

Pseudokod:
Rozpoczynamy algorytmem naiwnym, aż do znalezienia pierwszej ściany powłoki wypukłej, następnie 


3. Incremental O(n^2)														//TODO: może tłumaczy się na inkrementalny czy coś


4. Dziel i zwyciężaj O(n*log(n))

																			//TODO: dokończyć opis algorytmów

Jak sprawdzamy czy trójka punktów opisuje ścianę zewnętrzną należącą do powłoki wypukłej:
Sprawdzenie czy punkt d leży przed czy za ścianą złożoną z punktów a, b, c polega na sprawdzeniu wyznacznika macierzy A, który jest równy objętości ostrosłupa o podstawie a, b, c i wierzchołku d.
Jeżeli det(A) > 0, więc objętość jest dodatnia, to punkt d leży po wewnętrznej stronie ściany a, b, c.
Jeżeli det(A) < 0, więc objętość jest ujemna, to punk d leży po zewnętrznej stronie ściany a, b, c.			//TODO: to jest do weryfikacji, chyba jeszcze coś trzeba sprawdzić, żeby się upewnić po której stronie jesteśmy

Postać macierzy A:
	a.x a.y a.z 1
	b.x b.y b.z 1
	c.x c.y c.z 1
	d.x d.y d.z 1


Opis programu
-------------

Podział na moduły:							//TODO: opis modułów, plików, na pewno osobnym będzie generacja danych


Użyte struktury:
Point:
double x
double y
double z

Face:
Point p1
Point p2
Point p3

Edge:
Point p1
Point p2

Hull:
Set<Face>			//TODO: jest Set czy coś takiego w c++?


												//TODO: (skopiowane z pliku) inne informacje dodatkowe o szczególnych decyzjach projektowych (np. ograniczenia dotyczące
												rozmiaru problemu, charakterystyki generatorów danych testowych, specjalne konwencje w
												alokacji pamięci dynamicznej, wymagania dotyczące typów parametryzujących szablony,
												konwencje związane z obsługą sytuacji wyjątkowych, itp.).
