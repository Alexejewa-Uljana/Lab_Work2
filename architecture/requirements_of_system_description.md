# **System Requirements and Use Cases**

## **1. System Requirements**

### **1.1 Functional Requirements**

1. **Game Initialization and Progression**
   - The system must initialize the game world, load story elements, and track player progress.
   - Unlock new content based on player achievements.

2. **Player Mechanics**
   - Allow the player to manage a deck (add, remove, upgrade cards).
   - Track player health and mana, ensuring valid actions.
   - Provide an inventory for storing artifacts and items.
   - Support skill progression through a structured skill tree.

3. **Combat System**
   - Implement turn-based mechanics with alternating turns.
   - Validate card usage, ensuring sufficient mana and valid effects.
   - Apply status effects correctly and remove them when expired.
   - Allow drawing and discarding cards based on game rules.

4. **Enemy AI**
   - Control enemy actions with AI logic for strategic decision-making.
   - Differentiate between regular enemies and bosses, providing unique AI patterns.

5. **Rewards and Progression**
   - Grant rewards after battle, including new cards, artifacts, and experience.
   - Ensure progression unlocks new enemies, bosses, and story elements.

---

## **2. Use Cases**

### **2.1 Playing a Card**  
- The player selects a card from their hand.
- The system verifies that they have enough mana.
- The card’s effect is applied (damage, defense, status effects, etc.).
- The player's mana is updated, and the card is discarded if necessary.
- If the player lacks mana or a valid target, the action is denied.

### **2.2 Enemy Turn Execution**  
- The AI selects a valid move based on available cards and strategy.
- The system verifies the move and executes the action.
- If no valid moves exist, the enemy skips its turn.
- If an effect (e.g., stun) prevents the enemy from acting, the turn is skipped.

### **2.3 Winning a Battle**  
- The player wins when the enemy’s health reaches 0.
- The system grants rewards (cards, artifacts, experience).
- The game updates progression and unlocks new content.
- If the match ends in a draw, no rewards are granted.

This structure ensures **clear, predictable, and balanced gameplay mechanics** while maintaining system stability and modularity.
