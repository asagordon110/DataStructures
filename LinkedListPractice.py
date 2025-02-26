class Pokemon:
  def __init__(self, name, type, evolution = None):
    self.name = name
    self.type = type
    self.is_caught = False
    self.evolution = evolution

  def print_pokemon(self):
    print({
      "name": self.name,
      "types": self.type,
      "is_caught": self.is_caught
    })

  def catch(self):
    self.is_caught = True

  def choose(self):
    if self.is_caught:
      print(f"{self.name} I choose you!")
    else:
      print(f"{self.name} is wild! Catch them if you can!")

  def add_type(self, new_type):
    self.type.append(new_type)
'''
def get_by_type(my_pokemon, pokemon_type):
  plist = []
  for pokemon in my_pokemon:
    if pokemon_type in pokemon.type: 
      plist.append(pokemon)
  return plist
''' 
def get_evolutionary_line(starter_pokemon):
  evolution_line = []
  current = starter_pokemon

  while current:
    evolution_line.append(current.name)
    current = current.evolution

  return evolution_line

class Node:
  def __init__(self, value, next=None):
    self.value = value
    self.next = next

def print_linked_list(head):
  result = []
  current = head

  while current:
    result.append(current.value)
    current = current.next

  print(" - > ".join(result))

#Tests
node_1 = Node("Mario")
a = node_1
node_2 = Node("Luigi")
node_3 = Node("Wario")
node_4 = Node("Toad")
node_5 = Node("Yoshi")

node_1.next = node_2
node_2.next = node_3
node_3.next = node_4
node_4.next = node_5

print_linked_list(a)