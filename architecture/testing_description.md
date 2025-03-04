# **Testing Plan with Google Test**

## **1. Overview**  
The goal of the testing plan is to ensure the correctness and reliability of the core mechanics in the game, including the **combat system**, **deck management**, **AI behavior**, and **card interactions**. This will be done through **unit tests** and **integration tests** using **Google Test (gtest)**.

---

## **2. Testing Scope**  

### **2.1 Unit Tests**

- **Player and Deck Management**:
  Test that the `Player` object is correctly initialized, can add/remove cards from the deck, and handles mana and health properly.

- **Combat Mechanics**:
  Verify that the `TurnManager` alternates turns between the player and the enemy.
  Ensure that the `AttackCard` and `DefenseCard` work as expected, applying the correct effects and modifying health and mana.

- **AI Behavior**:
  Validate that the `AIController` makes valid decisions based on available cards and combat strategies.

- **Card Effects**:
  Check that the `Effect` class applies and removes status effects correctly (e.g., poison, stun).

### **2.2 Integration Tests**  

- **Battle System**:
  Simulate a full battle between the player and the enemy, ensuring proper interaction of card effects, health, mana, and the turn system.

- **Skill and Reward Systems**:
  Test that winning a battle correctly updates the player's skill tree, inventory, and rewards system.

---
