# Unik - Gra w Unikanie Rakiet

## Opis projektu
Unik to prosta gra 2D napisana w C++ z wykorzystaniem biblioteki SFML. Gracz steruje bohaterem na planszy o rozmiarze 10x10 i musi unikać rakiet, które poruszają się po planszy w losowych kierunkach.

## Technologie
- C++
- SFML
- Programowanie wielowątkowe

## Instalacja i uruchomienie
### Wymagania
- Kompilator obsługujący standard C++11 lub nowszy (np. g++ lub MSVC)
- SFML (Simple and Fast Multimedia Library)
- CMake (opcjonalnie, jeśli chcesz skompilować projekt w środowisku CMake)

### Kompilacja i uruchomienie
1. Sklonuj repozytorium:
   ```sh
   git clone https://github.com/twoje_repo/unik.git
   cd unik
   ```
2. Skonfiguruj SFML i skompiluj projekt:
   ```sh
   g++ -std=c++11 -o unik src/*.cpp -Iheaders -lsfml-graphics -lsfml-window -lsfml-system
   ```
3. Uruchom grę:
   ```sh
   ./unik config.txt
   ```

## Konfiguracja
Gra wykorzystuje plik konfiguracyjny `config.txt`, w którym można ustawić liczbę rakiet oraz prędkość gry. Plik powinien zawierać dwie liczby:
```
10 5
```
Pierwsza liczba oznacza liczbę rakiet, a druga ich prędkość (im wyższa wartość, tym wolniejsza gra).

## Sterowanie
- `W` - ruch w górę
- `S` - ruch w dół
- `A` - ruch w lewo
- `D` - ruch w prawo

## Dokumentacja
Dokumentacja do kodu znajduje się w folderze `docs`.

## Demo

![unik_demo](https://github.com/user-attachments/assets/880fdc3e-4028-4cdf-a060-ababc79901b5)


