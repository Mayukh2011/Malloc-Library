//function to create new node
Node* create_new_node(int size,int address)
{

  Node * newNode=sbrk(sizeof(Node));




  newNode->size=size;
  newNode->free_flag=0;
  newNode->startAddr=address;

  if(head==NULL)
  {
    head=newNode;

  }
  else
  {

    Node *last=head;
  while(last->next!=NULL)
  {

    last=last->next;
  }

    last->next=newNode;
  }

  newNode->next=NULL;

  return newNode;
}

// function to dive the node repeatedly by 2 to get the appropriate memory size.
void divide_node(Node * dividing_node)
{

  int size_of_orignal=dividing_node->size;
  dividing_node->size=(size_of_orignal)/2;
  Node *div_node=sbrk(sizeof(Node));
  div_node->size=(size_of_orignal)/2;
  div_node->free_flag=0;
  div_node->startAddr=dividing_node->startAddr+div_node->size;
  div_node->next=dividing_node->next;
  dividing_node->next=div_node;

}

// function to  merge nodes if they are buddies
void merge_buddy_node()
{

   Node * lowBud=head;
   Node * highBud=lowBud->next;

   while(highBud!=NULL)
   {
      if(findBuddies(lowBud,highBud)==0)
      {

        if(lowBud->free_flag==0&&highBud->free_flag==0)
        {

          Node *mergeBuds=lowBud;

          mergeBuds->size=lowBud->size+highBud->size;
          mergeBuds->memory_size=0;
          mergeBuds->free_flag=0;
          mergeBuds->next=highBud->next;

          lowBud=head;
          highBud=lowBud->next;
          continue;

        }
      }
      lowBud=lowBud->next;
      highBud=highBud->next;
   }



}

// function to find an appropriate place for the size requested to go.
Node * search_where_to_put(size_t memsize)
{
    Node *temp=head;

    while(temp!=NULL)
    {
            if(temp->size>=memsize&&temp->free_flag==0)
      {

        return temp;
      }
      temp=temp->next;

    }
    return NULL;


}
// functionto find buddies
int findBuddies(Node * LowBuddy,Node * HighBuddy)
{
    int buddies=1;
    long long lowerBudAddr=LowBuddy->startAddr;



  if((LowBuddy->size==HighBuddy->size)&&(lowerBudAddr%(LowBuddy->size*2)==0)&&((LowBuddy->startAddr+LowBuddy->size)==HighBuddy->startAddr))
  {
    buddies=0;
  }

    return buddies;
}

// to check if a number is divisible by 2
int isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
      if (n%2 != 0)
         return 0;
      n = n/2;
  }
  return 1;
}
// function to ask Kernel for space.
Node  * call_for_space(int multiple)
{


    void * strAddr=sbrk(multiple*getpagesize());
    if(strAddr==-1)
   {
     errno=ENOMEM;
     return NULL;
   }
    Node * mainNode=create_new_node(multiple*getpagesize(),strAddr);

    return mainNode;

}
// function to find celing of a number
int ceil(float num) {

    int inum = num;
    if (num == (float)inum) {
        return inum;
    }
    return inum + 1;
}
