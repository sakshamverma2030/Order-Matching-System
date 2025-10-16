# Order matching System (C++)

A beginner-friendly terminal-based matching engine written in C++ that simulates buy/sell order flow using heaps and greedy logic.

---

## Features

- Guided input for buy/sell orders
- Real-time trade execution using heap-based matching
- Dynamic order book display (buy/sell snapshot)
- Trade history tracking
- Input validation and clean CLI formatting

---

##  DSA Concepts Used

| Concept             | Role in Project                          |
|---------------------|-------------------------------------------|
| Structs & Classes   | Modeling orders and trades                |
| Priority Queue      | Max-heap for buy orders, Min-heap for sell orders |
| Greedy Logic        | Matching best price orders immediately    |
| Vector              | Storing executed trades                   |
| Input Validation    | Preventing invalid entries                |
| Modular Design      | Scalable architecture (optional split)    |

---
##  Project Flow (Step-by-Step)

| Step | What Happens |
|------|--------------|
| 1️   | User enters order (type, quantity, price) |
| 2️   | Input is validated |
| 3️   | Order is stored in buy/sell heap |
| 4️   | Matching logic checks top buy/sell |
| 5️   | Trade is executed if prices match |
| 6️   | Quantity is adjusted and leftovers re-added |
| 7️   | Trade is stored in history |
| 8️   | Order book and trade history are displayed |
| 9️   | User decides to continue or exit |

---

##  How to Run

```bash
g++ main.cpp -o lob
./lob
-------------------------------------------

##  Sample Input
Order Type: buy  
Quantity: 100  
Price: 60  

Order Type: sell  
Quantity: 50  
Price: 58
 -----------------------------------------
##  Sample Output

Trade Executed: Rs58 x 50

=== Buy Orders ===  
[Rs60 x 50] (ID 1)

=== Sell Orders ===  
(none)

=== Trade History ===  
Buy ID 1 matched with Sell ID 2 at Rs58 x 50

👨‍💻 Author
Saksham Verma
