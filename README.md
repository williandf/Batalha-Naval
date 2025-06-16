# 🛳️ Batalha Naval com Habilidades Especiais (Desafio Nível Mestre)

Este projeto é uma implementação progressiva do clássico **Batalha Naval** em linguagem C, desenvolvido como parte de uma série de desafios educacionais que visam o aprimoramento de habilidades em **vetores, matrizes, validações e lógica condicional**.

---

## 📌 Objetivo

Integrar as seguintes funcionalidades em um único programa:

- Representar o **tabuleiro 10x10**
- Posicionar **navios** de forma válida (horizontal, vertical e diagonal)
- Criar e aplicar **habilidades especiais** com áreas de efeito:
  - **Cone**
  - **Cruz**
  - **Octaedro**

---

## 🧩 Funcionalidades Implementadas

### ✅ Posicionamento de Navios

- Quatro navios com tamanho fixo 3:
  - 2 navios posicionados em direções ortogonais (horizontal e vertical)
  - 2 navios posicionados em diagonais (`\` e `/`)
- Validação para evitar **sobreposição** e **saída dos limites do tabuleiro**

### ✅ Habilidades Especiais

- **Matriz 5x5** para cada habilidade
- Áreas de efeito centralizadas no ponto de origem escolhido
- Regras de forma construídas dinamicamente com **loops e condicionais**
- As áreas atingidas são representadas no tabuleiro com o valor `5` (sem sobrepor navios)

---

## 💻 Tecnologias Utilizadas

- Linguagem C
- Terminal/Console
- GCC (ou compilador C equivalente)

---

## ▶️ Como Compilar e Executar

1. Clone este repositório ou copie o arquivo `Batalha.c`.
2. Compile com `gcc`:

```bash
gcc Batalha.c -o Batalha .\Batalha
