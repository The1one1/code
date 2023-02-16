// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> leftView(struct Node *root);

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        vector<int> vec = leftView(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// Function to return a list containing elements of left view of the binary tree.

vector<int> fun(Node *root)
{
    vector<vector<int>> v(101);

    unordered_map<Node *, int> level;
    level[root] = 1;

    v[1].push_back(root->data);
    queue<Node *> q;
    q.push(root);

    while (not q.empty())
    {
        auto child = q.front();
        q.pop();

        if (child->left != NULL)
        {
            level[child->left] = level[child] + 1;
            q.push(child->left);
            v[level[child->left]].push_back(child->left->data);
        }
        if (child->right != NULL)
        {
            q.push(child->right);
            level[child->right] = level[child] + 1;
            v[level[child->left]].push_back(child->right->data);
        }
    }

    vector<int> k;
    for (auto i = 1; i < v.size(); i++)
    {
        if (v[i].size() != 0)
            k.push_back(*v[i].begin());
        else
            return k;
    }
    return k;
}

vector<int> leftView(Node *root)
{
    return fun(root);
}