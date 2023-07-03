//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Node{
  public:
    int data;
    Node *left, *right;
    Node(int d) {
        data = d;
        left = NULL, right = NULL;
    }
};
class cmp{
    public:
    bool operator()(Node *a, Node *b) {
        return a->data > b->data;
    }
};
class Solution
{
	public:
	    void dfs(Node *root, vector<string> &res, string temp) {
	        if (not root) return;
	        if (not root->left and not root->right) res.push_back(temp);
	        dfs(root->left, res, temp+'0');
	        dfs(root->right, res, temp+'1');
	    }
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    for (int i=0; i<N; i++) pq.push(new Node(f[i]));
		    while (pq.size() > 1) {
		        Node* x = pq.top(); pq.pop();
		        Node* y = pq.top(); pq.pop();
		        Node *root = new Node(x->data + y->data);
		        root->left = x, root->right = y;
		        pq.push(root);
		    }
		    vector<string> res;
		    Node *root = pq.top();
		    dfs(root, res, "");
		    return res;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends