typedef struct Node Node;

struct Node {
    int val;
    Node* next;
};

Node *init_list();
Node *insert_node(Node *llist, int new_val);
void print_list(Node *llist);