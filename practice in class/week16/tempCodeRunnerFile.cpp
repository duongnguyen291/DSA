node *deleteNode1(node *r, int x){
// //có thể dùng predecessor hoặc successor để thay trong case 3
//     if(r == NULL) return NULL;
//     if(x < r->data) r->left = deleteNode(r->left,x);
//     else if(x > r->data) r->right = deleteNode(r->right,x);
//     else{
//         if(r->left == NULL && r->right == NULL){
//             delete r;
//             return NULL;
//         }
//         else if(r->left == NULL || r->right == NULL){
//             node *temp = r->left;
//             if(temp == NULL) temp = r->right;
//             delete r;
//             return temp;
//         }
//         else{
//             node *temp = findMax(r->left);
//             r->data = temp->data;
//             r->left = deleteNode(r->left,temp->data);
//         }
//     }
//     return r;
// }