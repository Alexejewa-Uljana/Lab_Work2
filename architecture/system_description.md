# **System Overview**  

This game is a **turn-based card RPG**. The core components include **player mechanics, combat system, AI-driven enemies, and deck-building elements**.

## **Main Components**  

### **Core System**  
- **`Game`** – The main manager that controls world events and battles.
- **`World`** & **`StoryManager`** – Handle game progression and events.

### **Player Mechanics**  
- **`Player`** – Manages health, mana, deck, and progression.
  - **`Deck`** – Stores cards for battles.
  - **`Inventory`** & **`Artifacts`** – Provide upgrades and bonuses.
  - **`SkillTree`** & **`CardUpgradeSystem`** – Enhance abilities and cards.
  - **`ManaSystem`** – Controls the player's mana usage.

### **Combat System**  
- **`BattleSystem`** – Handles turn-based combat.
  - **`TurnManager`** – Controls turn order.
  - **`Effect`** – Applies card effects in battles.

### **Enemies and AI**  
- **`Enemy`** & **`Boss`** – AI-driven opponents with unique decks.
  - **`AIController`** & **`BossAI`** – Manage enemy behavior.
  - **`EnemyDeck`** – Stores cards for enemies.

### **Rewards and Progression**  
- **`RewardSystem`** – Grants new cards, artifacts, or upgrades.

### **Cards and Decks**  
- **`Card`** – Base class for all cards.
  - **Includes:**
    - **`AttackCard`** – Deals damage to enemies.
    - **`DefenseCard`** – Provides shields or reduces damage.
    - **`MagicCard`** – Uses mana for special abilities.
    - **`SpecialCard`** – Unique mechanics that change gameplay.
    - **`StatusEffectCard`** – Applies status effects to enemies or the player.
