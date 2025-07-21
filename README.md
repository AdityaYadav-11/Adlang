# AdLang 🚀
A toy programming language designed and built from scratch in C++.  
Currently in **Phase 1 (Lexer)**: converts source code into a stream of tokens.

---

## ✨ Overview

AdLang is a custom-designed programming language built as a solo project to explore how compilers and interpreters work under the hood.  
This project is being developed in **phases**, mimicking the real-world stages of language implementation.

---

## 🧠 Phase 1: Lexer (Completed)

The lexer (lexical analyzer) takes raw source code and converts it into a series of **tokens** such as:
- Keywords (`let`, `print`)
- Identifiers (`x`, `y`)
- Operators (`+`, `=`)
- Numbers (`5`, `2`)
- Symbols (`;`, `(`, `)`)

### ✔️ Example Input:
```plaintext
let x = 5 + 2;
print(x);
