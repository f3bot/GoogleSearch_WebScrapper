# GoogleSearch_WebScrapper
Zadanie domowe 🏠🔥
Zadanie 1

Wczytaj pliki zawierające wyniki wyszukiwania stron internetowych, m.in. plik dla którego poprzednio wyodrębniałeś telefony (lista plików zawierająca wyniki wyszukiwań w Google: plik1, plik2 , plik3, plik4. Zauważ, że telefon wizualnie skojarzony jest z hyperlinkiem (umieszczonym w nagłówku wyniku wyszukiwania) prowadzącym na stronę, na której został opublikowany. np. https://www.biblioteka.wroc.pl/filie/filia-nr-7. Łatwiej to zauważyć gdy np. w Google Chrome, na podglądzie strony, wybierzesz funkcję inspect preview, wtedy możesz zobaczyć zagnieżdżoną strukturę dokumentu html.

    Stwórz wyrażenie regularne, które wyodrębnia wyniki poszczególnych znalezionych w wyszukiwarce pozycji i wyodrębni z niego hyperlink z adresem znalezionej strony
    Zastosuj wyrażenie regularne z zadania wprowadzającego nr 5 i 6, które w obrębie znalezionej pozycji wyszukiwania wyodrębni wszystkie ciągi pasujące do wzorca numeru telefonu. Wersja trudniejsza: zmodyfikuj tak wyrażenie regularne żeby znaleźć jak najwięcej numerów telefonów pojawiających się w wynikach wyszukiwania.
    znalezione dane zapisuj do mapy std::map<std::string, std::vector<std::string>>, której kluczem jest hyperłącze, a wartościami wektor zawierający numery telefonów skojarzone z danym łączem. Otwórz 1-2 stron w przeglądarce i zweryfikuj skuteczność z jaką udało Ci się wyodrębnić numery telefonów i hyperliniki odnoszące się do wyników wyszukiwania. W wersji podstawowej możesz założyć, żę jeśli znajdziesz większość (>50%) numerów pasujących do założonego wzorca, to wymagania zadania zostały spełnione.
    dokonaj transformacji numerów telefonów do znormalizowanej postaci usuwając z nich spacje i myślniki oraz nawiasy
    stwórz funkcję std::string href_trimmed = href_trim(href_full), która z hyperlinku wyodrębni wyłącznie nazwę domeny np. dla https://www.biblioteka.wroc.pl/filie/filia-nr-7 będzie to biblioteka.wroc.pl. Użyj tej wartości jako klucza mapy (wtedy telefony różnych filii zostaną pogrupowane w obrębie jednego klucza)
    używając algorytmu std::unique_copy lub kontenera std::set spraw, żeby dla danego wpisu numery telefonów się nie powtarzały (może się zdarzyć, że dany numer pojawia się na kilku stronach należących do tej samej domeny)
    zapisz dane do pliku CSV, w którym w pierwszej kolumnie znajduje się nazwa domeny, a w kolejnych znalezione numery telefonów (może się zdarzyć, że w każdym wierszu będzie inna liczba kolumn)

Autorzy: Piotr Kaczmarek
