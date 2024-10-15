from node import Node

class BinaryTree:
    def __init__(self, root):
        self.root = Node(root)

    """ def find(self, data):
        return self._find(self.root, data)

    def _find(self, current_node, data):
        if current_node is None:
            print("the tree is empty")
            return None
        elif current_node.data == data:
            return current_node
        left_result = self._find(current_node.left, data)
        if left_result is not None:
            return left_result
        return self._find(current_node.right, data) """

    def _find(self, current_node, data, path=[]):
        if current_node is None:
            print("El árbol está vacío")
            return None, path
        elif current_node.data == data:
            path.append(current_node.data)
            return current_node, path
        left_result, left_path = self._find(current_node.left, data, path + [current_node.data])
        if left_result is not None:
            return left_result, left_path
        right_result, right_path = self._find(current_node.right, data, path + [current_node.data])
        return right_result, right_path

    def find(self, data):
        result, path = self._find(self.root, data)
        
        if result is not None:
            print(f"Node data '{data}' found in track: {path}")
        else:
            print(f"Node data '{data}' not found in tree")