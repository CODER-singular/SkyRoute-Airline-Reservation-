# ✈️ SkyRoute Airlines — Flight Reservation System

A terminal-based domestic flight seat reservation and booking system 
developed in C++ as a Programming Fundamentals final project at 
COMSATS University Islamabad, Lahore Campus.

---

## 📋 Project Overview

SkyRoute Airlines simulates a complete airline booking experience 
entirely within the terminal. Users can select flights between 5 
Pakistani airports, view a live seat map, book seats for multiple 
passengers, process a payment with OTP verification, and receive 
a generated boarding pass saved as a .txt file.

---

## ⚙️ Technical Implementation

- 3 x 12x4 2D arrays representing seat maps for 3 daily flight slots
- Struct-based passenger data model passed by reference across 9 functions
- Nested do-while loops for input validation on every field
- fstream file I/O for boarding pass generation per booking
- OTP-verified payment with Sleep() loading animation
- toupper() character-by-character string conversion for city input
- switch-based seat array routing by time slot
- Bool flag pattern for occupied seat retry logic

---

## 🛫 Features

- 5 domestic airports: LHR, ISB, KHI, SIAL, SKD
- 3 daily flights: 04:00 AM, 03:00 PM, 11:00 PM
- Business Class (Rows 1-3) and Economy Class (Rows 4-12)
- Multi-passenger booking (adults + children with 50% child fare)
- Return ticket support with doubled pricing
- Interactive seat map showing [X] occupied and [O] available
- Credit card + CVC + OTP payment flow
- Auto-generated boarding pass as .txt file

---

## 🗂️ Concepts Used

| Concept | Application |
|---|---|
| 2D Arrays | Seat maps for 3 flight slots |
| Struct | Passenger data model |
| Pass by Reference | Data sharing across 9 functions |
| do-while Loops | Input validation throughout |
| for Loops | Seat display, multi-passenger booking |
| switch | Menu routing, seat array selection |
| fstream | Boarding pass file generation |
| File Handling | .txt output per passenger |

---

## 👥 Team

| Name | Registration |
|---|---|
| Muhammad Hassan Sharif | FA25-BCE-071 |
| Muhammad Daniyal | FA25-BCE-065 |
| Talha Zafar | FA25-BCE-125 |

**Course:** Programming Fundamentals
**Instructor:** Dr. Arsla
**University:** COMSATS University Islamabad, Lahore Campus
**Semester:** Spring 2025

---

*From Johar Town, with love :)*
