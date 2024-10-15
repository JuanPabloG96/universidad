class Node:
  def __init__(self, data):
    self.data = data;
    self.left = None
    self.right = None
    
  def insert(self, node):
        if self.left is None:
            self.left = node
        elif self.right is None:
            self.right = node