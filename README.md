# 🎮 Mini Game Suite in C

**Created by:** Hrishikesh Pathak  

A menu-driven C project containing three interactive console-based games designed to strengthen core C programming concepts such as loops, arrays, strings, functions, and random number generation.

---

## 📌 Project Overview

This project is a collection of **three fun and logic-based games** implemented in C:

1. 🧩 Escape Room Puzzle  
2. 🔢 4-Digit Guessing Game  
3. 🧮 Maths Quiz  

The user can select any game from the menu and play until they choose to exit.

---

## 🛠️ Technologies Used

- Programming Language: **C**
- Compiler: **GCC / Turbo C / Any standard C compiler**
- Libraries:
  - `stdio.h`
  - `stdlib.h`
  - `string.h`
  - `time.h`

---

## 🎮 Game Descriptions

### 1️⃣ Escape Room Game

A logic-based puzzle game consisting of **three stages**:

- **Jumbled Word Puzzle**
  - Jumbled word: `IHTSAFLHGL`
  - Correct answer: `FLASHLIGHT`

- **Riddle**
  - *"I am tall when I am young and short when I am old."*
  - Answer: `candle`

- **Final Door Code**
  - Derived from the first letters of:
    - Flashlight
    - Candle
    - Light
  - Final code: `CFL`

The player must solve all stages to escape successfully.

---

### 2️⃣ 4-Digit Guessing Game

- The computer has a **secret 4-digit number** (default: `9153`)
- Player enters a 4-digit guess
- After each guess, the program shows:
  - Digits correct and in the **right position**
  - Digits correct but in the **wrong position**
- Game continues until all 4 digits are correctly guessed

This game is similar to the **Mastermind logic game**.

---

### 3️⃣ Maths Quiz Game

- User selects:
  - Difficulty level:
    - 1 → Easy
    - 2 → Medium
    - 3 → Hard
  - Number of questions
- Questions include:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- Score is calculated and displayed at the end

---

## 📋 Menu Structure

