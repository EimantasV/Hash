# Naujas Hash:

failas HashNew.h

usage example - main2.cpp 

arba simply:
```
#import "HashNew.h"

...

  std::string result1 = HashHex("your input"); // gauni hex'u hash'a
  std::string result2 = HashBit("your input"); // gauni bit'u hash'a

```


## Senas Hash:
## Idėja:
```
hash[64]; // output

foreach (character in input)
{
    for (i=0;i<64;i++)
    {
        switch( ((int)character + i) % casesCount ) // case selection could be more random
        {
        case 0:
          hash[i] = hash[i] xor character; // bitwise operations are used for scrambling
          break;
        case 1:
          hash[i] = hash[i] xor (character BitwiseShiftLeft 1);
          break;
          // the more cases the better result
        }
    }
}

output = compressToHex(hash);
```
## Testai:

- [x] Nepriklausomai nuo input, output dydis vienodas.
- [x] Tas pats input duoda tą patį output.
- [x] 100000 porų hash'uose nėra kolizijų.

### Speed testai:

Laikas per kurį suhashavo konstitucija.txt kiekvieną eilutę:

| hash funckija | total time (ms) |
| ------------- | ----------------- |
| Mano          | 75                |
| SHA256        | 4                 |

### Skirtingumas:

Čia skaiciuojama kiek primo hash'o bitų nesutampa su kito hash'o bitais. Ir tai išreiskiama procentais.
- Bit difference min: 15.2344%
- Bit difference max: 75.3906%
- Bit difference avg: 49.421%

Čia sumuojami atstumai tarp simbolių ir suma padalinama iš (64*15). Hash'ų "0000....0000" ir "ffff.....ffff" skirtumas yra 100%;
- Hex difference min: 5%
- Hex difference max: 61.875%
- Hex difference avg: 31.4772%

### Trukumai:
- Lėtas.
- Labai lėtas, jei didelis input.

### Privalumai:
- Veikia. :D
- Lengva patobulinti.
