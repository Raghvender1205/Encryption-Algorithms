# DES (Data Encryption Standard)
It is vulnerable to powerful attacks so its popularity is declining

## Introduction
DES is a block cipher, it encrypts data in blocks of size 64 bit each.

The Same Algorithm and key are used for encryption and decryption with minor differences.
The Key length is 56 bits.

Basic Idea is like this
<img src='https://media.geeksforgeeks.org/wp-content/uploads/20200306122641/DES-11.png'></img>

We have mention that DES uses a 56 bit key. Actually, the initial key consists of 64 bits. However, before the DES process even starts, 
every 8th bit of the key is discarded to produce a 56 bit key. That is bit position 8, 16, 24, 32, 40, 48, 56 and 64 are discarded.

<img src='https://media.geeksforgeeks.org/wp-content/uploads/222-8.png'></img>

Thus, the discarding of every 8th bit of the key produces a 56-bit key from the original 64-bit key.

DES is based on the two fundamental attributes of cryptography: substitution (also called as confusion) and transposition (also called as diffusion). 
DES consists of 16 steps, each of which is called as a round. Each round performs the steps of substitution and transposition. 
Let us now discuss the broad-level steps in DES.

* In the first step, the 64 bit plain text block is handed over to an initial Permutation (IP) function.
* The initial permutation performed on plain text.
* Next the initial permutation (IP) produces two halves of the permuted block; says Left Plain Text (LPT) and Right Plain Text (RPT).
* Now each LPT and RPT to go through 16 rounds of encryption process.
* In the end, LPT and RPT are rejoined and a Final Permutation (FP) is performed on the combined block
* The result of this process produces 64 bit cipher text.
<img src='https://media.geeksforgeeks.org/wp-content/uploads/20200306124326/Steps-in-DES.png'/>

## Initial Permutation
Initial permutation (IP) happens only once and it happens before the first round. It suggests how the transposition in IP should proceed.

For example, it says that the IP replaces the first bit of the original plain text block with the 58th bit of the original plain text, the second bit with the 50th bit of the original plain text block and so on.

This is nothing but jugglery of bit positions of the original plain text block.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/444-3.png"/>

As we have noted after IP done, the resulting 64-bit permuted text block is divided into two half blocks. Each half block consists of 32 bits, and each of the 16 rounds.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/555-5.png"/>

## Step 1: Key Transformation
We have noted initial 64-bit key is transformed into a 56-bit key by discarding every 8th bit of the initial key. 

Thus, for each a 56-bit key is available. From this 56-bit key, a different 48-bit Sub Key is generated during each round using a process called as key transformation.

For this the 56 bit key is divided into two halves, each of 28 bits. These halves are circularly shifted left by one or two positions, depending on the round.

For example, if the round number 1, 2, 9 or 16 the shift is done by only position for other rounds, the circular shift is done by two positions. The number of key bits shifted per round is show in figure.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/666-2.png">

After an appropriate shift, 48 of the 56 bit are selected. for selecting 48 of the 56 bits the table show in figure given below.

For instance, after the shift, bit number 14 moves on the first position, bit number 17 moves on the second position and so on. If we observe the table carefully, we will realize that it contains only 48 bit positions.

Bit number 18 is discarded (we will not find it in the table), like 7 others, to reduce a 56-bit key to a 48-bit key. Since the key transformation process involves permutation as well as selection of a 48-bit sub set of the original 56-bit key it is called <b>Compression Permutation</b>.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/777.png">

Because of this compression permutation technique, a different subset of key bits is used in each round. That’s make DES not easy to crack.

## Step 2: Expansion Permutation
Recall that after initial permutation, we had two 32-bit plain text areas called as Left Plain Text(LPT) and Right Plain Text(RPT).

During the expansion permutation, the RPT is expanded from 32 bits to 48 bits. Bits are permuted as well hence called as expansion permutation. This happens as the 32 bit RPT is divided into 8 blocks, with each block consisting of 4 bits.

Then, each 4 bit block of the previous step is then expanded to a corresponding 6 bit block, i.e., per 4 bit block, 2 more bits are added.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/999-1.png"/> 

This process results into expansion as well as permutation of the input bit while creating output.

Key transformation process compresses the 56-bit key to 48 bits. Then the expansion permutation process expands the 32-bit RPT to 48-bits.

Now the 48-bit key is XOR with 48-bit RPT and resulting output is given to the next step, which is the <b>S-Box substitution</b>.