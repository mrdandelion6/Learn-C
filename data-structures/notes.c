#define _GNU_SOURCE

#include "helpers.h"
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int TEX_SUPPORT = 1; // want a mutable variable

int main(int argc, char* argv[]) {

    if (argc > 1) {
        if (strcmp(argv[1], "tex") == 0) {
            TEX_SUPPORT = 1;
        }
    }

    // welcome to my notes on data structures.
    int making_the_most_of_my_notes();
    int main_topics();
    int ADTs();
    int counting_steps();
    int balanced_trees();
    int avl_trees();
    int union_of_AVLs();
    int weighted_balance_trees();
    int priority_queues();
    int intro_to_graphs();
    int breadth_first_search();
    int depth_first_search();
    int directed_graphs();
    int strongly_connected_components();
    int dijkstras_algorithm();

    // run
    dijkstras_algorithm();

    return 0;
}

int making_the_most_of_my_notes() {
    // text notes for data structures might not be the best for learning, especially for those who are new.

    // while these notes are nice and compact, without a visual representation, it can be hard to understand the concepts.

    // that's why i have a folder with figures and diagrams which can be renfered in an output.pdf file if you have a latex compiler installed and in the PATH of where you execute this program.

    // to enable this feature, keep TEX_SUPPORT as 1 at the top of this file, or set it to 0 to disable it if you don't have latex installed.

    // these diagrams really help but are not crucial to these notes as i explain with text and pseudocode quite a bit anyways.

    // you can also pass the argument "tex" to the program to enable the latex output if you want to keep the TEXT_SUPPORT variable as 0.
}

int main_topics() {
    // the main topics ill go over in these notes:

    // 1. balance trees
    // 2. hash tables
    // 3. intro_to_graphs
    // 4. disjoint sets
    // 5. priority queues
    // 6. amortized analysis

    return 0;
}

int ADTs() {
    // ADT: Abstract Data Type
    // an ADT defines:
        // a set of objects
        // a set of operations that can be performed on said objects
        // possibly also their time and space costs (memory and performance)
        // DOESN'T DEFINE HOW THEY ARE IMPLEMENTED!!

    // the implementations of ADTs are called data structures

    // some things that make ADTs great
        // they just provide a specification; a framework for how things work
        // modularity: you can change the implementation without changing the interface
        // reusability: you can use the same ADT in different programs

    return 0;
}

int counting_steps() {
    int xlx = __LINE__; // for latex typesetting, just ignore.

    // lets take a look at the following algo. we will see how we can count the total number of steps.
    #define N 10
    int A[N] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int i = 1;
    while ( i < N ) {
        int v = A[i];
        int j = i;

        while ( j > 0 && A[j-1] > v ) {
            A[j] = A[j-1]; // move all the values up
            j--;
        }

        A[j] = v;
        i++;
    }
    // sorts the array to ascending
    // note at each iteration of the outer loop, the array is sorted up to i
    // this algorithm is known as insertion sort and has a worst case time complexity of O(n^2)

    // the inner while loop moves our 'v' value to its proper place in the sorted sublist (that goes up to i).
    print_int_arr(A, N);

    // lets try to count the steps this algorithm takes

    // COUNTING STEPS
        // getting/setting variables is 1 step
        // function call: 1 step for the call + 1 step to evaluate each argument + the steps inside the function
        // return statement: 1 step + the steps to evaluate the return value 
        // if/while condition: 1 step + the steps to evaluate the expressions
        // assignment: 1 step + the steps to evaluate the expression
        // arithmetic/boolean operators: 1 + the steps to evaluate the operands
        // array access: 1 step + the steps to evaluate the index
        // constants: free, they don't need to be evaluated

    // we can find the total steps by calculating the "cost" of each line and then multiplying by the "frequency"; the number of times that line runs.
    // lets count the steps for the insertion sort algorithm

    i = 1; 
    // 2 steps: 
        // - 1 for initializing (setting i)
        // - 1 for assigning 1 to i

    while ( i < N ) { 
    // 2 steps:
        // 1 for boolean comparison
        // 1 for evaluating (getting) i
        // 0 for "evaluating" N; it's a constant cause it's a macro
    // note that if we had len(A) instead (like for python), we would have 5 steps
            // 1 for boolean comparison
            // 1 for evaluating (getting) i
            // 1 for function call of len()
            // 1 for evaluating the argument A
            // 1 for returning the value of len()

        int v = A[i];
        // 5 steps:
            // 1 for assigning v
            // 1 for setting v
            // 1 for getting A
            // 1 for getting i
            // 1 for index access

        int j = i;
        // 3 steps:
            // 1 for setting j
            // 1 for assigning i to j
            // 1 for getting i

        while ( j > 0 && A[j-1] > v ) {
        // 10 or 3 steps:
        // 3 steps, happens if j <= 0:
            // 1 for while condition
            // 1 for boolean comparison
            // 1 for getting j
        // 10 steps, happens if j > 0:
            // 1 for while condition
            // 1 boolean comparison for j > 0 && A[j-1] > v (the whole thing)
            // 1 for boolean comparison j > 0
            // 1 for getting j
            // 1 for boolean comparison A[j-1] > v
            // 1 for getting A
            // 1 for getting j
            // 1 for calculating j-1
            // 1 for index access
            // 1 for getting v
    
            A[j] = A[j-1]; // move all the values up
            // 8 steps
                // 1 for getting A
                // 1 for getting j
                // 1 index access
                // 1 for assigning A[j-1] to A[j]
                // 1 for getting A
                // 1 for getting j
                // 1 for calculating j-1
                // 1 for index access

            j--; // j = j - 1
            // 4 steps:
                // 1 for getting j
                // 1 for assigning j-1 to j
                // 1 for getting j
                // 1 for calculating j-1
        }

        A[j] = v;
        // 5 steps:
            // 1 for getting A
            // 1 for getting j
            // 1 for index access
            // 1 for assigning v to A[j]
            // 1 for getting v

        i++; // i = i + 1
        // 4 steps:
            // 1 for getting i
            // 1 for assigning i+1 to i
            // 1 for getting i
            // 1 for calculating i+1
    }

    // now lets determine the WORST CASE frequency of each line. then we can multiply the cost by the frequency to get the total steps.
    
    i = 1; // 1 frequency
    while ( i < N ) { // N frequency: N-1 true + 1 false
        // the reason it's N-1 times true is because we loop N-1 times before it's false [1, N-1] inclusive.
        // would've been N times if i started at 0

        int v = A[i]; // 1 * (N-1) freq, recall N-1 times true
        int j = i; // 1 * (N-1) freq

        while ( j > 0 && A[j-1] > v ) { // (i + 1) * (N-1) freq : but i is not constant, it changes each iteration
            // worst case is loop runs all i times true, from j = i to j = 1 and 1 time false for j = 0
            // we use i because we can evaluate the sum later 
            // however, note that when calculating the total cost, we apply i for the "true" steps, and 1 for the "false" steps
            // this is because the true steps run i times and the false step just runs once.
            // recall the true steps were 10 and the false ones were 3, so we would have 10i + 3 for the total cost, and this would happen N - 1 times.
            A[j] = A[j-1]; // 1 * (i) * (N-1) freq
            j--; // 1 * (i) * (N-1) freq
        }

        A[j] = v; // 1 * (N-1) freq
        i++; // 1 * (N-1) freq
    }

    // now let's calculate the total cost.
    
    i = 1; // line 1
    while ( i < N ) { // line 2
        int v = A[i]; // line 3
        int j = i; // line 4

        while ( j > 0 && A[j-1] > v ) { // line 5
            A[j] = A[j-1]; // line 6
            j--; // line 7
        }

        A[j] = v; // line 8
        i++; // line 9
    }

    // line 1:
        // 2 steps * 1 freq = 2 total
    
    // line 2: (let's assume we have i < len(A) instead of i < N, so 5 steps).
        // 5 steps * N = 5N

    // line 3:
        // 5 steps * (N-1) = 5N - 5

    // line 4:
        // 3 steps * (N-1) = 3N - 3

    // line 8:
        // 5 steps * (N-1) = 5N - 5

    // line 9:
        // 4 steps * (N-1) = 4N - 4

    // so excluding the inner while loop, we have:
    // 2 + 5N + 5N - 5 + 3N - 3 + 5N - 5 + 4N - 4 = 22N - 22 + 2 
    // = 22N - 15

    // now let i be the i'th iteration of the outer loop
    // for the inner loop, we then have the following cost at each iteration of the outer loop:
    
    // line 5:
        // 10i + 3 steps

    // line 6:
        // 8i steps
    
    // line 7:
        // 4i steps

    // then in total, our while loop has the following cost:
    // (see the latex output.pdf file in this directory)
    
    if (TEX_SUPPORT) {
        new_tex("\\textbf{worst case cost}\n\nour cost of the inner loop is:\n");

        add_tex_output(
            "\\begin{align*}\n"
            "&\\sum_{i=1}^{N-1} (10i + 3) + 8i + 4i\\\\\n"
            "=&\\sum_{i=1}^{N-1} 22i + 3\n"
            "\\end{align*}"
        );

        add_tex_output(
            "so our total cost is:\n"
            "\\begin{align*}\n"
            "& 22N - 15 + \\sum_{i=1}^{N-1} 22i + 3\\\\\n"
            "&= 22N - 15 + 22\\frac{(n-1)n}{2} + 3 (n-1)\\\\\n"
            "&= 11n^2 + 14n - 18\n"
            "\\end{align*}"
        );

        // for the best cost, we can assume the inner loop runs 0 times, with only 1 false check.
        // this would give us a frequency of N-1 for line 5 and 0 for line 6 and 7

        // so the best case cost is:
        // 22N - 15 + (N-1)*10 = 32N - 25
        add_tex_output(
            "\\textbf{best case cost}\n\n"
            "\\vspace{5mm}\n"
            "for the best case, the inner loop runs 0 times, so we have:\n"
            "\\begin{align*}\n"
            "& 22N - 15 + 10(N-1)\\\\\n"
            "&= 32N - 25\n"
            "\\end{align*}"
        );
    }

    return 0;
}

int balanced_trees() {
    // recall BSTs (binary search trees) 
    // BSTs are a type of binary tree where the left child is less than the parent and the right child is greater than the parent
    // eg:

    //      5
    //     / \
    //    3   7
    //   /   / \
    //  1   6   8

    // we can also choose <= for left or >= for right, it is a design decision.

    // searching in a BST actually has a worst case time complexity of O(n) if the tree is unbalanced. for example:

    //      1
    //       \
    //        2
    //         \
    //          3
    //           \
    //            4
    //             \
    //              5

    // this is akin to a linked list, and searching for 5 would take 5 steps.
    // to avoid this, we can use a balanced tree!
    // maintain a BST that always stays balanced. so the height of the tree is always log(n) where n is the number of nodes.

    // we have a few options for balanced trees:
        // AVL trees
        // red-black trees
        // splay trees
        // B-trees

    // in the next section we are going to explore AVL trees.

    return 0;
}

int avl_trees() {
    // AVL trees are a type of balanced binary search tree
    // they are named after their inventors: Adelson-Velsky and Landis
    // AVL trees work by maintaining a BALANCE FACTOR for each node
    // the balance factor of a node is the height of the left subtree - the height of the right subtree
        // balance_factor = height(left) - height(right)

    // AVL trees must maintain a balance factor of -1, 0, or 1 for each node
    
    // SEARCHING IN AVL
    // searching in an AVL tree is the same as searching in a BST

    // INSERTING INTO AN AVL TREE
    // when inserting into an AVL tree, we first insert the node as we would in a BST
    // then we update the balance factors of the nodes on the path from the root to the new node
    // if the balance factor of any node becomes -2 or 2, we need to rebalance the tree!
    // we can do this by "rotating" the tree

    // eg, consider the tree:
    //                              
    //                44   (-1)        // numbers in brackets are the balance factors. no brackets means 0
    //              /    \             //  leaves always have a balance factor of 0
    //            32       78  (1)
    //           /  \     /  \
    //         17   35   50   88
    //                  /  \
    //                48    62

    // adding a 45 would make the tree unbalanced!

    //                44   (-2)
    //              /     \            
    //            32         78  (2)
    //           /  \      /    \
    //         17   35   50 (1)   88
    //                  /  \
    //                48    62
    //               /
    //              45  

    // so we will "rotate" the tree to rebalance it. 
    // we pick the lowest node with a balance factor of 2 or -2, and rotate it in the direction that will balance the tree.
    // in this case we would rotation 78 to the right

    //                44   (-1)
    //              /     \
    //            32       50  (0)
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                45    62   88

    // now the tree is balanced!

    // let's go over how ROTATIONS work in a little more depth
    // there are two types of rotations: CW and CCW

    // we do a CW rotation when the balance factor > 1, like in the example above
        // ie) the left subtree is too deep
        // during CW rotation:
        // 1. replace the parent with the left child, 
        // 2. make the left child's right child the parent's left child
        // 3. make the parent the right child of the left child
        // this can be seen from the example above and takes O(1) time

    // we do a CCW rotation when the balance factor < -1
        // ie) the right subtree is too deep:A
        // during CCW rotation:
        // 1. replace the parent with the right child
        // 2. make the right child's left child the parent's right child
        // 3. make the parent the left child of the right child

    // note that sometimes we need to do a DOUBLE ROTATION to balance the tree
    // this is when we have a zig-zag pattern in the tree
    // or more simply, when any child of the parent node we are rotating has a balance factor of the opposite sign 
    // for example, say we want to insert 46 into the tree:

    //                 44   (-1)
    //              /     \
    //            32       50  (0)
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                45    62   88

    // we get:

    //                 44   (-2)
    //             /       \
    //          32          50 
    //         /  \       /     \
    //       17   35    48 (2)    78
    //                  /        /   \
    //                45 (-1)   62    88
    //                  \
    //                   46

    // note how 48 is our problem node, and it has a balance factor of 2
    // and that a child of 48, 45, has a balance factor of -1, which is the opposite sign
    // hence we will need to do a double rotation to balance the tree
    // first we will have to do a CCW rotation on 45, then a CW rotation on 48

    // first rotation:

    //                 44   
    //              /     \
    //            32       50  
    //           /  \     /  \
    //         17   35   48   78
    //                  /    /  \
    //                46    62   88
    //               /
    //              45

    // second rotation:

    //                 44   
    //             /       \
    //          32          50  
    //        /  \        /    \
    //      17   35     46     78
    //                 /  \    /  \
    //                45  48  62   88

    // in the next section we will go over how to implement an AVL tree in C

    return 0;
}

// we will implement an AVL tree in C in the following functions, see avl_implementation() for examples

typedef struct AVLNode {
    int value;
    int balance_factor;
    struct AVLNode* left;
    struct AVLNode* right;
} AVLNode;

AVLNode* AVL_init(int val) {
    AVLNode* new = malloc(sizeof(AVLNode));
    new->value = val;
    new->balance_factor = 0;
    new->left = NULL;
    new->right = NULL;
    return new;
}

int AVL_isleaf(AVLNode* tree) {
    return tree->left == NULL && tree->right == NULL;
}

int AVL_height(AVLNode* tree) {
    if (tree == NULL) {
        return 0;
    }
    int rh = AVL_height(tree->right);
    int lh = AVL_height(tree->left);
    return rh >=  lh ? 1 + rh : 1 + lh;
}
 
AVLNode* AVL_edge_find(AVLNode* tree, int val) {
    // return a valid edge node in tree which a new node containing val can be attached to while maintaining the BST property
    if ( tree->value == val ) {
        return tree; // return the node itself when it matches the value exactly
    }

    if ( val >= tree->value && tree->right != NULL ) {
        return AVL_edge_find(tree->right, val);

    }
    if ( val < tree->value && tree->left != NULL ) {
        return AVL_edge_find(tree->left, val);
    }

    return tree;
}

int AVL_insert(AVLNode* tree, int val) {
    AVLNode* new = AVL_init(val);
    AVLNode* parent = AVL_edge_find(tree, val); 
    if (parent->value >= val) {
        parent->right = new; // parent-> right should be NULL
        parent->balance_factor--;
    } else {
        parent->left = new; // parent-> left should be NULL
        parent->balance_factor++;
    }

    

    return 0;
}


int avl_implementation() {
    // TODO: copy over the implementation from closestAVL project
    

    return 0;
}

int augmented_data_structures() {
    // "augmented data structure" is a fancy term for an existing data structure modified to store additional information and / or perform additional operations.

    // lets make a task for ourselves: design a DS that implements an ordered set/dict and in addition to insert, delete, search, union, etc,. also supports two types of RANK QUERIES:
        // 1. RANK(S, k): given a key k in set S, what is the rank of k in S? ie: the key's position among the elements of S
        // 2. SELECT(S, r): given a rank r in set S, which key in S has rank r?

    // for example, in the set of values S = {3, 15, 27, 30, 35, 56}
    // rank(S, 15) = 2
    // select(S, 4) = 30

    // we can implement this using an AVL tree
    // for rank:
        // in-order traversal of the tree, and count the number of nodes visited until we reach the key
    // for select:
        // in order traversal of the tree, and return the key when we reach the r'th node

    // what is the complexity of rank? O(n)
    // what is the complexity of select? O(n)

    // note that our search, insert, delete operations do not need to change.

    // IDEA 1:
    // store rank in each node n in the tree T
    
        // rank(T, k): search for n such that n.key = k, return n.rank -> O(log(n))
        // select(T, r): search for n such that n.rank = r, return n.key -> O(log(n))

    // note that with this idea, our search, insert, and delete operations will have to change to update the rank of each node whenever we insert and delete!
    // kind of tedious

    // IDEA 2:
    // store the size of the subtree rooted at each node n in the tree T
    // how is size related to rank? 
    // define RELATIVE-RANK, rank(n, k) as rank of key k relative to the keys in the tree rooted at node n

        // rank(T, k): 1 + number of keys in T than are less than k
        // rank(n, n.key) = 1 + size(n.left)

        // we can use this to form an O(log(n)) algorithm for rank and select!

    //  rank(T, k) in O(log(n)):
    // to find the rank of k in T, we can do a binary search for k in T and keep track of the rank as we go down the tree.

    // 1. base case: if k == n.key, return 1 + size(n.left)
    // 2. if k < n.key, return rank(n.left, k)
    // 3. if k > n.key, return 1 + size(n.left) + rank(n.right, k)

    //  select(T, r) in O(log(n)):
    // to find the key with rank r in T, we also do a binary search! this time, we traverse the tree and compare the rank of the current node to r. in our recursion, we will have to change the value of r as we go down the tree. it will make more sense when we see the algo:

    // 1. base case: if r == size(n.left) + 1, return n.key
    // 2. if r < (size.nleft) + 1, return select(n.left, r)
    // 3. if r > (size.nleft) + 1, return select(n.right, r - 1 - size(n.left))

    // now everything is in O(log(n))
    return 0;
}

int union_of_AVLs(){
    // so far we have taken a look at the following operations on AVLs:
    // 1. search
    // 2. insert
    // 3. delete
    // 4. rank
    // 5. select

    // now we will explore returning the union, intersections, and difference of AVL trees
    
    // UNION OF AVL TREES
    // suppose we have two AVL trees G and L
    // size(G) = n, size(L) = m, and n <= m

    // simple approach for union:
    // just add all the nodes of G to L
    // each insertion is O(log(m + n)), and we have n insertions
    // hence, the complexity of the union is O(n*log(m + n))

    // a better approach: divide and conquer

        // recap of divide and conquer: split the input into smaller pieces and solve the problem on each piece, then combine the results

        // some eg: merge sort, quick sort, binary search in array, etc.

    // we can use divide and conquer to find the union of two AVL trees
        // split G into smaller trees
        // split L into smaller trees
        // build unions of G and L
        // merge results from union of G and L

    // lets see how we can SPLIT an AVL tree
        // suppose tree L has key k at its root node
        // split G into two trees: G<k and G>k, both balanced
        // split(T, k): returns (T<k, T>k)

    // example
    //           25
    //         /    \
    //       14       30
    //      /  \     / 
    //    12   17   27
    // say we want to split at 16
    // we want {12, 14} and {17, 25, 27, 30} as the result
    // we split the left subtree into (L, R) = ({12, 14}, {17})
    // T<k is {12, 14}, the left the above split
    // T>k is join({17}, 25, {27, 30})

    // so our split(T, k) algorithm will be as follows:
    
    // if T == null:
    //    return (null, null)
    // if k == T.key:
    //    return (T.left, T.right)

    // if k < T.key:
    //    (L, R) = split(T.left, k)
    //    R' = join(R, T.key, T.right)
    //    return (L, R')

    // if k > T.key:
    //    (L, R) = split(T.right, k)
    //    L' = join(T.left, t.key, L)
    //    return (L', R)

    // let's understand this recursion a bit better:
        // our bases cases are fairly simple, we just return the left and right subtrees when we find the key or pairs of  NULLs when we reach a null node

        // when the k < T.key, that means the split needs to happen in the left subtree.  but the right part of the split in the left subtree also needs to be joined with the stuff from the parent node. specifically, the parent node itself and the right subtree of the parent node need to be joined with the left subtrees right child

        // for visualization, see output.pdf
            // you can see the blue nodes are the left split. the red nodes are the righ split WITHIN the subtree. they need to be joined with all the white nodes.

    
    if (TEX_SUPPORT) {
        new_tex(
            "\\begin{mypar}\n"
            "\\textbf{splitting an AVL tree}\n\n"
            "let's split the AVL tree at 16\n\n"
            "\\begin{forest}\n"
            "for tree={circle,draw,minimum size=2em,edge={-latex}, calign=edge midpoint}\n"
            "[25\n"
            "    [14, fill=blue, opacity=0.5\n"
            "        [12, fill=blue, opacity=0.5]\n"
            "        [17, fill=red, opacity=0.5]\n"
            "    ]\n"
            "    [30\n"
            "        [27]\n"
            "       [ ,phantom]\n"
            "    ]\n"
            "]\n"
            "\\end{forest}\n"
            "\\end{mypar}"
        );
    }


    // now lets see how we can JOIN two AVL trees
    // join(G, k, L): returns a new AVL tree with root k and subtrees G and L/ k is the root of L

    // join(G, k, L):
        // note that, G <= k <= L

    // NULL cases 
    // if G == null:
    //    return insert(L, k)
    // if L == null: 
    //    return insert(G, k)

    // NO BALANCE CASE 
    // if |height(G) - height(L)| <= 1:
    //    return new AVL tree with root k, left G, right L

    // BALANCE CASE 
    // if height(G) > height(L) + 1: 
        // insert k and L into G 

    // if height(L) > height(G) + 1: 
        // insert k and G into L

    // note that when we insert the trees, we don't just insert all the nodes of L into G or vice versa. we do it in a more efficient way!

    // inserting G into L:
    // in this case height(L) > height(G) + 1

        // in L, keep going right to find the node p, which satisfies:
            // 1.) p is still too tall: height(p) > height(G) + 1
            // 2.) p.right is just right: height(p.right) <= height(G) + 1
        // create a new node q with key k, left child p.right, and right child G. this node becomes p's new right child
        // rebalance p from upwards as needed


    // inserting L into G:
    // similarly, in this case, height(G) > height(L) + 1

        // in G, keep going left until we find a node p such that:
            // 1.) height(p) > height(L) + 1
            // 2.) height(p.right) <= height(L) + 1

        // create a new tree q with node k, left child L, and right child p.right. then set q to be p's right child.
        // rebalanced p from upwards as needed

    // let's understand, why does this result in a balanced tree?
    
    // lets look at an example for intuition:

    // suppose we have two AVL trees G and L

    // L:
    //          25
    //        /    \
    //      14      26

    // G:
    //               37
    //            /      \
    //          33        40
    //         /  \      /  \
    //       32   34    38   50
    //      /       \          \
    //     31       35          60
    //                \
    //                36

    // suppose our k value is 30. we want to insert L into G

    // we traverse G to find the node p = 33.
    // then we create the following node:

    //          30
    //        /     \
    //      25       32
    //     /  \      /  
    //   14    26  31 

    // then we set this to be the left child of p = 33.

    //                  37
    //              /       \
    //            33         40
    //           /   \      /  \
    //         30    34    38   50
    //        /   \    \          \
    //      25     32   36         60
    //     /  \    /
    //   14   26  31

    // we can see the above tree is balanced.
    // in general, there are 4 cases of joining AVL trees.
    // it will be easier to understand with a diagram, so run this code and see the output.pdf file in this directory

    // TODO: complete hand drawn diagrams for this and upload to the figures directory

    if (TEX_SUPPORT) {
        add_tex_output(
            "\n\n\\textbf{here are the 4 cases for joining AVL trees}\n\n"
            "\\includegraphics[width=0.5\\textwidth]{figures/avl_join1.png}\n"
            "\\includegraphics[width=0.5\\textwidth]{figures/avl_join2.png}\n"
            "\\includegraphics[width=0.5\\textwidth]{figures/avl_join3.png}\n"
            "\\includegraphics[width=0.5\\textwidth]{figures/avl_join4.png}\n"
        );
    }

    // we can use join() and split() as show above to implement union as follows:

    // union(T1, T2):
        // if T1 == nil
        //    return T2
        // if T2 == nil
        //    return T1

        // k = T2.key
        // (L, R) = split(T1, k) // split T1 at the root of T2
        
        // L' = union(L, T2.left)
        // R' = union(R, T2.right)

        // return join(L', k, R')

    return 0;
}

int weighted_balance_trees() {
    // another way to balance trees is to use a WEIGHTED BALANCE TREE (WBT).
    // before we were using AVLs, which balanced the tree based on the height of the tree

    // in a weighted balance tree, we balance the tree based on the number of nodes in the tree, i.e the size

    // idea: at every node n,
        // 1/3 <= [size(n.left) + 1] / [size(n.right) + 1] <= 3

        // =>
            // (1/3) * [size(n.right) + 1] <= size(n.left) + 1 <= 3 * [size(n.right) + 1]

        // i.e the size of the left subtree + 1 is between 1/3 and 3 times the size of the right subtree + 1

    // or we can simplify this by saying that weight(n) = size(n) + 1, hence:

        // 1/3 <= weight(n.left) / weight(n.right) <= 3

    // equivalently,
        // weight(n.left) <= 3 * weight(n.right)
        // weight(n.right) <= 3 * weight(n.left)

    // we can use this to balance the tree. just keep track of the size with a size field.

    // we will want to do rotations again, as with AVL trees!

    // ROTATIONS OF WBTs:

    // CASE 1: right heavy AND single CCW rotation works
        // i.e)
        // if weight(n.right) > 3 * weight(n.left) 
        // and weight(n.right.left) < 2 * weight(n.right.right)

        // why does that second condition allow a single rotation to work?
        // simple idea: the heavy node was the right node, so we check the weights of its children. the right node's left node is going to become the new right node of the parent node. want to make sure its size is not too big compared to the right node's right node.

        // we can mathematically show why this works:
            // let l = size(n.left), a = size(n.right.left), b = size(n.right.right).
            // since n is right heavy, either:
            // - a node was added to n.right to cause the imbalance
            // a node was removed from n.left to cause the imbalance

            // we have the following assumptions:
            // TODO: write up the mathematical derivation and add to the output.pdf file
 
        // CASE 2: left heavy AND single CW rotation works
            // same idea:
            // weight(n.left) > 3 * weight(n.right)
            // weight(n.left.right) < 2 * weight(n.left.left)

        // CASE 3: right heavy AND double rotation needed
            // in this case:
            // weight(n.right) > 3 * weight(n.left)
            // weight(n.right.left) >= 2 * weight(n.right.right)

            // must do:
            // R = n.right
            // rotate_right(R.left)
            // new_R = n.right
            // rotate_left(new_R)

        // CASE 4: left heavy AND double rotation needed
            // in this case:
            // same idea

    // so when we insert / delete, we would rebalance each node from the inserted / deleted node to the root. usually done recursively. same as AVL trees.
        
    return 0;
}

int union_of_WBTs() {
    // for the union of WBTs, we would need to change the join() function.

    // recall for AVLs, they join function:
        // join(G, k, L):

    // TODO: do the rest

    return 0;
}

int priority_queues() {
    // priority queues are collections of priority-job pairs; priorities must be comparable; i.e. have some order

    // they are ADTs with the following operations:
        // insert(job, priority)
        // max()
        // extract_max()

    // insert(j, p) inserts a job j with a given priority p
    // max() returns the job with the highest priority
    // extract_max removes the job with the highest priority from the priority queue and returns it

    // a heap is one way to store a priority queue
    // see the next section for heaps

    return 0;
}

int heaps() {
    // heaps are a data structure with O(1) time to find the highest priority element (min or max)
    // and O(log(n)) time to insert and delete elements

    // this makes them perfect for implementing priority queues and many other applications

    // a heap is:
        // a binary tree
        // "nearly complete": every level i has 2^i nodes, except the bottom level; the bottom nodes flush to the left
        // at each node n: priority(n) >= priority(n.left) and priority(n) >= priority(n.right). this is known as the heap priority

        // here is an example
        // note that each node is a priority which corresponds to a job

        //                     16
        //                  /      \
        //                14        10
        //              /    \      /  \
        //             8      7    9    3
        //            / \    / 
        //           2   4  1

        // notice how all the levels are complete except the last one, and the last one is filled from left to right

        // lets look at some insertion examples

        // insert 15 into the above heap

        //                     16
        //                  /      \
        //                14        10
        //              /    \      /  \
        //             8      7    9    3
        //            / \    / \
        //           2   4  1   15
        
        // note that the order of the priorities is now bad! need to swap with parent.
        // dont forget, we need parent >= left and parent >= right
        // this is called "bubble up", also known as float up or sift up. 

        //                     16
        //                  /      \
        //                14        10
        //              /    \      /  \
        //             8     15    9    3
        //            / \    / \
        //           2   4  1   7

        // note that the order is still bad, we see 15 > 14 but 15 is the right child of 14

        //                     16
        //                  /      \
        //                15        10
        //              /    \      /  \
        //             8     14    9    3
        //            / \    / \
        //           2   4  1   7

        // now the order is good!
        // we'll explore the algorithm for insertion in the section after the next one

        return 0;
}

int applications_of_heaps() {
    // heaps have many applications:
        // 1. heapsort
        // 2. priority queues
        // 3. dijkstra's algorithm
        // 4. huffman coding
        // 5. median maintenance
        // 6. job scheduling
        // 7. kth largest element
        // 8. finding the mode of a set of numbers
        // 9. finding the top k elements of a set of numbers
        // 10. finding the smallest k elements of a set of numbers

        // 11. graph algorithms: prim's and krushkal's algorithms for finding the minimum spanning tree

        // 12. stream processing: heaps are used in algos that deal with streaming data where u need to keep track of the top k elements in a dataset that is too large to fit in memory

        // 13. memory management: some implementations of memory allocation and garbage collection algorithms use heaps to keep track of memory blocks

    return 0;
}

int heap_insertion() {
    // let's go over the algorithm for inserting into a heap

    // insert(H, p, j):
        // v = create_node(p, j)

        // insert v at bottom level, leftmost free place (find smallest height favoring left)

        // while v has a parent p with priority(p) < priority(v): swap v and p
            // this is called "bubbling up" and ensures the heap property is maintained
    
    // worst case time is O(height)
    // note that height = floor(log(n)) + 1 (assuming we say a single node heap has height 1)

    return 0;
}


int heap_max_extract() {
    // for doing max_extract, we need to remove the root node and replace it with the last node in the heap, i.e the rightmost node in the bottom level

    // example

    //                     16
    //                  /      \
    //                15        10
    //              /    \      /  \
    //             8      14    9    3
    //            / \    / \
    //           2   4  1   7

    // after extracting the max, we replace 16 with 7

    //                     7
    //                  /      \
    //                15        10
    //              /    \      /  \
    //             8      14    9    3
    //            / \    /
    //           2   4  1

    // now we need to "bubble down" the new root node to maintain the heap property. also known as sift down or float down.

    // bubbling down:

    //                 15
    //              /      \
    //            7        10
    //          /    \      /  \
    //         8      14    9    3
    //        / \    /
    //       2   4  1

    // need to swap 7 and 14 now

    //                 15
    //              /      \
    //            14        10
    //          /    \      /  \
    //         8      7    9    3
    //        / \    /
    //       2   4  1

    // now the order is good

    // lets look at the algorithm to do this

    // max_extract(H):
        // max_p, max_j = priority(H), job(H)

        // move last node to root
        // v = root

        // while v has child c with priority(c) > priority(v):
            // c = child with highest priority
            // swap v and c
            // v = c

        // return max_p, max_j

    // worst case time for this is O(log(n))

    return 0;
}

int heaps_in_array() {
    // heaps can be implemented in an arrays instead of a tree

    // the array is an in-order traversal of the tree. for example, for the following heap tree:

    //                     16
    //                  /      \
    //                14        10
    //              /    \      /  \
    //             8      7    9    3
    //            / \    / 
    //           2   4  1

    // we have the array [16, 14, 10, 8, 7, 9, 3, 2, 4, 1]

    // where do we insert / remove ? simply at the ends of the array

    // where are children / parents? suppose the first index is index 0
        // left child of node at index i: index 2i + 1
        // right child of node at index i: index 2i + 2
        // parent of node at index i: index floor[ (i - 1) / 2 ]

    // pros:
        // no need for pointers
        // easy to implement
        // easy to store in memory

    // cons:
        // need to resize array when it gets full
        // need to shift elements when removing from the middle
        // not as easy to visualize as a tree
    return 0;
}

int heap_height() {
    // in this section we prove that the height of a heap is ceil(log(n)) + 1
    // note that we are considering a single node to have height 1

    // let h = height of the heap
    // let n = size of heap

    // largest n: when the bottom level is totally full
    // then,
    // n = 2^0 + 2^1 + 2^2 + ... + 2^(h-1)
    // geometric series sum formula: 2^0 + 2^1 + 2^2 + ... + 2^(h-1) = 2^h - 1

    // then, n = 2^h - 1

    // smallest n:
    // when there is only 1 node at the bottom level.
    // then,
    // n = [2^0 + 2^1 + 2^2 + ... + 2^(h-2)] + 1
    //   = [2^(h-1) - 1] + 1
    //   = 2^(h-1)

    // hence,
    // 2^(h-1) <= n <= 2^h - 1
    // 2^(h-1) <= n < 2^h
    // h-1 <= log(n) < h
    // h = <= log(n) + 1 < h + 1

    // hence, h = ceil(log(n)) + 1

    return 0;
}

int intro_to_graphs() {
    // a graph is a collection of nodes (vertices) and edges (connections between nodes)
    // graphs can be directed or undirected

    // before we go into the details of graphs, we will first go some examples of graphs and their applications

    // example usages of graphs:
        // cities and highways between them
        // computers and network cables between them
        // people and relationships
        // in a board game: a state and legal moves to other states

    // simply anything that can be modelled with nodes and edges.
    // remember, edges are connections between nodes, the PATHs, i.e. the LINES between the nodes

    // in a nutshell, we use graphs because they are a simple and powerful way to model relationships between objects
    // lets look at an example of a graph

    //         c     e
    //        / \
    //       a---b---d

    // note that this is not a tree, nodes can be connected in any way. the nodes can connect horizontally, vertically, or diagonally, it doesn't matter

    // definition of a graph
    // a GRAPH is a pair G = (V, E), where:
        // V is a set of vertices (nodes)
        // E is a set of edges (connections between nodes)

    // in the next function sections we will look at different kinds of graphs, such as undirected and directed graphs.
    // for now we will work with undirected graphs because they are simpler

    // UNDIRECTED GRAPH:
        // an undirected graph is a graph where the edges are bidirectional, i.e there is no direction to the edges and they can be considered to point in both directions

    // DIRECTED GRAPH:
        // a directed graph is a graph where the edges have a direction, i.e they point from one node to another

    // lets take a look at some graph terminology that applies in general to all graphs
    // GRAPH TERMINOLOGY:

    // 1. VERTEX: vertex is another word for node in the graph
    // 2. ENDPOINT: the nodes at the end of an edge are called the endpoints of the edge
    // 3. INCIDENT ON: we say an edge is incident on a vertex if the vertex is one of the endpoints of the edge
    // 4. DEGREE: the degree of a vertex is the number of edges incident on the vertex
    // 5. ADJACENT: two vertices are adjacent if there is an edge between them

    // example from aboves, 
        // edge {a, c} is incident on a and is also incident on c
        // b and d are endpoints of edge {b, d}
        // e is not an endpoint of any edge
        // edge {c, b} is not incident on a
        // vertices a and b are adjacent
        // the degree of a is 2 and the degree of b is 3


    // now lets explore WAYS OF STORING UNDIRECTED GRAPHS !! essentially: how can we implement a graph in code? these methods show how we can represent a graph in memory! they do not store the nodes of the graph, but rather the connections between the nodes, i.e how they are related
    
    // 1. ADJACENCY MATRIX: 
        // a 2D array where the rows and columns are the vertices, and the value at (i, j) is 1 if there is an edge between i and j, and 0 otherwise

        // note that the space complexity of the adjacency matrix is O(n^2), where n is the number of vertices

        // here is the adjacency matrix for the above graph:

        //     a  b  c  d  e
        //  a  0  1  1  0  0
        //  b  1  0  1  1  0
        //  c  1  1  0  0  0
        //  d  0  1  0  0  0
        //  e  0  0  0  0  0

        // operation times:
        // who are adjacent to vertex v? O(n)
            // go through the row for v and check for 1s
        // are v1 and v2 adjacent? O(1)
            // double index into the matrix, adj[v1][v2] == 1?

    // 2. ADJACENCY LIST:
        // a 1D array or dictionary where the key is the vertex and the value is a list of vertices that are adjacent to the key vertex

        // the space complexity of the adjacency list is O(n + m), where n is the number of vertices and m is the number of edges

        // here is the adjacency list for the above graph:

        // a: [b, c]
        // b: [a, c, d]
        // c: [a, b]
        // d: [b]
        // e: []

        // operation times:
        // who are adjacent to vertex v? O(degree(v))
            // just return the list of adjacent vertices
            // even though returning the list is O(1), we consider it O(degree(v)) because we consider iterating over the list. in that sense, this is the fastest time complexity of finding the adjacent vertices (O(1) to return, O(degree(v)) to iterate)
        // are v1 and v2 adjacent? O(degree(v1))
            // iterate over the list of adjacent vertices of v1 and check if v2 is in the list
        
        // this is much more optimal for graph searches

    // MORE (UNDIRECTED) GRAPH TERMINOLOGY:
        // 1. PATH: a PATH is a non-empty sequence of vertices in which:
            // consecutive vertices are adjacent
        // 2. SIMPLE PATH: a SIMPLE PATH is a path in which:
            // consecutive vertices are adjacent
            // AND vertices are distinct

            // for example, recall our graph:

            //         c     e
            //        / \
            //       a---b---d

            // - <d> is a path of length 0
            // - <d, b, c> is a path of length 2
            // - <d, b, c, b> is not a (simple) path because b is repeated
            // - <b, a, d> is not a path

        // 3. REACHABLE: we say a vertex v is reachable from vertex u if there is a path from u to v
            // e.g. a is reachable from c, b, d, but not e

        // 4. SIMPLE CYCLE: a SIMPLE CYCLE non-empty sequence of vertices in which:
            // consecutive vertices are adjacent
            // first vertex = last vertex
            // vertices are distinct except for the first=last
            // edges used are distinct
            // a single vertex is not a cycle

            // for example, consider the following graph:

            //       c       e
            //     /   \   /   \
            //    a------b------d

            //  <b, a, c, b> is a simple cycle, length 3. some books call it <b, a, c> instead

            // <b, c, a, b, d, e, b> is not a simple cycle because b is repeat// ed

            // <b, d, b> is not a simple cycle because the edge {b, d} is repeated

            // <a, b> is not a simple cycle because first != last

        // 5. CONNECTED
        // a graph is connected if between every to disinct vertices there is a path. remember, an edge is not a path. a graph that is not connected is said to be disconnected

        // e.g) 

        // following graph is connected

        //      c       e
        //    /   \       \
        //   a------b------d

        // following graph is disconnected

        //      c       e
        //    /   \       \
        //   a------b      d

        // 6. COMPONENT
        // a component is a maximal subset of vertices reachable from each other.

        // e.g)

        // following graph has 2 components

        //      c       e
        //    /   \       \
        //   a------b      d

        // components are: {a, b, c} and {d, e}

        // 7. TREE
        // a tree is a connected graph with no simple cycles

        // let E be the number of edges and V be the number of vertices
        // then equivalent definitions are:
            // between every two vertices there is a unique path
            // connected, but deleting any edge disconnects the graph
            // connected and |E| = |V| - 1, (1 less edge than vertices)
            // no cycles, but adding any edge creates a cycle
            // no cycles and |E| = |V| - 1

        // e.g)

        //      c       e
        //    /   \       \
        //   a     b ------d


        // 8. FOREST
        // a forest is a graph that is a collecion of trees

        // e.g)

        //      c       e ----- f
        //    /   \       \
        //   a     b      d

    return 0;
}

int breadth_first_search() {
    // breadth first search is a graph traversal algorithm that traverses the graph level by level, and has an order for visiting each level which leads to many patterns

    // the algorithm is as follows:
        // 1. visit the start vertex
        // 2. visit all the neighbors of the above
        // 3. visit all the neighbors of the above
        // ...

    // the algorithm uses a queue to keep track of the vertices to visit next

    // start := pick a start vertex
    // q := new queue
    // q.enqueue(start)
    // mark start as visited

    // while q is not empty:
        // u := q.dequeue()
        // for each neighbor v of u:
            // if v is not visited:
                // q.enqueue(v)
                // mark v as visited

    // BFS finds:
        // whether a vertex is reachable from start
        // if yes, the shortest path and distance
        // a tree constisting of reachable vertices and edges from start
        // the component containing start

    // BFS TIME COMPLEXITY:
        // we enqueue and dequeue each vertex once
            // only enqueue if not visited
        // we consider each edge twice
            // each edge is incident on 2 vertices
        // we find each vertex's list of neighbors once
        // check v's visited status deg(v) times
            // deg(v) is the degree of v, i.e the number of edges incident on v
        // hence the time complexity is O(|V| + |E|)

    return 0;
}

int depth_first_search() {
    // depth first search is a graph traversal algorithm that traverses the graph by going as deep as possible along each branch before backtracking

    // DFS leaves a trail of breadcrumbs as it goes, and backtracks when it reaches a dead end, i.e a vertex with no unvisited neighbors

    // example, consider the following graph where X is an unvisited vertex and O is a visited vertex, and Z is the vertex we are at

    // for this, it would be best to see diagrams online for yourself. it is very simple

    // DFS finds:
        // whether a vertex is reachable from start
        // a tree constisting of reachable vertices and edges from start
        // the component containing start
        // with a little modification, whether a cycle exists in the graph

    // DFS TIME COMPLEXITY:
        // also O(|V| + |E|), same as BFS

    // DETECTING CYCLES:
        // while searching, check if our current vertex has a neighbor that is visited and is not the predecessor
        // if true, then we have a cycle

    // FINISHING A VERTEX*
    // when doing DFS, we say that a vertex is finished when we have visited all its neighbors and backtracked to it

    return 0;
}

int directed_graphs() {
    // directed graphs are graphs where the edges have a direction, i.e they point from one node to another

    // the edges are represented as ordered pairs, i.e (u, v) is an edge from u to v. we don't have any bidirectional edges

    // e.g)

    //          c     e
    //         ^  \
    //        /    v 
    //       a<----b---->d
    //              <----

    // hard to type, but we have (b, d) and (d, b) as edges.

    // adjacency list:
        // a: [c]
        // b: [a, d]
        // c: [b]
        // d: [b]
        // e: []

    // note that c is adjacent to a, but a is not adjacent to c

    // we need new definition for degree:
        // in-degree of a vertex v: number of edges that point to v
        // out-degree of a vertex v: number of edges that point from v

    // also cycles and paths must now consider the direction of the edges

    // BFS and DFS are the same, but the resulting "subgraph" obtained will depends on our starting vertex even for connected graphs

    // only difference is that for DFS, when we are detecting cycles we check if our current vertex has a neighbor that is visited (which includes the predecessor)

    return 0;
}

int strongly_connected_components() {
    // only applies to directed graphs

    // strongly connected components are subsets of vertices in a directed graph where every vertex is reachable from every other vertex in the subset

    // e.g)

    //          c     e
    //         ^  \
    //        /    v
    //       a<----b---->d

    // then the strongly connected components are:
        // {a, b, c}
        // {d}
        // {e}

    // i.e for every vertex in a component, there is a path to every other vertex in the component

    // we briefly introduce tranposed graphs for directed graphs:
        // the tranpose of a graph G, denoted G^T, is the graph obtained by reversing the direction of all the edges in G

        // G^T has the same strongly connected components as G

        // the time to compute the adjacency list of G^T is O(|V| + |E|)

    // COMPUTING SCCs - KOSARAJU'S ALGORITHM:
        // 1. run DFS on G:
            // visit all vertices
            // store the order in which vertices finish* in a stack
        // 2. compute adjacency list of G^T to form G^T
        // 3. run DFS on G^T
            // use the stack from step 1 to determine the order of vertices to visit
            // each resulting completion of DFS is a strongly connected component

    // time complexity is O(|V| + |E|)
    return 0;
}

int  weighted_graphs() {
    // weighted graphs are graphs where the edges have a weight, i.e a number associated with them

    // the weight can represent the cost of traversing the edge, the distance between the nodes, etc

    // e.g)

    //          c     e
    //         ^  \
    //        /    v
    //       a<----b---->d

    // with weights:
    // a -> c: 2
    // c -> b: 6
    // b -> d: 1
    // b -> a: 3

    // weights indicate the cost of traversing the edge
    // the higher the weight, the more expensive it is to traverse the edge
    // you can think of the weight as the distance between the vertices

    return 0;
}

int dijkstras_algorithm() {
    // dijkstra's algorithm is a graph traversal algorithm that finds the shortest path from a start vertex to all other vertices in a graph

    // note that we can use dijkstra's algorithm on both directed and undirected graphs, weighted or unweighted

    // task: given a (edge-weighted) graph and two vertices, find the shortest path between the two vertices or report that no path exists

    // or even better: given an edge-weighted graph and a vertex s, find the shortest path from s to all other vertices. this is the most common use case

    // dijkstra's algo finds shortest paths by a BFS with a twist:
        // the BFS queue is replaced with a min-priority queue.
            // in case you forgot about the BFS queue: it is a queue that keeps track of the vertices to visit. each time you visit a vertex, you add its neighbors to the queue
        // with an additional operation: decrease_priority(vertex, new_priority). remember, since this is a min-priority queue, a decrease in priority means it will be visited sooner

    // we keep univisted vertices in a min-priority queue:
        // priority(v) = distance(start, v)
        // priority(v) = infinity if no path from s to v

    // we want to have a list of unvisited vertices, and also a table of priority and predecessors for each vertex 

    // at the start of the algorithm, the priority of the start vertex is 0 and the priority of all other vertices is infinity:

    // vertex_priority = {a: 0, b: inf, c: inf, d: inf, e: inf, f: inf, g: inf, h: inf, i: inf}
    // vertex_predecessor = {a: None, b: None, c: None, d: None, e: None, f: None, g: None, h: None, i: None}

    // consider the graph in the pdf output
    
    if (TEX_SUPPORT) {
        new_tex(
            "\\begin{center}\n"
            "\\includegraphics[width=0.5\\textwidth]{../figures/dijkstra.png}\n"
            "\\end{center}"
        );
    }

    // if we start at a, then the algorithm would go as follows:
        // begin at a
            // check a's neighbours b, h: update their priorities and predecessors: {b: 4, h: 8}, {b: a, h: a}
            // add b and h to the min priority queue
            // mark a as visited
        // pop b from the min priority queue
            // since b has a lower priority than h, we pop b
            // check b's unvisited neighbours and update their priorities and predecessors: {c: 12}
                // we don't update h because it's current priority is 8 and the new priority would be 4 + 11 = 15 from a -> b -> h. hence we don't change h's priority or predecessor

        // ... and so on until the min priority queue is empty

    // with the predecessor table, we can construct a tree with a at the root and the shortest paths to all other vertices. the tree is called the shortest path tree

    // let n = |V| and m = |E|. then the time complexity of dijkstra's algorithm is O((n + m)*log(n))
    // let's see why:
        // every VERTEX enters and leaves the min-heap once
            // recall that popping from a min-heap is O(log(n))
            // recall that inserting into a min-heap is O(log(n))
        // every EDGE may possibly need to call decrease_priority when we traverse the graph
            // this is O(log(n)) as well
        // the rest of the operations are O(1)

    // then the total worst case time complexity is O(nlogn) + O(mlogn) = O(nlogn + mlogn) = O((n + m)logn)
    printf("end!\n");

    return 0;
}

int amortized_analysis() {
    // amortized analysis is a method of analyzing the time complexity of an algorithm over a sequence of operations

    // we begin studying how to calculate the total time of a sequence of operations as a whole
    // before we would calculate the sub of the worst case times of each individal operation separately

    // for example, consider multi-pop stack operations:
        // push(x): O(1)
        // pop(): O(1)

        // if we do n pops, the total time is O(n),
        // multipop(k): O(k)

    // now consider what happens if we start with an empty stack and perform n operations (can be any operations: push, pop, or multipop).

    // a naive analysis may suggest in the worst case we have O(n^2) time complexity if we call multipop(n) n times

    // however, obviously this cannot be the case because in order for multipop to be O(n), the stack must grow to size n, and this will take a lot of push() calls, which are O(1). so multipop will rarely be called and most of our operations will be O(1), hence the total time complexity must be O(n). if multipop is called a lot, then the stack will not be given a chance to grow to size n, and the total time complexity will not be O(n) for multipop.

    // you might be thinking, well that's pretty obvious, what's the point? i thought this too, but this is a good example to illustrate the concept of amortized analysis as you will see. we are essentially taking a more in-depth look at the analyzing worst case time complexity.

    // idea:
        // if n operations take O(n) total time in the worst case
        // then the amortized time per operation is O(1)

    // in general:
        // if n operaitons take O(f(n)) total time in the worst case
        // then the amortized time per operation is O(f(n) / n)

    // AMORTISATION METHOD #0: AGGREGATE
    // aggegating is what we just considered with multi pop stacks
    // make an observation / argument about overall number of steps in n operations
    // usually examine how different operations depend on each other

    // AMORTISATION METHOD #1: ACCOUNTING
    // let's consider our multi-pop stack example from earlier.
    // say each operation receives 2 dollars
    // say push and pop spend 1 dollar
    // multipop(k) spends the number of items actually popped: min(k, size) dollars
    // if we have money left over after the operation, we save it for the future
    // else if we dont have enough for the operation: spend from savings

    // the idea is that we are analyzing the overall cost of the operations by accounting our cost and giving an allowance of sorts

    // this only works if we have enough to pay everything in the end
    // must prove the invariant: amount >= 0
    //  conclude that each operation takes O(2) amortised time


    return 0;
}