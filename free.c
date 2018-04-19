
void free(void *ptr)
{

   //if pointer is null then return.
   if(ptr==NULL)
   {

      return;
   }
   else{


        pthread_mutex_lock(&mutex);
            // go to the node with the same address as that odf the argument.
             Node * go_to_the_address=head;
             while(go_to_the_address!=NULL)
             {
               if(go_to_the_address->startAddr==ptr)
               {
                 break;
               }
                go_to_the_address=go_to_the_address->next;
             }
                //if the address is not found in the list or is already freed then  return.
                if(!go_to_the_address||go_to_the_address->free_flag==0)
                {

                  pthread_mutex_unlock(&mutex);
                  return;

                }
              // update the list and merge the buddies.
             go_to_the_address->memory_size=0;
             go_to_the_address->free_flag=0;
             merge_buddy_node();

              pthread_mutex_unlock(&mutex);

      }


}
