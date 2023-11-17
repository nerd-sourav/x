pair<Node *, Node *> helper(Node * cur) {
        if(cur == nullptr)
            return {nullptr, nullptr};
            
        pair<Node *, Node *> leftres = helper(cur -> left);
        pair<Node *, Node *> rightres = helper(cur -> right);
        
        cur -> left = leftres.second;
        cur -> right = rightres.first;
        
        if(leftres.second)
            leftres.second -> right = cur;
        if(rightres.first)
            rightres.first -> left = cur;
        
        return {(leftres.first ? leftres.first : cur), (rightres.second ? rightres.second : cur)};
    }
    
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if(root == nullptr)
            return nullptr;
        
        pair<Node *, Node *> res = helper(root);
        
        res.first -> left = res.second;
        res.second -> right = res.first;
            
        return res.first;
    }
