

void *realloc(void *ptr, size_t size)
{

// if size is 0 then return Null. and free the pointer
  if(size==0)
  {
    free(ptr);
    return NULL;
  }
  else{


      pthread_mutex_lock(&mutex);
            Node * go_to_the_address=head;
              // search for the address passed in the list
            while(go_to_the_address!=NULL)
            {
              if(go_to_the_address->startAddr==ptr)
              {
                break;
              }
               go_to_the_address=go_to_the_address->next;
            }
            pthread_mutex_unlock(&mutex);


            void *Addr;
              // if address is not found the malloc the size
              if (!go_to_the_address) {

                  Addr = malloc(size);
              }
              else {
                    // if size asked for is greater than the original size then reserve the space using malloc and then copy the original content.
                  if (go_to_the_address->size < size) {

                      Addr = malloc(size);

                      Addr = memcpy(Addr, ptr, go_to_the_address->size );
                      // once allocated the free the original address.
                      free(ptr);
                  }
                  else {
                    // else point to the original address.
                      Addr = ptr;
                  }
              }

              return Addr;
      }




}
