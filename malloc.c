

void * malloc(size_t size)
{

pthread_mutex_lock(&mutex);
//if size is 0 then return null
    if(size==0)
    {
      pthread_mutex_unlock(&mutex);
      return NULL;
    }



 int multiple;

// this piece of code returns the multiple of page size to be requested.
multiple = ceil(size/(float)getpagesize());

  Node *node;
  Node *pointer;

// if head is null the make call to the kernel for space.
    if(head==NULL)
    {

      node=call_for_space(multiple);
      pointer=head;
      //divide the memory until the appropriate size is achieved.
       while(size<node->size&& node->size>8)
       {
         if((node->size/2)<size)
         break;
          divide_node(node);
       }

      // once we get the appropriate chunk then populate the information regarding the allocation.
       pointer->free_flag=1;
       pointer->memory_size=size;

     }

    else{
        // serach the entire list for appropriate place to insert the requested memory.
        pointer=search_where_to_put(size);

        if(pointer!=NULL){

                    // once  we get an memory chunk to place the requested size, divide it, if possible to get an exact fit.
                    while(1){
                      if((pointer->size)/2>=size&&(pointer->size)>8)
                      {
                      	divide_node(pointer);
                        continue;
                      }
                      break;
                    }
                    // update the list, regarding the memory chunk.
                      pointer->memory_size=size;
                      pointer->free_flag=1;


      }
      else{

                Node *newMemorycallNode;

                Node *Last;

                 Last=head;

                 //if the size requested is too big then call for more space from the kernel and add that to the list.
                  while(Last->next!=NULL)
                  {

                    Last=Last->next;
                  }

                  newMemorycallNode=call_for_space(multiple);
                  Last->next=newMemorycallNode;

                  pointer=search_where_to_put(size);

                while(1){
                  if((pointer->size)/2>=size)
                  {
                    divide_node(pointer);
                    continue;
                  }
                  break;
                }
                  // update the list, regarding the memory chunk.
                  pointer->memory_size=size;
                  pointer->free_flag=1;




      }

  }

pthread_mutex_unlock(&mutex);
  return pointer->startAddr;

}
