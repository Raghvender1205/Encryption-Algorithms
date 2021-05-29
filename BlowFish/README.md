# BlowFish Algorithm
It is significantly faster than DES and provides a good encryption rate with no effective cryptanalysis technique found to date. It is one of the first, secure block cyphers not subject to any patents and hence freely available for anyone to use.

1. blockSize: 64-bits
2. keySize: 32-bits to 448-bits variable size
3. number of subkeys: 18 [P-array]
4. number of rounds: 16
5. number of subsitution boxes: 4 [each having 512 entries of 32-bits each]

Entire Encryption -> 

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20190929214411/encryption-blowfish.jpg">

## Step 1: Generation of SubKeys
* 18 subkeys{P[0]…P[17]} are needed in both encryption aswell as decryption process and the same subkeys are used for both the processes.
* These 18 subkeys are stored in a P-array with each array element being a 32-bit entry.
* It is initialised with the digits of pi(?)
* The hexadecimal representation of each of the subkeys is given by:
```
                                                    P[0] = "243f6a88"
                                                    P[1] = "85a308d3"
                                                    .
                                                    .
                                                    .
                                                    P[17] = "8979fb1b"
```
<code>P-Array</code>

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20190929204242/Parray.jpg">

* Now each of the subkey is changed with respect to the input key as:
```
                        P[0] = P[0] xor 1st 32-bits of input key
                        P[1] = P[1] xor 2nd 32-bits of input key
                        .
                        .
                        .
                        P[i] = P[i] xor (i+1)th 32-bits of input key 
                        (roll over to 1st 32-bits depending on the key length)
                        .
                        .
                        .
                        P[17] = P[17] xor 18th 32-bits of input key 
                        (roll over to 1st 32-bits depending on key length)
```

<b>The resultant P-array holds 18 subkeys that is used during the entire encryption process</b>

## Step 2: Initialize Substitution Boxes
1. 4 Substitution boxes(S-boxes) are needed{S[0]…S[4]} in both encryption aswell as decryption process with each S-box having 256 entries{S[i][0]…S[i][255], 0&lei&le4} where each entry is 32-bit.
2. It is initialised with the digits of pi(?) after initialising the P-array.

## Step 3: Encryption
1. The Encryption function consists of two parts: 
    1. <b>Rounds</b>: The encryption consists of 16 rounds with each round  (Ri) taking inputs the plainText(P.T.) from previous round and corresponding subkey(Pi). The description of each round is as follows:
    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20190929211024/round-blowfish1.jpg"> 
    
    The description of the Function 'F' is:
    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20190929212325/F-blowfish.jpg">
    Here, function "add" is addition modulo 2^32.

2. <b>Post-processing</b>: The output after the 16 rounds is processed as follows:
    
    <img src="https://media.geeksforgeeks.org/wp-content/uploads/20190929221708/pp-blowfish2.jpg">