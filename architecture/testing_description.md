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

## **3. Test Strategy**

### **3.1 Player Initialization Tests**  
These tests will verify that the `Player` object is correctly initialized, with proper values for health, mana, and deck state.

### **3.2 Card Play Tests**  
These tests will verify that cards are correctly played, the required mana is deducted, and the effects of the cards (e.g., damage, healing, or buffs) are applied correctly.

### **3.3 AI Behavior Tests**  
These tests will verify that the AI-controlled enemies make valid decisions based on the cards they have in their deck and the current game state. The AI should play optimally or follow predefined strategies.

---

## **4. Conclusion**  
The testing plan will ensure that all critical systems of the game, such as the combat mechanics, card interactions, and AI behavior, are functioning as expected. Through unit and integration tests using **Google Test**, we will verify that each component of the game behaves correctly and integrates smoothly, providing a reliable and stable gameplay experience.
