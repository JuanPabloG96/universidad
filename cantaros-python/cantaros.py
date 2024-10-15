from node import Node
from binaryTree import BinaryTree

tree = BinaryTree("root node")
nodo_izquierdo = Node("root node left")
nodo_derecho = Node("root node right")

tree.root.insert(nodo_izquierdo)
tree.root.insert(nodo_derecho)

nodo_izquierdo.insert(Node("test"))

tree.find("test")