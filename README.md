# Algorytmy optymalizacji dyskretnej<br>LISTA 4

### Autor : _Krzysztof Tałałaj_<br>Indeks : 254653<br>Data : 18.01.2022

## Opis folderów

1. app - pliki uruchamiające algorytmy tz. "main"
2. inc - pliki nagłówkowe algorytmów (.hpp)
3. src - pliki źródłowe algorytmów (.cpp)
4. out - pliki wynikowe testów i inne zapisane wyniki

## Uruchamianie

Aby skompilować i przetestować programy należy użyć komendy

```bash
make
make test # wykonuje testy
```

Aby zapisany model grafu rozwiązać przy użyciu JuMP w języku julia należy użyć komendy

```bash
./parser.jl [plik z zapisanym grafem].json
```

Aby uruchomić programy należy użyć komendy (argumenty w <> są opcjonalne)

```bash
[dinic/edmonds] -k [wymiar hiperkostki] <-printFlow> <-glpk [plik zapisowy].json>
```
