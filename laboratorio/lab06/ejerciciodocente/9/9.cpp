#include <iostream>
#include <queue>
using namespace std;

enum COLOR { RED, BLACK };

class Node {
public:
    int val;
    COLOR color;
    Node *left, *right, *parent;

    Node(int val) {
        this->val = val;
        parent = left = right = nullptr;
        // El nodo es creado durante la inserción
        // Nodo es rojo en la inserción
        color = RED;
    }

    // Retorna el puntero al tío
    Node* uncle() {
        // Si no hay padre o abuelo entonces tampoco tío
        if (parent == nullptr || parent->parent == nullptr)
            return nullptr;

        if (parent->isOnLeft())
            // tío a la derecha
            return parent->parent->right;
        else
            // tío a la izquierda
            return parent->parent->left;
    }

    // Comprobar si el nodo está en el hijo izquierdo del padre
    bool isOnLeft() {
        return this == parent->left;
    }

    // Retorna el puntero al hermano
    Node* sibling() {
        // hermano nulo si no hay padre
        if (parent == nullptr)
            return nullptr;

        if (isOnLeft())
            return parent->right;

        return parent->left;
    }

    // Mueve el nodo hacia abajo y se mueve el nodo dado en su lugar
    void moveDown(Node* nParent) {
        if (parent != nullptr) {
            if (isOnLeft())
                parent->left = nParent;
            else
                parent->right = nParent;
        }
        nParent->parent = parent;
        parent = nParent;
    }

    bool hasRedChild() {
        return (left != nullptr && left->color == RED) ||
               (right != nullptr && right->color == RED);
    }
};

class RBTree {
    Node* root;

    // Gira a la izquierda el nodo dado
    void leftRotate(Node* x) {
        // nuevo padre será el hijo derecho del nodo
        Node* nParent = x->right;

        // actualizamos la raíz si el nodo actual es raíz
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // conecta x con el elemento izquierdo del nuevo padre
        x->right = nParent->left;

        // conecta el elemento izquierdo del nuevo padre si no es nulo
        if (nParent->left != nullptr)
            nParent->left->parent = x;

        // conecta el nuevo padre con x
        nParent->left = x;
    }

    void rightRotate(Node* x) {
        // nuevo padre será el hijo izquierdo del nodo
        Node* nParent = x->left;

        // actualizamos la raíz si el nodo actual es la raíz
        if (x == root)
            root = nParent;

        x->moveDown(nParent);

        // conectar x con el elemento derecho del nuevo padre
        x->left = nParent->right;

        // conectar el elemento derecho del nuevo padre si es no nulo
        if (nParent->right != nullptr)
            nParent->right->parent = x;

        // conectar el nuevo padre con x
        nParent->right = x;
    }

    void swapColors(Node* x1, Node* x2) {
        COLOR temp = x1->color;
        x1->color = x2->color;
        x2->color = temp;
    }

    void swapValues(Node* u, Node* v) {
        int temp = u->val;
        u->val = v->val;
        v->val = temp;
    }

    // Arregla red red en el nodo dado
    void fixRedRed(Node* x) {
        // Si x es raíz, color negro y retornar
        if (x == root) {
            x->color = BLACK;
            return;
        }

        // inicializar padre, abuelo, tío
        Node* parent     = x->parent;
        Node* grandparent = parent->parent;
        Node* uncle      = x->uncle();

        if (parent->color != BLACK) {
            if (uncle != nullptr && uncle->color == RED) {
                // tío rojo, realizar la recolorización y reajustar
                parent->color      = BLACK;
                uncle->color       = BLACK;
                grandparent->color = RED;
                fixRedRed(grandparent);
            } else {
                // Sino realizamos LR, LL, RL, RR
                if (parent->isOnLeft()) {
                    if (x->isOnLeft())
                        // Para la izquierda izquierda
                        swapColors(parent, grandparent);
                    else {
                        leftRotate(parent);
                        swapColors(x, grandparent);
                    }
                    // Para izquierda izquierda e izquierda derecha
                    rightRotate(grandparent);
                } else {
                    if (x->isOnLeft()) {
                        // para la derecha izquierda
                        rightRotate(parent);
                        swapColors(x, grandparent);
                    } else
                        swapColors(parent, grandparent);

                    // para derecha derecha y derecha izquierda
                    leftRotate(grandparent);
                }
            }
        }
    }

    // Encontrar un nodo que no tenga un hijo izquierdo
    // en el subárbol de un nodo dado
    Node* successor(Node* x) {
        Node* temp = x;
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }

    // Encontrar el nodo que sustituye a un nodo eliminado en BST
    Node* BSTreplace(Node* x) {
        // cuando el nodo tiene 2 hijos
        if (x->left != nullptr && x->right != nullptr)
            return successor(x->right);

        // cuando es hoja
        if (x->left == nullptr && x->right == nullptr)
            return nullptr;

        // cuando tiene un solo hijo
        if (x->left != nullptr)
            return x->left;
        else
            return x->right;
    }

    // Elimina el nodo dado
    void deleteNode(Node* v) {
        Node* u = BSTreplace(v);
        // Verdadero cuando u y v son ambos negros
        bool uvBlack = ((u == nullptr || u->color == BLACK) && (v->color == BLACK));
        Node* parent = v->parent;

        if (u == nullptr) {
            // u es nullptr por lo tanto v es hoja
            if (v == root)
                root = nullptr;
            else {
                if (uvBlack)
                    // u y v ambos negros, fijar el negro doble como v
                    fixDoubleBlack(v);
                else if (v->sibling() != nullptr)
                    // hermano no es null, hazlo rojo
                    v->sibling()->color = RED;

                // eliminar v del árbol
                if (v->isOnLeft())
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
            }
            delete v;
            return;
        }

        if (v->left == nullptr || v->right == nullptr) {
            // v tiene 1 hijo
            if (v == root) {
                // v es raíz, asignar el valor de u a v y borrar u
                v->val = u->val;
                v->left = v->right = nullptr;
                delete u;
            } else {
                // Desconecta v del árbol y mueve u hacia arriba
                if (v->isOnLeft())
                    parent->left = u;
                else
                    parent->right = u;

                delete v;
                u->parent = parent;

                if (uvBlack)
                    // u y v ambos negros, fijar el doble negro en u
                    fixDoubleBlack(u);
                else
                    // u o v rojo, colorear u negro
                    u->color = BLACK;
            }
            return;
        }

        // v tiene 2 hijos, intercambia valores con sucesor y recurre
        swapValues(u, v);
        deleteNode(u);
    }

    void fixDoubleBlack(Node* x) {
        // Llegando a la raíz
        if (x == root)
            return;

        Node* sibling = x->sibling();
        Node* parent  = x->parent;

        if (sibling == nullptr)
            // No hay hermano, double black empujando hacia arriba
            fixDoubleBlack(parent);
        else {
            if (sibling->color == RED) {
                // hermano rojo
                parent->color  = RED;
                sibling->color = BLACK;

                if (sibling->isOnLeft())
                    rightRotate(parent);
                else
                    leftRotate(parent);

                fixDoubleBlack(x);
            } else {
                // hermano negro
                if (sibling->hasRedChild()) {
                    // al menos 1 hijo rojo
                    if (sibling->left != nullptr && sibling->left->color == RED) {
                        if (sibling->isOnLeft()) {
                            // izquierda izquierda
                            sibling->left->color = sibling->color;
                            sibling->color       = parent->color;
                            rightRotate(parent);
                        } else {
                            // derecha izquierda
                            sibling->left->color = parent->color;
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    } else {
                        if (sibling->isOnLeft()) {
                            // izquierda derecha
                            sibling->right->color = parent->color;
                            leftRotate(sibling);
                            rightRotate(parent);
                        } else {
                            // derecha derecha
                            sibling->right->color = sibling->color;
                            sibling->color        = parent->color;
                            leftRotate(parent);
                        }
                    }
                    parent->color = BLACK;
                } else {
                    // 2 hijos negros
                    sibling->color = RED;
                    if (parent->color == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->color = BLACK;
                }
            }
        }
    }

    // Imprime el orden de nivel de un nodo dado
    void levelOrder(Node* x) {
        if (x == nullptr)
            return;

        queue<Node*> q;
        Node* curr;

        q.push(x);

        while (!q.empty()) {
            curr = q.front();
            q.pop();
            cout << curr->val << " ";

            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    // Imprime inorder recursivamente
    void inorder(Node* x) {
        if (x == nullptr)
            return;

        inorder(x->left);
        cout << x->val << " ";
        inorder(x->right);
    }

    // Destructor auxiliar para liberar memoria
    void destroyTree(Node* node) {
        if (node == nullptr) return;
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

public:
    // Constructor: inicializa la raíz
    RBTree() {
        root = nullptr;
    }

    // Destructor: libera toda la memoria del árbol
    ~RBTree() {
        destroyTree(root);
    }

    Node* getRoot() {
        return root;
    }

    // Búsqueda de un valor dado
    Node* search(int n) {
        Node* temp = root;
        while (temp != nullptr) {
            if (n < temp->val) {
                if (temp->left == nullptr)
                    break;
                else
                    temp = temp->left;
            } else if (n == temp->val) {
                break;
            } else {
                if (temp->right == nullptr)
                    break;
                else
                    temp = temp->right;
            }
        }
        return temp;
    }

    // Insertar el valor dado en el árbol
    void insert(int n) {
        Node* newNode = new Node(n);
        if (root == nullptr) {
            newNode->color = BLACK;
            root = newNode;
        } else {
            Node* temp = search(n);

            // retorna si el valor ya existe
            if (temp->val == n) {
                delete newNode;
                return;
            }

            newNode->parent = temp;

            if (n < temp->val)
                temp->left = newNode;
            else
                temp->right = newNode;

            // arregla la violación red red si existe
            fixRedRed(newNode);
        }
    }

    // Elimina el nodo con el valor dado
    void deleteByVal(int n) {
        if (root == nullptr)
            return;

        Node* v = search(n);

        if (v->val != n) {
            cout << "No se encontró nodo con valor: " << n << endl;
            return;
        }

        deleteNode(v);
    }

    // Imprime inorder el árbol
    void printInOrder() {
        cout << "Inorder: " << endl;
        if (root == nullptr)
            cout << "Árbol vacío" << endl;
        else
            inorder(root);
        cout << endl;
    }

    // Imprime el nivel en orden del árbol
    void printLevelOrder() {
        cout << "Nivel en orden: " << endl;
        if (root == nullptr)
            cout << "Árbol vacío" << endl;
        else
            levelOrder(root);
        cout << endl;
    }
};

int main() {
    RBTree tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    tree.printInOrder();
    tree.printLevelOrder();

    cout << "\nBorrando 18, 11, 3, 10, 22\n" << endl;

    tree.deleteByVal(18);
    tree.deleteByVal(11);
    tree.deleteByVal(3);
    tree.deleteByVal(10);
    tree.deleteByVal(22);

    tree.printInOrder();
    tree.printLevelOrder();

    return 0;
}
