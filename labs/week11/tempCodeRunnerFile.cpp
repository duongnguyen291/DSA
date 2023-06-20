int CountKChildren(node *head, int k, int result){
//     if(head == NULL) return 0;
//     int cnt = 0;
//     node *p = head->rightSibling;
//     for(node cur = p; cur != NULL;cur = cur->rightSibling){
//         cnt++;
//     }
//     if(cnt == k) 
//         result++;
//     while(p != NULL){
//         result = CountKChildren(p,k,result);
//         p = p->rightSibling;
//     }
//     return result;
// }