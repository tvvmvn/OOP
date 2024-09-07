#include <iostream>
#include <unordered_map>

using namespace std;

// Flyweight class
class Character {
  public:
    Character(char intrinsicState) : m_intrinsicState(intrinsicState) {}

    void draw(int extrinsicState) {
      cout << "Drawing character '" << m_intrinsicState << "' at position " << extrinsicState << endl;
    }

  private:
    char m_intrinsicState;
};

// Flyweight factory
class CharacterFactory {
  public:
    Character *getCharacter(char key) {
      if (m_characters.find(key) == m_characters.end()) {
        m_characters[key] = new Character(key);
      }
      
      return m_characters[key];
    }

  private:
    unordered_map<char, Character *> m_characters;
};

int main() {
  CharacterFactory characterFactory;

  // Extrinsic state
  int position = 0;

  // Drawing characters 'A', 'B', 'C' at different positions
  characterFactory.getCharacter('A')->draw(position++);
  characterFactory.getCharacter('B')->draw(position++);
  characterFactory.getCharacter('C')->draw(position++);

  return 0;
}