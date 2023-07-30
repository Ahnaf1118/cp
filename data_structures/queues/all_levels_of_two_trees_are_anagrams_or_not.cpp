//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool match(map<int, int> &a, map<int, int> &b) {
        for (auto pr: a) {
            if (b[pr.first] != pr.second) return false;
        }
        return true;
    }
    bool areAnagrams(Node *root1, Node *root2)
    {
        queue<pair<Node*, int>> p, q;
        p.push({root1, 0}), q.push({root2, 0});
        map<int, int> a, b;
        a[root1->data]++, b[root2->data]++;
        int level = -1;
        while (not p.empty() and not q.empty()) {
            auto pr = p.front(); p.pop();
            auto qr = q.front(); q.pop();
            int cur_level = pr.second;
            if (cur_level > level) {
                level = cur_level;
                if (not match(a, b)) return false;
                else a.clear(), b.clear();
            }
            if (pr.first->left) p.push({pr.first->left, pr.second+1}), a[pr.first->left->data]++;
            if (pr.first->right) p.push({pr.first->right, pr.second+1}), a[pr.first->right->data]++;
            if (qr.first->left) q.push({qr.first->left, qr.second+1}), b[qr.first->left->data]++;
            if (qr.first->right) q.push({qr.first->right, qr.second+1}), b[qr.first->right->data]++;
        }
        return true;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/
int main() {
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        Node *root1 = buildTree(treeString1);
        getline(cin, treeString2);
        Node *root2 = buildTree(treeString2);
        Solution ob;
        cout << ob.areAnagrams(root1, root2) << endl;
    }
    return 0;
}

// } Driver Code Ends