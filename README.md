# Hash
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
- [x] 100000 porų hash'uose nėra koliziju.

### Speed testai:

Laikas per kurį suhashavo konstitucija.txt kiekvieną eilutę:

| hash funckija | total time (ms) |
| ------------- | ----------------- |
| Mano          | 75                |
| SHA256        | 4                 |

### Skirtingumas:

- Bit difference min: 15.2344%
- Bit difference max: 75.3906%
- Bit difference avg: 49.421%

### Trukumai:
- Lėtas.
- Labai lėtas, jei didelis input.

### Privalumai:
- Veikia. :D
- Lengva patobulinti.
