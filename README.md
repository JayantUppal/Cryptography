# Cryptography


## Description

A list of encryption algorithms to demonstrate concepts of Cryptography. Programmers and network professionals use cryptography to maintain secure communication and ensure the privacy of computer information.


## What's Included

### [Caesar-Cypher](/Caesar_Cypher.c)

  It is a mono-alphabetic cipher, also known as shift cipher wherein each letter of the plaintext is substituted by another letter to form the ciphertext. It is a     simplest form of substitution cipher scheme.

### [Substitution-Cypher](/Substitution_Cypher.c)
  Simple substitution cipher is the most commonly used cipher and includes an algorithm of substituting every plain text character for every cipher text character. In this process, alphabets are jumbled in comparison with Caesar cipher algorithm. A python script to list out all possibilities while decryption can be found [here](/Sub_Decypher.py).

### [Vignere-Cypher](/Vignere_Cypher.c)
  This cipher uses a text string (say, a word) as a key, which is then used for doing a number of shifts on the plaintext.

### [Playfair-Cypher](/Playfair_Cypher.c)
  In this, pairs of letters are encrypted, instead of single letters as in the case of simple substitution cipher. Also, initially a key table is created. The key table is a 5×5 grid of alphabets that acts as the key for encrypting the plaintext.

### [Rivest-Shamir-Adleman(RSA)](/RSA.c)
  RSA encryption, in full Rivest-Shamir-Adleman encryption, is widely used for data encryption of e-mail and other digital transactions over the Internet. It is an asymmetric system, which means that a key pair will be generated, a public key and a private key, obviously, you keep your private key secure and pass around the public one.

### [Diffie-Hellman Key Exchange](/Diffie_Hellman.c)
  Diffie Hellman algorithm is an asymmetric algorithm used to establish a shared secret for a symmetric key algorithm.
