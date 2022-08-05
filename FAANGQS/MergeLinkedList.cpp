TreeNode<int> mergeLinkedList(TreeNode<int> * head1,TreeNode<int> *head2){
    TreeNode<int> *head=NULL;
    TreeNode<int> *Tail=NULL;
    
    while(head1!=NUll&&head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->left;
                
                
                
            }
            
        }
        else{
            if(head==NULL){
                   head=head2;
                tail=head2;
                head1=head2->right;
                
            }
            else{
                 tail->right=head2;
                head1->left=tail;
                tail=head2;
                head1=head2->left;
                
                
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
     while(head2!=NULL){
        tail->right=head1;
        head2->left=tail;
        tail=head1;
        head2=head1->right;
    }
}