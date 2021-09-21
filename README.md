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
