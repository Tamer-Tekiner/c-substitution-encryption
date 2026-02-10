# Substitution Cipher (C)

This program implements a **substitution cipher** in C.

It takes a 26-letter key as a command-line argument, validates it, and encrypts plaintext entered by the user while preserving letter case.

---

## Features

- Key must contain **exactly 26 characters**
- Key must contain **only alphabetic characters**
- Key must contain **no repeated letters**
- Preserves **uppercase and lowercase**
- Non-alphabetic characters remain unchanged

---

## How to Compile

```bash
clang -o substitution substitution.c
